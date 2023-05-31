#include "funcoes_main.h"

// Fun��o para exibir a lista de produtos
void exibirProdutos(const Produto* produtos, int quantidade, bool exibirVendidos,bool pausa)
{
    system("cls");
    printf("Item (codigo)\tNome do Item\t     Valor (Unidade)\tEstoque");
    if (exibirVendidos)
    {
        printf("\tVendidos \n");
    }
    printf("\n");

    for (int i = 0; i < quantidade; i++)
    {
            printf("%-15llu %-20s %-18.2f %-12d\n", produtos[i].codigo, produtos[i].nome, produtos[i].valor,
                   produtos[i].estoque);
            if (exibirVendidos) {
                printf("%d", produtos[i].vendidos);
            }

    }
    if (pausa) {
        system("pause");
    }
}
