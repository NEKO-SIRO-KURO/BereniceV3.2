#ifndef VARIAVEIS_H_INCLUDED
#define VARIAVEIS_H_INCLUDED

// Estrutura para representar um produto
typedef struct
{
    unsigned long long codigo;
    char nome[26];
    float valor;
    int estoque;
    int vendidos;
    int em_compra;
} Produto;
#include <stdio.h>

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "atualizar.c"
#include "cadastrar.c"
#include "exibir.c"
#include "salvar.c"
#include "vendas.c"
#endif // VARIAVEIS_H_INCLUDED
