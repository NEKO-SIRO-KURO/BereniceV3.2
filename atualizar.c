#include "funcoes_main.h"

// Fun��o para atualizar as informa��es de um produto existente
void atualizarProduto(Produto* produtos, int quantidade)
{
    unsigned long long codigo;
    printf("Digite o codigo do produto a ser atualizado:");
    scanf("%llu", &codigo);

    bool produtoEncontrado = false;
    int indiceProduto;

    for (int i = 0; i < quantidade; i++)
    {
        if (produtos[i].codigo == codigo)
        {
            produtoEncontrado = true;
            indiceProduto = i;
            break;
        }
    }

    if (produtoEncontrado)
    {
        printf("Produto encontrado:\n");
        printf("Codigo: %llu\n", produtos[indiceProduto].codigo);
        printf("Nome: %s\n", produtos[indiceProduto].nome);
        printf("Valor Unitario: %.2f\n", produtos[indiceProduto].valor);
        printf("Estoque: %d\n", produtos[indiceProduto].estoque);
        system("pause");
        system("cls");
        float novoValor;
        printf("Digite o novo valor unitario do produto:");
        scanf("%f", &novoValor);

        int novaQuantidade;
        printf("Digite a nova quantidade em estoque do produto:");
        scanf("%d", &novaQuantidade);

        printf("Alteracoes realizadas:\n");
        printf("Valor unitario anterior: %.2f\tNovo valor unitario: %.2f\n", produtos[indiceProduto].valor, novoValor);
        printf("Quantidade em estoque anterior: %d\tNova quantidade em estoque: %d\n", produtos[indiceProduto].estoque, novaQuantidade);
        system("pause");
        produtos[indiceProduto].valor = novoValor;
        produtos[indiceProduto].estoque = novaQuantidade;
    }
    else
    {
        printf("Produto nao encontrado.\n");
        system("pause");
    }
}

// Fun��o para excluir um produto
void excluirProduto(Produto** produtos, int* quantidade)
{
    unsigned long long codigo;
    printf("Digite o codigo do produto a ser excluido: \n");
    scanf("%llu", &codigo);

    bool produtoEncontrado = false;
    int indiceProduto;

    for (int i = 0; i < *quantidade; i++)
    {
        if ((*produtos)[i].codigo == codigo)
        {
            produtoEncontrado = true;
            indiceProduto = i;
            break;
        }
    }

    if (produtoEncontrado)
    {
        system("cls");
        printf("Produto encontrado:\n");
        printf("Codigo: %llu\n", (*produtos)[indiceProduto].codigo);
        printf("Nome: %s\n", (*produtos)[indiceProduto].nome);
        printf("Valor Unitario: %.2f\n", (*produtos)[indiceProduto].valor);
        printf("Estoque: %d\n", (*produtos)[indiceProduto].estoque);

        char confirmacao;
        printf("Deseja realmente excluir o produto? (S/N): ");
        scanf(" %c", &confirmacao);

        if (confirmacao == 'S' || confirmacao == 's')
        {
            for (int i = indiceProduto; i < *quantidade - 1; i++) //serve para reorganizar a lista de produtos
            {
                (*produtos)[i] = (*produtos)[i + 1];
            }

            (*quantidade)--;
            produtos = (Produto **) (Produto *) realloc(*produtos, (*quantidade) * sizeof(Produto));
            printf("Produto excluido com sucesso!\n");
            system("pause");
        }
        else
        {
            printf("Exclusao cancelada.\n");
        }
    }
    else
    {
        printf("Produto nao encontrado.\n");
        }
}
