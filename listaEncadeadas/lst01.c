#include "list.h"

// procedimento para inserir no inicio da lista

void    inserir_no_inicio(Pessoa **lista, int num)
{
    Pessoa *nova = malloc(sizeof(Pessoa));
    if (nova)
    {
        nova->idade = num;
        nova->proximo = *lista;
        *lista = nova;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

int main(void)
{
    
}