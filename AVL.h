#ifndef ___ARVORE_H___
#define ___ARVORE_H___

#include <stdio.h>
/*para inputs e outputs*/
#include <stdlib.h>
/*para alocação dinamica*/

typedef struct arvore
{
    int fb;
    void *chave;
    struct arvore *esq, *dir;
} arvore;

arvore *criano(void *valor);
/*
Função criano: aloca dinamicamente e inicializa um novo nó de uma
árvore AVL.
Entrada:
    - ponteiro para o valor a ser armazenado no nó.
Saída:
    - ponteiro para o nó criado.
Observação:
    - em caso de falha na alocação de memória, a função exibe uma
      mensagem de erro e encerra a execução do programa.
*/

arvore *aloca(arvore *raiz, void *chave, int *H, int (*diferenca)(void *, void *));
/*
Função aloca: insere um novo elemento em uma árvore AVL realizando
os balanceamentos necessários após a inserção.
Entrada:
    - ponteiro para a raiz da árvore;
    - ponteiro para a chave a ser inserida;
    - ponteiro para a variável indicadora de alteração de altura;
    - função callback para comparação entre chaves.
Saída:
    - ponteiro para a raiz da árvore após a inserção.
Observação:
    - caso a chave já exista, a árvore não é modificada.
*/

arvore *BalanceiaPDir(arvore *raiz, int *H);
/*
Função BalanceiaPDir: realiza o balanceamento de uma árvore AVL
quando ocorre desbalanceamento para a esquerda.
Entrada:
    - ponteiro para a raiz da subárvore desbalanceada;
    - ponteiro para a variável indicadora de alteração de altura.
Saída:
    - ponteiro para a nova raiz da subárvore balanceada.
Observação:
    - executa rotação simples ou dupla para a direita.
*/

arvore *BalanceiaPEsq(arvore *raiz, int *H);
/*
Função BalanceiaPEsq: realiza o balanceamento de uma árvore AVL
quando ocorre desbalanceamento para a direita.
Entrada:
    - ponteiro para a raiz da subárvore desbalanceada;
    - ponteiro para a variável indicadora de alteração de altura.
Saída:
    - ponteiro para a nova raiz da subárvore balanceada.
Observação:
    - executa rotação simples ou dupla para a esquerda.
*/

arvore *removeAVL(arvore *raiz, void *chave, int *H, int (*diferenca)(void *, void *), void (*apaga)(void *));
/*
Função removeAVL: remove um elemento de uma árvore AVL realizando
os balanceamentos necessários após a remoção.
Entrada:
    - ponteiro para a raiz da árvore;
    - ponteiro para a chave a ser removida;
    - ponteiro para a variável indicadora de alteração de altura;
    - função callback para comparação entre chaves;
    - função callback para desalocação da chave removida.
Saída:
    - ponteiro para a raiz da árvore após a remoção.
Observação:
    - caso a chave não exista, a árvore permanece inalterada.
*/

arvore *sucessor(arvore *raiz, arvore *Suc, int *H, void (*apaga)(void *));
/*
Função sucessor: localiza o sucessor em ordem de um nó durante o
processo de remoção em uma árvore AVL.
Entrada:
    - ponteiro para o nó cuja chave será substituída;
    - ponteiro para a raiz da subárvore direita;
    - ponteiro para a variável indicadora de alteração de altura;
    - função callback para desalocação da chave removida.
Saída:
    - ponteiro para a nova raiz da subárvore após a remoção do sucessor.
Observação:
    - substitui a chave do nó removido pela chave do sucessor em ordem.
*/

arvore *BuscaNo(arvore *raiz, void *dado, int (*diferenca)(void *, void *));
/*
Função BuscaNo: procura um elemento em uma árvore AVL.
Entrada:
    - ponteiro para a raiz da árvore;
    - ponteiro para o dado procurado;
    - função callback para comparação entre chaves.
Saída:
    - ponteiro para o nó que contém o dado procurado;
    - NULL caso o elemento não exista na árvore.
*/

