#include "../include/display.h"
#include "../include/printbase.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t number;
int bitlen;

void mainloop(void);
void changenum(void);
void changebitlen(void);

/**
 * number and bitlen are configured at the start
 */
int main(void)
{
    number = 0;
    bitlen = BITLEN_8;
    
    mainloop();
    return 0;
}

/**
 * This is the main loop that acts as the heart of the program
 */
void mainloop(void)
{
    for (;;) {
        SET_BUFFER;
        CLEAR_CONSOLE;

        switch (bitlen) {
            case BITLEN_8:  FG_ANSI(9, "[8-bit mode]\n\n"); break;
            case BITLEN_16: FG_ANSI(9, "[16-bit mode]\n\n"); break;
            case BITLEN_32: FG_ANSI(9, "[32-bit mode]\n\n"); break;
            case BITLEN_64: FG_ANSI(9, "[64-bit mode]\n\n"); break;
        };

        printBase10(number);
        printBase2(number, bitlen);
        printBase16(number, bitlen);
        printf("\n");
        
        MENU_OPTION(1, "CHANGE NUMBER");
        MENU_OPTION(2, "CHANGE BIT LENGTH");
        MENU_OPTION(3, "END PROGRAM");
        FLUSH;

        switch (getchar()) {
            case '1': changenum(); break;
            case '2': changebitlen(); break;
            case '3': exit(EXIT_SUCCESS);
        };
    }
}

/**
 * This function asks the user to input a new number
 */
void changenum(void)
{
    SET_BUFFER;
    CLEAR_CONSOLE;
    FG_ANSI(9, "Enter new number: ");
    FLUSH;
    scanf("%" SCNu64, &number);
}

/**
 * This functions puts the user in a loop that asks them to choose
 * a new mode for bit-length
 */
void changebitlen(void)
{
    for (;;) {
        SET_BUFFER;
        CLEAR_CONSOLE;
        FG_ANSI(9, "[Enter new bit-length]\n\n");

        MENU_OPTION(1, "8-BITS");
        MENU_OPTION(2, "16-BITS");
        MENU_OPTION(3, "32-BITS");
        MENU_OPTION(4, "64-BITS");
        FLUSH;

        switch (getchar()) {
            case '1': bitlen = BITLEN_8; return;
            case '2': bitlen = BITLEN_16; return;
            case '3': bitlen = BITLEN_32; return;
            case '4': bitlen = BITLEN_64; return;
        };
    }
}
