/* LIBS
================ */
#define uint u32
#include <core.h>
#include <lib.h>
#define RED                     "\e[0;31m"
#define YELLOW                  "\e[0;33m"
#define GREEN                   "\e[0;32m"
#define WHITE                   "\e[0m"

/* FRONTEND
================ */
#include "lex.c"
#include "cli.c"
#include "asm.c"
#include "cmp.c"

int main (int argc, char **argv) {

    char ** yield = lex_capture(
        "%f x",
        "10.0 x"
    );
    if ( yield == NULL ) { print("FAIL\n"); }
    else { printf(">> %s\n", yield[1]); }
    exit(0);

}