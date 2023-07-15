#include <stdarg.h>

#ifndef _PSSTDIO_H
#define _PSSTDIO_H

void imprime_console(int ln, const char *texto, va_list args);
void imprimeln(const char *texto, ...);
void imprime(const char *texto, ...);

#endif