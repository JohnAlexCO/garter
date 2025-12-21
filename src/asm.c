/* ASSEMBLER
================ */
uint assembler                  (char *output, char *input);

/*
ASSEMBLER FUNCTION
================
    Given an input character stream, invokes the tokenizer,
    parser, and processes it into raw data sections ready for output,
    then invokes the system write and returns */

void asm_error                  (char *message);
char * asm_tokenizer            (char *input);
uint asm_pusher                 (char opcode, uint base, uint adder);
uint asm_emitter                ();
u32 asm_hashname                (char *stream);

/*
HELPER FUNCTIONS
================
    Error: return ignored
        prints source and error message, terminates process

    Tokenizer: returns pointer to next token
        iterates the input one line at a time, 
        invokes symbol tracking and push functions
        updates section tracker

    Pusher: returns output size
        given an operation type and arguments,
        pushes encoded instructions and data into the sections

    Emitter: return ignored
        using accumulated program metadata
        writes the header and section data to output */

#define UOVERF 0xFF
#define UMAX 0xFFFF - UOVERF // make space so addressing for both can still fit a u16
enum {
    NIL,
    READABLE, WRITABLE, EXECUTABLE,
    EXTERNAL, LITERAL,
    UNDEFINED = -1
};

#define ASM_SECTION_COUNT 8
#define ASM_SECTION_DSIZE ( 1024 * 1024 * 4 )

typedef struct { u8 section; uint symbol; uint offset; } reference_t;
typedef struct { u8 section; u64 data; u32 name; } symbol_t;
typedef struct { symbol_t symbols[UMAX+1]; symbol_t overflow[UOVERF+1]; u8 over; } table_t;
typedef struct { char type; uint used; char strname[16]; char data[ASM_SECTION_DSIZE]; } section_t;

uint asm_y=0; uint asm_x=0;
section_t *asm_section=NULL; uint asm_sections = 0;
section_t sections[ASM_SECTION_COUNT] = { UNDEFINED };
table_t symbol_table =          { UNDEFINED };

symbol_t * symbol_get           (u32 name);
symbol_t * symbol_touch         (u32 name);
symbol_t * symbol_set           (u32 name, u8 section, u64 data);

section_t * section_get         (char *name);
section_t * section_set         (char *name);
section_t * section_new         (char *name, char type);

void asm_error (char *message) {
    printf(RED "ERROR, Assembler [%d:%d] " WHITE "%s\n", &asm_y, &asm_x, message); exit(-1); }
void asm_warn (char *message) {
    printf(YELLOW "WARNING, Assembler [%d:%d]" WHITE " %s\n", &asm_y, &asm_x, message); }

u32 hashname (char *stream) {
    uint a=0; uint b=0; uint c=0; uint sum=0;
    char *start = stream; while(*stream) {
        unsigned char ref = *stream - 32;
        a += ref % 9; b += ref % 7; c += ref % 11;
        sum += ref; stream++;
    }
    return (
        (a << 24) |
        (b << 16) |
        (c << 8)  |
        sum + (stream - start)
    );
}

symbol_t * symbol_get (u32 name) {
    symbol_t * this = &symbol_table.symbols[name % UMAX];
    if ( this->section == UNDEFINED ) { return NULL; } // No symbol defined
    else if ( this->name != name ) { // symbol collision
        int i; for(i=0;i<UOVERF && i<symbol_table.over;i++) {
            this = &symbol_table.overflow[i];
            if ( this->name == name ) { return this; }
        }   return NULL;
    }
    else { return this; }
}

symbol_t * symbol_touch (u32 name) {
    // Redefinition
    symbol_t * this = symbol_get(name); if ( this ) {
        if ( this->section <= EXTERNAL ) { this->section = EXTERNAL; return this; }
        asm_error("Symbol redefinition");
    }   // this = NULL;
    
    // Original definition
    uint offset = name % UMAX;
    this = &symbol_table.symbols[offset];

    if ( this->section != UNDEFINED ) { // symbol collision
        printf("ASM `symbol_touch`, collision between %x and %x\n", &this->name, &name);
        int i; for(i=0;i<UOVERF && i<symbol_table.over;i++) {
            this = &symbol_table.overflow[i];
            if ( this->name != name ) { break; }
        }   if (i >= UOVERF-1) { asm_error("Failure to assign name to unique symbol"); }
    }

    // Fallthrough, `this` has been assigned to free space or errored
    this->name = name;
    this->section = EXTERNAL;
    return this;
}

symbol_t * symbol_set (u32 name, u8 section, u64 data) {
    symbol_t * this = symbol_touch(name); if (!this) { asm_error("Failure to touch symbol before set"); }
    this->section = section;
    this->data = data;
    return this;
}

section_t * section_get (char *name) {
    int cmp; int i;
    for(i=0;i<ASM_SECTION_COUNT && i<asm_sections;i++) {
        section_t * ref = &sections[i];
        cmp = strcmp(name, ref->strname, 15);
        if ( cmp == 0 ) { return ref; }
    }   return NULL;
}

section_t * section_set (char *name) {
    section_t * ref = section_get(name);
    if ( ref ) { asm_section = ref; return ref; }
    return NULL;
}

section_t * section_new (char *name, char type) {
    section_t * ref = section_set(name);
    if ( ref ) { 
        if ( ref->type != type ) { asm_error("Section redefined with conflicting type"); }
        asm_warn("Section redefinition"); return ref;
    }
    if ( asm_sections >= ASM_SECTION_COUNT ) { asm_error("Exceeded maximum number of program sections"); }
    ref = &sections[asm_sections];
    ref->type = type;
    asm_sections++;
    return ref;
}

char * asm_tokenizer            (char *input) {

    char opcode; uint base; uint adder;

    /*
        section <name> <permissions>
        move <register> <register>
        load/store <register> <address>
        immediate <register> <value>
        <binop> <register> <register>
        <unop> <register>
        <jumper> <register>
        <jump> <address>
    */

}

uint asm_pusher                 (char opcode, uint base, uint adder);
uint asm_emitter                ();

uint assembler                  (char *output, char *input);