#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* printf */
int _printf(const char *format, ...);

/* helpers */
int print_c(va_list args);
int print_s(va_list args);
int print_percent(void);

/* integers (%d, %i) */
int print_d(va_list args);

#endif /* MAIN_H */

