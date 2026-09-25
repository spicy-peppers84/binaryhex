#include "../include/printbase.h"
#include "../include/display.h"
#include <inttypes.h>
#include <stdio.h>

/**
 * This function prints the number in its base 10 form. It uses the macro
 * PRIu64 to display 64-bit numbers
 */
void printBase10(uint64_t number)
{
    printf("BASE-10: %" PRIu64 "\n", number);
}

/**
 * This function prints the numeber in its base 2 form. It reads the bits
 * starting from the left by shifting bits to the right to print either
 * 1 or 0. It adds space whenever a full byte is written and 1 is
 * highlighted in red
 */
void printBase2(uint64_t number, int bitlen)
{
    int bitsWritten = 0;

    printf("BASE-2:  ");
    for (int i = bitlen - 1; i >= 0; i--) {
        // Shift bits i to the right and check if it equals 1
        ((number >> i) & 1) ?
        FG_ANSI(9, "1") : printf("0");

        // Add a space when a full byte is written
        if (++bitsWritten == 8) {
            bitsWritten = 0;
            printf(" ");
        }
    }
    printf("\n");
}

/**
 * This functions prints the number in its base 16 form. It uses a bitmask to
 * read the amount of bits specified by bitlen. The number is then printed as
 * a hexadecimal using conversion specifiers in the print functions
 */
void printBase16(uint64_t number, int bitlen)
{
    printf("BASE-16: 0x");
    switch (bitlen) {
        case BITLEN_8:
            number &= (0xFF); // states how many bytes to keep
            printf("%02X", number); // states how many digits to display
            break;

        case BITLEN_16:
            number &= (0xFFFF);
            printf("%04X", number);
            break;

        case BITLEN_32:
            number &= (0xFFFFFFFF);
            printf("%08X", number);
            break;

        case BITLEN_64:
            printf("%016" PRIX64, number);
            break;
    };
    printf("\n");
}
