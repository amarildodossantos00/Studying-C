#include "list.h"

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

void	imprimir(Pessoa *pessoa)
{
	printf("\n\tLista: ");
	while (pessoa)
	{
		printf("%d ", pessoa->idade);
		pessoa = pessoa->proximo;
	}
}

int	main(void)
{
	int	op;
	int	deli;
	int	valor;
	Pessoa *lista = NULL;
	do
	{
		printf("\n\t0 - Sair\n\t1 - Inicio\n\t2 - Meio\n\t3 - Fim\n\t4 - Imprimir\n\n\t");
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
