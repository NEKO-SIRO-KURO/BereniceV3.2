#include "funcoes_main.h"

// Função para salvar os produtos em um arquivo
void salvarProdutos(const Produto* produtos, int quantidade)
{
    system("cls");
    FILE* arquivo = fopen("produtos.bin", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.bin\n");
        system("pause");
        return;
    }

    fwrite(&quantidade, sizeof(int), 1, arquivo);

    for (int i = 0; i < quantidade; i++)
    {
        fwrite(&produtos[i].codigo, sizeof(unsigned long long), 1, arquivo);
        fwrite(produtos[i].nome, sizeof(char), 26, arquivo);
        fwrite(&produtos[i].valor, sizeof(float), 1, arquivo);
        fwrite(&produtos[i].estoque, sizeof(int), 1, arquivo);
        fwrite(&produtos[i].vendidos, sizeof(int), 1, arquivo);
    }

    fclose(arquivo);
    printf("Produtos salvos com sucesso!\n");
    system("pause");

}

// Função para ler os produtos de um arquivo
void lerProdutos(Produto** produtos, int* quantidade, bool pausa)
{
    system("cls");
    FILE* arquivo = fopen("produtos.bin", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.bin\n");
        if(pausa) {
            system("pause");
        }
        return;
    }

    fread(quantidade, sizeof(int), 1, arquivo);
    *produtos = realloc(*produtos, *quantidade * sizeof(Produto));

    for (int i = 0; i < *quantidade; i++)
    {
        fread(&(*produtos)[i].codigo, sizeof(unsigned long long), 1, arquivo);
        fread((*produtos)[i].nome, sizeof(char), 26, arquivo);
        fread(&(*produtos)[i].valor, sizeof(float), 1, arquivo);
        fread(&(*produtos)[i].estoque, sizeof(int), 1, arquivo);
        fread(&(*produtos)[i].vendidos, sizeof(int), 1, arquivo);
    }

    fclose(arquivo);
    printf("Produtos lidos com sucesso!\n");
    if(pausa) {
        system("pause");
    }
}

