#include "./ps.h"

inteiro func_principal() {
    inteiro inteiros[] = {1, 2, 3, 4, 5};

    para(inteiro i = 0; i < 5; i++)
        imprimeln("ELEMENTO [%i]: %i", i, inteiros[i]);

    retorna 0;
}