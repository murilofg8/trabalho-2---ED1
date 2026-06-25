#ifndef _ESTOQUE_H_
#define _ESTOQUE_H_

#include "AVL.h"
#include <string.h>

typedef struct data{
     int dia, mes, ano;
}data;

typedef struct livro{
     char titulo[200];
     char autor [200];
     char editora[50];
     int  lancamento;
     int  ed;
     int status;
     //historico de emprestivo: usar lista ou arvore;
}livro;

int ordenaLivro(livro a, livro b);



#endif
