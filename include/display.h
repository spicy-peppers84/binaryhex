#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>

void setbuffer(void);
void flush(void);
bool fgAnsi(int index, char* str);

#define SET_BUFFER                          setbuffer()
#define FLUSH                               flush()
#define FG_ANSI(index, str)                 fgAnsi(index, str)

#define CLEAR_CONSOLE                       printf("\033[H\033[2J")
#define MENU_OPTION(n, str)                 printf("\033[38;5;99m[%d]\033[0m %s\n", n, str)

#endif
