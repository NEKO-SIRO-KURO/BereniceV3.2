#include "funcoes_main.h"



// Protótipos das funções
void exibirProdutos(const Produto* produtos, int quantidade, bool exibirVendidos, bool pausa);
void cadastrarProdutos(Produto** produtos, int* quantidade);
void atualizarProduto(Produto* produtos, int quantidade);
void excluirProduto(Produto** produtos, int* quantidade);
void salvarProdutos(const Produto* produtos, int quantidade);
void lerProdutos(Produto** produtos, int* quantidade, bool pausa);
void relatorioVendas(const Produto* produtos, int quantidade);
void venderMenu(Produto* produtos, int quantidade);

// Função principal do programa
int main()
{
    int opcao;
    Produto* produtos = NULL;
    int quantidade = 0;
    lerProdutos(&produtos, &quantidade,false);
    while (true)
    {
        system("cls");
        printf("Bem vindo a padaria da Berenice!\n");
        printf("\n1. Produtos\n");
        printf("2. Vendas\n");
        printf("3. Sair\n");
        printf("Selecione uma opcao:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            while (true)
            {
                system("cls");
                printf("\n----- MENU DE PRODUTOS -----\n");
                printf("1. Exibir\n");
                printf("2. Cadastrar\n");
                printf("3. Atualizar\n");
                printf("4. Excluir\n");
                printf("5. Salvar\n");
                printf("6. Ler\n");
                printf("7. Voltar\n");
                printf("Digite a opcao desejada:");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    exibirProdutos(produtos, quantidade, false, true);
                    break;
                case 2:
                    cadastrarProdutos(&produtos, &quantidade);
                    break;
                case 3:
                    system("cls");
                    exibirProdutos(produtos, quantidade, false, false);
                    atualizarProduto(produtos, quantidade);
                    break;
                case 4:
                    system("cls");
                    exibirProdutos(produtos, quantidade, false, false);
                    excluirProduto(&produtos, &quantidade);
                    break;
                case 5:
                    salvarProdutos(produtos, quantidade);
                    break;
                case 6:
                    lerProdutos(&produtos, &quantidade, true);
                    break;
                case 7:
                    opcao = -1;  // Voltar ao menu principal
                    break;
                default:
                    printf("Opcao invalida!\n");
                        system("pause");
                    break;
                }

                if (opcao == -1)
                {
                    break;
                }
            }
            break;
        case 2:
            while (true)
            {
                system("cls");
                printf("\n----- MENU DE VENDAS -----\n");
                printf("1. Realizar venda\n");
                printf("2. Relatorio de vendas\n");
                printf("3. Voltar\n");
                printf("Digite a opcao desejada:");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    venderMenu(produtos, quantidade);
                    break;
                case 2:
                    relatorioVendas(produtos, quantidade);
                    break;
                case 3:
                    opcao = -1;  // Voltar ao menu principal
                        system("cls");
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
                }

                if (opcao == -1)
                {
                    break;
                }
            }
            break;
        case 3:
            printf("Encerrando o programa...\n");
            free(produtos);
            return 0;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}



// Função para exibir o relatório de vendas
void relatorioVendas(const Produto* produtos, int quantidade)
{
    FILE *arquivo;

    float totalVendas = 0;

    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    char caminhoArquivo[100];
    const char* nomePasta = "relatorio";

    int dia = now->tm_mday;
    int mes = now->tm_mon + 1;  // +1, pois janeiro é representado como 0
    int ano = now->tm_year + 1900;  // Adicionar 1900, pois o ano é contado a partir de 1900
    int hora = now->tm_hour;
    int minuto = now->tm_min;
    int segundo = now->tm_sec;

    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "%s/%d-%d-%d_%d-%d-%d.txt", nomePasta, dia, mes, ano , hora ,minuto , segundo);

    arquivo = fopen(caminhoArquivo, "w");  // Abre o arquivo para escrita
    printf("Data: %02d/%02d/%d\n", dia, mes, ano);
    printf("Hora: %02d:%02d:%02d\n", hora, minuto, segundo);

    system("cls");
    printf("Item (codigo)\tNome do Item\t     Valor (Unidade)\t   Vendidos\tTotal\n");
    fprintf(arquivo,"Item (codigo)\tNome do Item\tValor (Unidade)\t     Vendidos\tTotal\n");

    for (int i = 0; i < quantidade; i++)
    {
        float valorTotal = produtos[i].valor * produtos[i].vendidos;
        totalVendas += valorTotal;
        printf("%-15llu %-20s %-21.2f %-12d %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].valor, produtos[i].vendidos, valorTotal);
        fprintf(arquivo,"%-15llu %-20s %-15.2f %-10d %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].valor, produtos[i].vendidos, valorTotal);
    }

    printf("Total de vendas: %.2f\n", totalVendas);
    fprintf(arquivo,"Total de vendas: %.2f\n", totalVendas);
    fclose(arquivo);
    system("pause");
}
