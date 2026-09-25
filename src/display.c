#include "../include/display.h"
#include <stdio.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/ioctl.h>
#endif

bool invalidIndex(int n);
int getConsoleRows(void);
int getConsoleCols(void);

/**
 * This function sets the memory size of stdout and configures the buffer to
 * output when it is flushed or when the buffer is full
 */
void setbuffer(void)
{
    setvbuf(stdout, NULL, _IOFBF, getConsoleRows() * getConsoleCols());
}

/**
 * This functions flushes stdout
 */
void flush(void)
{
    fflush(stdout);
}

/**
 * This function colors a string based on the color represented by the index argument.
 * Returns false if the index is invalid
 */
bool fgAnsi(int index, char* str)
{
    if (invalidIndex(index)) {
        return false;
    }

    printf("\033[38;5;%dm%s\033[0m", index, str);
    return true;
}


/**
 * This function checks whether argument n is a valid color index
 */
bool invalidIndex(int n)
{
    return n < 0 || n > 255;
}

/**
 * This function returns the rows of the terminal by detecting its size through
 * the operating system. Its implementation is different depending on the platform
 */
int getConsoleRows(void)
{
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_row;
    #endif
}

/**
 * This function returns the columns of the terminal by detecting its size through
 * the operating system. Its implementation is different depending on the platform
 */
int getConsoleCols(void)
{
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_col;
    #endif
}
