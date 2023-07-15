#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void imprime_console(int ln, const char *texto, va_list args) {
    char *texto_impr;
    texto_impr = (char *)malloc(strlen(texto) * sizeof(char));
    memset(texto_impr, 0, sizeof(texto_impr));

    for(int i = 0; i < strlen(texto); i++) {
        if(texto[i] == '%') {
            char prox_char = texto[i + 1];

            if(prox_char == 'i') {
                int i_arg = va_arg(args, int);

                char buff[16];
                sprintf(buff, "%d", i_arg);

                texto_impr = realloc(texto_impr, sizeof(texto) + sizeof(char) * strlen(buff));
                strcat(texto_impr, buff);

                if((i + 1) < strlen(texto))
                    i++;

                texto_impr[strlen(texto_impr)] = texto[++i];
            }

            if(prox_char == 'c') {
                int i_arg = va_arg(args, int);

                unsigned char buff[2];
                memset(buff, 0, sizeof(buff));
                sprintf(buff, "%c", (unsigned char)i_arg);

                texto_impr = realloc(texto_impr, sizeof(texto) + sizeof(unsigned char) * strlen(buff));
                strcat(texto_impr, buff);

                if((i + 1) < strlen(texto))
                    i++;

                texto_impr[strlen(texto_impr)] = texto[++i];
            }
        } else
            texto_impr[strlen(texto_impr)] = texto[i];
    }

    va_end(args);
    
    if(ln)
        printf("%s\n", texto_impr);
    else
        printf("%s", texto_impr);
    
    free(texto_impr);
}

void imprimeln(const char *texto, ...) {
    va_list args;
    va_start(args, texto);
    imprime_console(1, texto, args);
    va_end(args);
}

void imprime(const char *texto, ...) {
    va_list args;
    va_start(args, texto);
    imprime_console(0, texto, args);
    va_end(args);
}