void imprime(arvore *raiz, int espacos, void (*printar)(void *));
/*
Função imprime: exibe os elementos de uma árvore AVL em formato
hierárquico. imprime a arvore de forma hierárquica (rotacionada 90°), mostrando a chave de cada nó
e seu fator de balanceamento (fb). Usa recursão em ordem dir->raiz->esq para que a árvore
apareça corretamente orientada quando lida de cima para baixo no terminal
Entrada:
    - ponteiro para a raiz da árvore;
    - nível de profundidade utilizado para indentação;
    - função callback responsável pela impressão da chave.
Saída: nenhuma.
Observação:
    - além da chave, também exibe o fator de balanceamento (fb)
      de cada nó.
*/

void LiberaArvore(arvore *raiz, void (*cb)(void *));
/*
Função LiberaArvore: libera toda a memória ocupada por uma árvore AVL.
Entrada:
    - ponteiro para a raiz da árvore;
    - função callback responsável por liberar a memória associada
      ao dado armazenado em cada nó.
Saída: nenhuma.
Observação:
    - a árvore é percorrida em pós-ordem (esquerda, direita e raiz),
      garantindo que os nós filhos sejam liberados antes de seus pais;
    - para cada nó, a função callback é utilizada para desalocar o
      conteúdo armazenado na chave e, em seguida, o próprio nó é
      removido da memória.
*/
void CamPreOrdem(arvore *raiz, void (*acao)(void *));
/*Função CamPreOrdem: realiza o caminhamento na lógica Pré Ordem.
Entrada:
    - ponteiro para a raiz da árvore;
    - função callback responsável por fazer a ação determinada
      na informação do campo Chave da arvore.
Saída: nenhuma.
Observação:
    -Ótimo para copiar a árvore
    - a árvore é percorrida em pré-ordem (raiz,esquerda e direita),
      realizando a ação do callback no nó da raiz em que está e em
      seguida realizando uma recursão em que o nó central dessa
      nova recursão é o nó à esqueda e apos isso, o nó à direita.
    -   Para evitar acesso de memoria inexistente (acessar campo em uma memória NULL),
     a função verifica se a raiz atual é NULL, caso seja, não realiza a ação(callback)
     e a busca de novos nós "filhos"
*/

void CamEmOrdem(arvore *raiz, void (*acao)(void *));
/*Função CamEmOrdem: realiza o caminhamento na lógica Em Ordem.
Entrada:
    - ponteiro para a raiz da árvore;
    - função callback responsável por fazer a ação determinada
      na informação do campo Chave da arvore.
Saída: nenhuma.
Observação:
    - Realiza o caminhamento em ordem crescente
    - a árvore é percorrida em ordem (esquerda,raiz e direita),
      realizando uma recursão em que a raiz da nova recursão será o filho à esquerda,
     em seguida, a ação do callback no nó da raiz em que está, e por fim,
       realiza uma recursão em que o nó central dessa nova recursão é o nó à direita.
    -   Para evitar acesso de memoria inexistente (acessar campo em uma memória NULL),
     a função verifica se a raiz atual é NULL, caso seja, não realiza a ação(callback)
     e a busca de novos nós "filhos"
*/

void CamPosOrdem(arvore *raiz, void (*acao)(void *));
/*Função CamPosOrdem: realiza o caminhamento na lógica Pós-Ordem.
Entrada:
    - ponteiro para a raiz da árvore;
    - função callback responsável por fazer a ação determinada
      na informação do campo Chave da arvore.
Saída: nenhuma.
Observação:
    -Ótimo para exclusão de árvore
    - a árvore é percorrida em pós-ordem (esquerda, direita e raiz),
      realizando uma recursão em que a raiz da nova recursão será o filho à esquerda,
      em seguida, outra recursão cuja raiz será o filho à direita da raiz atual, por fim,
      realiza a ação sobre o nó atual.
    -   Para evitar acesso de memoria inexistente (acessar campo em uma memória NULL),
     a função verifica se a raiz atual é NULL, caso seja, não realiza a ação(callback)
     e a busca de novos nós "filhos"
*/
#endif