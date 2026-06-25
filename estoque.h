#ifndef _ESTOQUE_H_
#define _ESTOQUE_H_

#include "AVL.h"

typedef struct fabricacao{
    int dia,mes,ano;
}fabricacao;
/*
Estrutura fabricacao: armazena a data de fabricação de um produto.
Campos:
    - dia: dia da fabricação.
    - mes: mês da fabricação.
    - ano: ano da fabricação.
*/

typedef struct validade{
    int dia,mes,ano;
}validade;
/*
Estrutura validade: armazena a data de validade de um produto.
Campos:
    - dia: dia de vencimento.
    - mes: mês de vencimento.
    - ano: ano de vencimento.
*/

typedef struct registro{
    int CodigoDeBarras;
    char NomeDoProduto[100];
    char Fabricante[100];
    int QuantidadeEmEstoque;
    fabricacao Fabricacao;
    validade Validade;
}registro;
/*
Estrutura registro: representa o cadastro de um produto em estoque.
Campos:
    - CodigoDeBarras: identificador único do produto.
    - NomeDoProduto: nome do produto.
    - Fabricante: nome do fabricante do produto.
    - QuantidadeEmEstoque: quantidade disponível em estoque.
    - Fabricacao: data de fabricação do produto.
    - Validade: data de validade do produto.
*/

registro* CriaRegistro(int codigo, char* nome, char* fabricante, int QuantidadeEmEstoque, fabricacao Fabricacao, validade Validade);
/*
Função CriaRegistro: aloca dinamicamente e inicializa um novo registro
de produto com as informações fornecidas.
Entrada:
    - código de barras do produto;
    - nome do produto;
    - nome do fabricante;
    - quantidade disponível em estoque;
    - data de fabricação;
    - data de validade.
Saída:
    - ponteiro para o registro criado e inicializado.
Observação:
    - os campos NomeDoProduto e Fabricante são copiados para o registro,
      com limite de 99 caracteres, garantindo a terminação da string
      com '\0';
    - em caso de falha na alocação de memória, a função exibe uma
      mensagem de erro e encerra a execução do programa.
*/

void ApagaRegistro(void *Pont);
/*
Função ApagaRegistro: libera a memória ocupada por um registro.
Entrada:
    - ponteiro genérico para o registro a ser removido.
Saída: nenhuma.
Observação:
    - o ponteiro recebido é convertido para o tipo registro antes
      da liberação da memória.
*/

int DiferencaCodigo(void *chave1, void *chave2);
/*
Função DiferencaCodigo: compara dois registros utilizando seus
códigos de barras como chave de ordenação.
Entrada:
    - ponteiro para o primeiro registro;
    - ponteiro para o segundo registro.
Saída:
    - valor negativo se o código de barras do primeiro registro
      for menor que o do segundo;
    - zero se os códigos de barras forem iguais;
    - valor positivo se o código de barras do primeiro registro
      for maior que o do segundo.
Observação:
    - utilizada como função callback de comparação em estruturas
      de dados que armazenam registros de forma genérica.
*/

void ExibeProduto(registro *produto);
/*
Função ExibeProduto: exibe na tela todas as informações de um produto
armazenado em um registro.
Entrada:
    - ponteiro para o registro do produto a ser exibido.
Saída: nenhuma.
Observação:
    - são exibidos o código de barras, nome, fabricante,
      quantidade em estoque, data de fabricação e data de validade
      do produto.
*/

void PrintaCodigo(void *dado);
/*
Função PrintaCodigo: exibe na tela o código de barras de um produto.
Entrada:
    - ponteiro genérico para um registro de produto.
Saída: nenhuma.
Observação:
    - o ponteiro recebido é convertido para o tipo registro antes
      do acesso ao campo CodigoDeBarras;
    - utilizada como função callback de impressão em estruturas
      de dados genéricas.
*/

#endif