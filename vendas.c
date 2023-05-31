
#include "funcoes_main.h"

void venderVista(float total,Produto* produtos, int quantidade, int* carrinho){
    int escolhas;
    bool loop_teste;

    float din, troco;
    bool loop = true;

    if(total <= 50){
        total = total * 0.95;
    }
    else if(total < 100){
        total = total * 0.90;
    }
    else{
        total = total * 0.82;
    }

    while(loop == true){
        system("cls");
        do {
            printf("\nValor com descontos aplicados: %.2f\nValor dado pelo cliente: ", total);
            scanf("%f", &din);

            troco = din - total;

            loop_teste = true;
            if (troco < 0) {
                system("cls");
                printf("Quantia insuficiente\n");
                printf("deseja voltar par o menu de vendas S/N:");
                setbuf(stdin, NULL);
                scanf("%c", &escolhas);
                if (escolhas == 'S' || escolhas == 's') {

                    return;
                } else if (escolhas == 'N' || escolhas == 'n') {
                    loop_teste = false;
                } else {
                    printf("comando invalido,voltando para o menu");
                    return;
                }
            }
        } while (loop_teste != true);
            system("cls");
            printf("\nTroco: %.2f\n", troco);

        for (int i = 0; i < quantidade; i++) { //adiciona a variavel (vendidos) o que foi comprado e tira da variavel (estoque) o que foi comprado
            if(carrinho[i] == 1) {
                produtos[i].vendidos = produtos[i].vendidos + produtos[i].em_compra;
                produtos[i].estoque = produtos[i].estoque - produtos[i].em_compra;
            }
        }

            break;

    }
    return;
}

void venderPrazo(float total,Produto* produtos, int quantidade, int* carrinho){

    int parcelas;
    system("cls");
    printf("\nEm quantas parcelas gostaria de fazer a compra?\n");
    scanf("%d", &parcelas);
    setbuf(stdin, NULL);

    if(parcelas <= 3){
        total = (total*1.05)/parcelas;
    }
    else if(parcelas > 3){
        total = (total*1.08)/parcelas;
    }
    else{
        printf("Opcao invalida");
    }

    printf("O cliente esta devendo %d parcelas de %.2f\n", parcelas, total);
    for (int i = 0; i < quantidade; i++) { //adiciona a variavel (vendidos) o que foi comprado e tira da variavel (estoque) o que foi comprado
        if(carrinho[i] == 1) {
            produtos[i].vendidos = produtos[i].vendidos + produtos[i].em_compra;
            produtos[i].estoque = produtos[i].estoque - produtos[i].em_compra;
        }
    }
    return;
}

void venderMenu(Produto* produtos, int quantidade){

    bool loop_teste = true;
    bool teste = false;

    int indice, j = 0, escolha;
    int carrinho[quantidade];
    char escolhas;
    float total = 0;
    unsigned long long codigo;

    for (int i = 0; i < quantidade; ++i) {
        carrinho[i] = 0;
    }


        do{

            do{
                loop_teste = true;
                teste = false;
                system("cls");
                exibirProdutos(produtos, quantidade, false, false);

                printf("Codigo do produto que deseja vender: ");
                scanf("%llu", &codigo);
                setbuf(stdin, NULL);

                for (int i = 0; i < quantidade; ++i) {
                    if (codigo == produtos[i].codigo ){
                        teste = true;
                        indice = i;
                    }
                }

                if (!teste) {
                    printf("Opcao invalida\n");
                    printf("deseja voltar par o menu de vendas S/N:");
                    scanf("%c", &escolhas);
                    if (escolhas == 'S' || escolhas == 's') {
                        for (int i = 0; i < quantidade; i++) { //limpa a variavel (em_compras)
                            produtos[i].em_compra = 0;
                        }
                        return;
                    } else if (escolhas == 'N' || escolhas == 'n') {
                        loop_teste = false;
                    } else {
                        for (int i = 0; i < quantidade; i++) { //limpa a variavel (em_compras)
                            produtos[i].em_compra = 0;
                        }
                        printf("comando invalido,voltando para o menu");
                        return;
                    }
                }
            } while (loop_teste != true);

            do {
                loop_teste = true;
                printf("\n\nQuantia do produto que deseja vender: ");
                scanf("%d", &produtos[indice].em_compra);
                setbuf(stdin, NULL);

                if (produtos[indice].em_compra <= 0 || produtos[indice].em_compra > produtos[indice].estoque) {
                    system("cls");
                    printf("Quantia invalida\n");
                    printf("deseja voltar par o menu de vendas S/N:");
                    scanf("%c", &escolhas);
                    if (escolhas == 'S' || escolhas == 's') {
                        for (int i = 0; i < quantidade; i++) { //limpa a variavel (em_compras)
                            produtos[i].em_compra = 0;
                        }
                        return;
                    } else if (escolhas == 'N' || escolhas == 'n') {
                        loop_teste = false;
                    } else {
                        for (int i = 0; i < quantidade; i++) { //limpa a variavel (em_compras)
                            produtos[i].em_compra = 0;
                        }
                        printf("comando invalido,voltando para o menu");
                        return;
                    }

                }
            } while (loop_teste != true);
            system("cls");
            printf("quer comprar mais alguma coisa?\ndigite S/N:");
            setbuf(stdin, NULL);
            scanf("%s", &escolhas);
            carrinho[indice] = 1;
        } while (escolhas == 'N' || escolhas != 'n');

        for (int i = 0; i < quantidade; ++i) {
            if(carrinho[i] == 1){
                j = produtos[i].valor * produtos[i].em_compra;
                total += j;

            }
        }


        system("cls");
        printf("|        Preco Total: %.2f       |\n", total);

        system("pause");
        do {
            system("cls");
            printf("O pagamento sera feito:\n1. A vista\n2. A prazo\n\n");
            scanf("%d", &escolha);

            loop_teste = true;
            switch (escolha) {
                case 1:
                    venderVista(total, produtos, quantidade, carrinho);
                    break;

                    case 2:
                        venderPrazo(total, produtos, quantidade, carrinho);
                        break;
                    default:
                        system("cls");
                        printf("Opcao invalida\n");
                        setbuf(stdin, NULL);
                        printf("deseja voltar par o menu de vendas S/N:");
                        scanf("%c", &escolhas);
                        if (escolhas == 'S' || escolhas == 's') {
                            for (int i = 0; i < quantidade; i++) { //limpa a variavel (em_compras)
                                produtos[i].em_compra = 0;
                            }
                            return;
                        } else if (escolhas == 'N' || escolhas == 'n') {
                            loop_teste = false;
                        } else {
                               for (int i = 0; i < quantidade; i++) { //limpa a variavel (em_compras)
                                   produtos[i].em_compra = 0;
                               }
                            printf("comando invalido,voltando para o menu");
                            return;
                        }
                    }
                }while (loop_teste != true);

            for (int i = 0; i < quantidade; i++) { //limpa a variavel (em_compras)
                produtos[i].em_compra = 0;
            }

            printf("\n\nDeseja realizar mais uma venda? S/N:");
            getchar();
            scanf("%c", &escolhas);
            getchar();
            if (escolhas == 's'){
                venderMenu(produtos, quantidade);
            }




    return;
}

