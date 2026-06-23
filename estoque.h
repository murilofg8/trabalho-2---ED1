#ifndef _ESTOQUE_H_
#define _ESTOQUE_H_

#include "arvore.h"

typedef struct fabricacao{
    int dia,mes,ano;
}fabricacao;

typedef struct validade{
    int dia,mes,ano;
}validade;

typedef struct registro{
    int CodigoDeBarras;
    char NomeDoProduto[100];
    char Fabricante[100];
    int QuantidadeEmEstoque;
    fabricacao Fabricacao;
    validade Validade;
}registro;

#endif