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


/*
Funçao ordenaLivro: rebebe dois nós AVL e retorna um número inteiro indicando a ordem afabetica.
Entrada: ponteiro para dois nós do tipo livro.
Saìda: 
    -  < 0, se livro a vier primeiro na ordem alfabética
    -  > 0, se livro b vier primeiro na ordem alfabética
    -    0, se forem iguais
*/
int ordenaLivro(livro *a, livro *b);


/*
Função criaLivro: rebebe os dados do dadastramento e retorna um ponteiro para no alocado dinamicamente.
Entrada: titulo, autor, editora, edição e ano de publicação.
Saìda: ponteiro para o nó alocado.
*/
livro *criaLivro(char titulo[], char autor[], char editora[], int ed, int lancamento);

/*
Função consultaLivro: rebebe o titulo e autor do livro e retorna um ponteiro para o nó do livro caso ele exista.
Entrada: titulo e autor do livro.
Saída: ponteiro para o nó do livro caso ele exista, ou NULL caso contrário.
*/
livro *consultaLivro(char titulo[], char autor[]);



#endif
