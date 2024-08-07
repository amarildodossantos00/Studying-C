#include "list.h"

// Procedimento para inserir no fim da lista

void	inserir_no_fim(Pessoa **lista, int num)
{
	Pessoa *nova = malloc(sizeof(Pessoa));
	Pessoa *aux;

	if (nova)
	{
		nova->idade = num;
		nova->proximo = NULL;
		// é o primeiro?
		if(*lista == NULL)
			*lista = nova;
		else
		{
			aux = *lista;
			while (aux->proximo)
				aux = aux->proximo;
			aux->proximo = nova;
		}
	}
	else
		printf("Erro ao alocar memoria\n");
}

int	main(void)
{

}
