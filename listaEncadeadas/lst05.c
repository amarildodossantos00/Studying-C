#include "list.h"

typedef struct{
	Pessoa *inicio;
	int tam;
}Lista;

void	criar_lista(Lista *lista)
{
	lista->inicio = NULL;
	lista->tam = 0;
}

void    inserir_no_inicio(Lista *lista, int num)
{
    Pessoa *nova = malloc(sizeof(Pessoa));
    if (nova)
    {
        nova->idade = num;
        nova->proximo = lista->inicio;
        lista->inicio = nova;
		lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void	inserir_no_meio(Lista *lista, int num, int ant)
{
	Pessoa *nova = malloc(sizeof(Pessoa));
	Pessoa *aux;

	if (nova)
	{
		nova->idade = num;
		// e o primeiro
		if (lista->inicio == NULL)
		{
			nova->proximo = NULL;
			lista->inicio = nova;
		}
		else
		{
			aux = lista->inicio;
			while (aux->idade != ant && aux->proximo)
				aux = aux->proximo;
			nova->proximo = aux->proximo;
			aux->proximo = nova;
		}
		lista->tam++;
	}
	else
		printf("Erro ao alocar memoria!!!\n");
}

void	inserir_no_fim(Lista *lista, int num)
{
	Pessoa *nova = malloc(sizeof(Pessoa));
	Pessoa *aux;

	if (nova)
	{
		nova->idade = num;
		nova->proximo = NULL;
		// é o primeiro?
		if(lista->inicio == NULL)
			lista->inicio = nova;
		else
		{
			aux = lista->inicio;
			while (aux)
				aux = aux->proximo;
			aux->proximo = nova;
		}
		lista->tam++;
	}
	else
		printf("Erro ao alocar memoria\n");
}

void	imprimir(Lista pessoa)
{
	printf("\n\tTamanho da lista %d: ", pessoa.tam);
	printf("\n\tLista:");
	while (pessoa.inicio)
	{
		printf(" %d", pessoa.inicio->idade);
		pessoa.inicio = pessoa.inicio->proximo;
	}
}

int	main(void)
{
	int	op;
	int	deli;
	int	valor;
	//Pessoa *lista = NULL;
	Lista lista;

	criar_lista(&lista);

	do
	{
		printf("\n\n\t0 - Sair\n\t1 - Inicio\n\t2 - Meio\n\t3 - Fim\n\t4 - Imprimir\n\n\t");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			printf("\nDigite a idade: ");
			scanf("%d", &valor);
			inserir_no_inicio(&lista, valor);
			break;
		case 2:
			printf("\nDigite a idade: ");
			scanf("%d", &valor);
			printf("\n\nDigite o delimitador: ");
			scanf("%d", &deli);
			inserir_no_meio(&lista, valor, deli);
			break;
		case 3:
			printf("\nDigite a idade: ");
			scanf("%d", &valor);
			inserir_no_fim(&lista, valor);
			break;
		case 4:
			imprimir(lista);
			break;

		default:
			if (op != 0)
				printf("Opção inválidda!\n");
			break;
		}
	}while(op != 0);
	return (42);
}
