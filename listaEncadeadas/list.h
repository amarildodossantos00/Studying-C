#ifndef LIST_H
#define LIST_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    int idade;
    struct no *proximo;
}Pessoa;


#endif