#ifndef _ESTOQUE_H_
#define _ESTOQUE_H_

#include "AVL.h"
#include <string.h>

typedef struct data{
     int dia, mes, ano;
}data;

typedef struct historico{
     char locatario[200];
     data emprestimo;
     data devolucao;
     struct historico *prox;
}historico;

typedef struct livro{
     char titulo[200];
     char autor [200];
     char editora[50];
     int  lancamento;
     int  ed;
     int status;
     historico *emprestimos;
}livro;

/*
Função criaNo: recebe os dados do emprestimo e retorna um ponteiro para no alocado dinamicamente.
Entrada: locatario, data de emprestimo e data de devolução. 
Saída: ponteiro para o nó alocado.
*/
historico *criaNo(char locatario[], data emprestimo, data devolucao);

/*
Função addHistorico: recebe um ponteiro para o histórico de emprestimos, os dados do emprestimo e retorna um ponteiro para o histórico atualizado.
Entrada: ponteiro para o histórico de emprestimos, locatario, data de emprestimo e data de devolução.
Saída: ponteiro para o histórico atualizado.
*/
historico *addHistorico(historico *emprestimos, char locatario[], data emprestimo, data devolucao);

/*
Função destroiHistorico: recebe um ponteiro para o histórico de emprestimos e libera a memória alocada.
Entrada: ponteiro para o histórico de emprestimos.
Saída: void.
*/
void destroiHistorico(historico *emprestimos);

/*
Funçao ordenaLivro: recebe dois nós AVL e retorna um número inteiro indicando a ordem afabetica.
Entrada: ponteiro para dois nós do tipo livro.
Saìda: 
    -  < 0, se livro a vier primeiro na ordem alfabética
    -  > 0, se livro b vier primeiro na ordem alfabética
    -    0, se forem iguais
*/
int ordenaLivro(void *pontA, void *pontB);

/*
Função acaoConsulta: percorre a árvore em ordem e imprime os dados de todos
os exemplares cujo título e autor coincidam com os informados pelo usuário.
Entrada: ponteiro para o nó atual da árvore (livro cadastrado) e ponteiro
para o livro de busca contendo título e autor digitados pelo usuário.
Saída: void.
*/
void acaoConsulta(void *pontA, void *pontB);

/*
Função criaLivro: recebe os dados do cadastramento e retorna um ponteiro para no alocado dinamicamente.
Entrada: titulo, autor, editora, edição e ano de publicação.
Saìda: ponteiro para o nó alocado.
*/
livro *criaLivro(char titulo[], char autor[], int ed);

/*
Função removeLivro: recebe um ponteiro para o nó do livro e libera a memória alocada. fução callback para a função de remoção da árvore AVL.
Entrada: ponteiro para o nó do livro.
saída: void.
*/
void removeLivro( void *no);


#endif
