#include "funcoes_main.h"

// Fun��o para cadastrar novos produtos
void cadastrarProdutos(Produto** produtos, int* quantidade)
{
    system("cls");
    int numNovosProdutos;
    printf("\nDigite a quantidade de novos produtos a serem cadastrados: \n");
    scanf("%d", &numNovosProdutos);
    *produtos = (Produto*)realloc(*produtos, (*quantidade + numNovosProdutos) * sizeof(Produto));

    for (int i = 0; i < numNovosProdutos; i++)
    {
        system("cls");
        Produto novoProduto;
        printf("Digite os dados do produto %d:\n", i + 1);
        printf("Codigo do Item: \n");
        scanf("%llu", &novoProduto.codigo);

        bool codigoExistente = false;

        for (int j = 0; j < *quantidade; j++)
        {
            if ((*produtos)[j].codigo == novoProduto.codigo)
            {
                codigoExistente = true;
                break;
            }
        }

        if (codigoExistente)
        {
            printf("Codigo do item j� existente. Por favor, insira um c�digo diferente.\n");
            i--;  // Re-iterar a inser��o do mesmo produto
            continue;
        }

        printf("Nome do Item: \n");
        scanf(" %[^\n]s", novoProduto.nome);// Lê uma string até encontrar uma nova linha (\n)

        printf("Preco Unitario do item: \n");
        scanf("%f", &novoProduto.valor);

        printf("Quantidade do item em estoque: \n");
        scanf("%d", &novoProduto.estoque);

        novoProduto.vendidos = 0;

        (*produtos)[*quantidade + i] = novoProduto;
    }

    *quantidade += numNovosProdutos;

    printf("%d produto(s) cadastrado(s) com sucesso!\n", numNovosProdutos);
}
