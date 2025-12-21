/* LEXER
================ */
char ** lex_capture (char *fmt, char *stream);
uint lex_wsp        (char *stream);
uint lex_newline    (char *stream);
uint lex_int        (char *stream);
uint lex_uint       (char *stream);
uint lex_float      (char *stream);
uint lex_hex        (char *stream); 
uint lex_byte       (char *stream);
uint lex_string     (char *stream);
uint lex_word       (char *stream);

/*
CAPTURE FUNCTION
================
    Returns either NULL on failure,
    or a list of pointers to captured tokens
    with a pointer to the end of the captured stream first

    %% = actual percentage symbol
    %c = capture any one character
    %w = capture any non-EOL whitespace
    %n = capture an EOL with or without return carriage
    %i = capture an integer (with or without sign)
    %u = capture an integer (unsigned only)
    %f = capture a float
    %b = capture a char or byte (i.e, 'W' with quotes, 0xFF, 128, et al)
    %s = capture a string (i.e., anything between quotes)
    %* = capture a label/word

HELPER FUNCTIONS
================
    Return either 0 on failure or the length of the captured type */

#define lex_yield_size 64
static char *lex_yield[lex_yield_size];

char ** lex_capture(char *fmt, char *stream){
    int yields = 0; int f; int s;
    char *fmtstart = fmt;
    char *streamstart = stream;

    while(*stream && *fmt) {
        if ( *fmt == '%' ) {
            int len=0; fmt++;
            switch(*fmt) {
                default: print("Lexer, Internal Error: invalid format specifier\n"); exit(-1);
                case '%': len = ( *stream == '%'); break;
                case 'c': len = ( *stream != 0 ); break;
                case 'w': len = lex_wsp(stream); break;
                case 'n': len = lex_newline(stream); break;
                case 'i': len = lex_int(stream); break;
                case 'u': len = lex_uint(stream); break;
                case 'f': len = lex_float(stream); break;
                case 'b': len = lex_byte(stream); break;
                case 's': len = lex_string(stream); break;
                case '*': len = lex_word(stream); break;
            }
            if (len > 0) {
                yields++; lex_yield[yields] = stream; 
                stream+=len; fmt++;
            } else { return NULL; }
            continue;
        }
        else if ( *fmt != *stream ) { return NULL; }
        stream++; fmt++;
    }

    if ( stream == streamstart ) { return NULL; }
    lex_yield[0] = stream;
    lex_yield[yields+1] = NULL;
    return lex_yield;
}

uint lex_wsp (char *stream) {
    char * start = stream;
    int i=0; while(*stream) { i = stream - start;
        switch(*stream) { default: return i; case '\r': case '\t': case ' ': stream++; continue; }
    }   i = stream - start; return i;
}

uint lex_newline (char *stream) {
    char * start = stream;
    int i=0; while(*stream) { i = stream - start;
        switch(*stream) { default: return i; case '\r': case '\n': stream++; continue; }
    }   i = stream - start; return i;
}

uint lex_int(char *stream) {
    char * start = stream;
    int i=0; while(*stream) { i = stream - start;
        if (*stream >= '0' && *stream <= '9') { stream++; continue; }
        if (*stream == '+' && i == 0) { stream++; continue; }
        if (*stream == '-' && i == 0) { stream++; continue; }
        break;
    }   i = stream - start; return i;
}

uint lex_uint(char *stream) {
    char * start = stream;
    int i=0; while(*stream) { i = stream - start;
        if (*stream >= '0' && *stream <= '9') { stream++; continue; }
        break;
    }   i = stream - start; return i;
}

uint lex_float (char *stream) {
    char * start = stream;
    int i=0; int dot=0; while(*stream) { i = stream - start;
        if (*stream >= '0' && *stream <= '9') { if (dot > 0){dot++;} stream++; continue; }
        if (*stream == '+' && i == 0) { stream++; continue; }
        if (*stream == '-' && i == 0) { stream++; continue; }
        if (*stream == '.' && dot == false) { dot=true; stream++; continue; }
        if (*stream == 'f' && dot > 1) { stream++; break; } // i.e the 'f' in "1.0f"
        break;
    }   i = stream - start;
    if ( i > 0 && start[i-1]=='.') { return 0; } return i;
}

uint lex_hex (char *stream) {
    char * start = stream;
    int i=0; int f=-1; while(*stream) { i = stream - start; 
        if (*stream >= '0' && *stream <= '9' ) { stream++; continue; }
        if (*stream >= 'A' && *stream <= 'F' ) { stream++; continue; }
        if (*stream >= 'a' && *stream <= 'a' ) { stream++; continue; }
        if (*stream == 'x' && i == 1 && *(stream-1) == '0') { stream++; continue; }
    }   i = stream - start; return i;
}

uint lex_byte (char *stream) {
    int i = lex_hex(stream); if ( i > 0 ) { return i; } i=0;
    char * start = stream; char env;
    while(*stream) { i = stream - start; 
        if (i == 0) { env=*stream; stream++; if ( env == '\'' || env == '"' || env == '`' ) { continue; } else { return 0; } }
        if (i == 1) { if ( *stream == env ) { return 0; } stream++; continue; }
        if (i == 2) { if ( *stream != env ) { return 0; } stream++; continue; }
    }   i = stream - start; return i;
}

uint lex_string (char *stream) {
    char * start = stream; bool escape = false;
    char env; int i=0; while(*stream) { i = stream - start; 
        if (i==0) { if (*stream == '\'' || *stream == '"' || *stream == '`') { env=*stream; stream++; continue; } return 0; }
        if (i!=0 && *stream == env && escape == false) { i = stream - start; return i; }
        if (*stream == '\\') { stream++; escape = !escape; }
        else if (escape == true) { escape = false; }
        stream++;
    }   return 0;
}

uint lex_word (char *stream) {
    char * start = stream;
    int i=0; while(*stream) { i = stream - start;
        if (*stream <= 'z' && *stream >= 'a') { stream++; continue; }
        if (*stream <= 'Z' && *stream >= 'A') { stream++; continue; }
        if (*stream == '_' ) { stream++; continue; }
        break;
    }   i = stream - start; return i;
}