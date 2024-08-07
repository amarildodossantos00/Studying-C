#include "list.h"

// Procedimento para inserir no meio da lista

void	inserir_no_meio(Pessoa **lista, int num, int ant)
{
	Pessoa *nova = malloc(sizeof(Pessoa));
	Pessoa *aux;

	if (nova)
	{
		nova->idade = num;
		// e o primeiro
		if (*lista == NULL)
		{
			nova->proximo = NULL;
			*lista = nova;
		}
		else
		{
			aux = *lista;
			while (aux->idade != ant && aux->proximo)
				aux = aux->proximo;
			nova->proximo = aux->proximo;
			aux->proximo = nova;
		}
	}
	else
		printf("Erro ao alocar memoria!!!\n");
}

int	main(void)
{

}
