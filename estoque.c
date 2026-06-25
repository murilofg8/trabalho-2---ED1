#include "estoque.h"
#include <string.h>
/*para strings*/

registro* CriaRegistro(int codigo, char* nome, char* fabricante, int QuantidadeEmEstoque, fabricacao Fabricacao, validade Validade){
    registro *novo = (registro*)malloc(sizeof(registro));
    if(novo == NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novo->CodigoDeBarras = codigo;
    strncpy(novo->NomeDoProduto, nome, 99);
    novo->NomeDoProduto[99] = '\0';
    strncpy(novo->Fabricante, fabricante, 99);
    novo->Fabricante[99] = '\0';
    novo->QuantidadeEmEstoque = QuantidadeEmEstoque;
    novo->Fabricacao = Fabricacao;
    novo->Validade = Validade;

    return novo;
}

void ApagaRegistro(void *Pont){
    registro *aux = (registro*)Pont;
    free(aux);
}

int DiferencaCodigo(void *chave1, void *chave2){
    registro *r1 = (registro*)chave1;
    registro *r2 = (registro*)chave2;
    return r1->CodigoDeBarras - r2->CodigoDeBarras;
}

void ExibeProduto(registro *produto){
    printf("codigo do produto: %d\n", produto->CodigoDeBarras);
    printf("nome do produto: %s\n", produto->NomeDoProduto);
    printf("fabricante do produto: %s\n", produto->Fabricante);
    printf("quantidade em estoque do produto: %d\n", produto->QuantidadeEmEstoque);
    printf("data de fabricacao do produto: %d/%d/%d\n", produto->Fabricacao.dia, produto->Fabricacao.mes, produto->Fabricacao.ano);
    printf("data de validade do produto: %d/%d/%d\n", produto->Validade.dia, produto->Validade.mes, produto->Validade.ano);
}

void PrintaCodigo(void *dado){
    registro *r = (registro*)dado;
    printf("%d", r->CodigoDeBarras);
}

int main(){
    int opcao, chave;
    arvore *raiz = NULL;
    int H;

    do{
        printf("\n----- MENU ESTOQUE -----\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar Produto\n");
        printf("3 - Remover Produto\n");
        printf("4 - Exibir Estrutura da Arvore\n");
        printf("5 - Encerrar Sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&opcao);
    
        switch(opcao){
            case 1:{
                printf("Digite o codigo de barras do produto: ");
                scanf("%d",&chave);
                while(getchar() != '\n');

                registro busca;
                busca.CodigoDeBarras = chave;
                arvore *encontrado = BuscaNo(raiz, &busca, DiferencaCodigo);

                if(encontrado != NULL){
                    printf("Produto ja cadastrado\n");
                    ExibeProduto((registro*)encontrado->chave);
                } else {
                    char nome[100];
                    char fabricante[100];
                    int quantidade;
                    fabricacao Fabricacao;
                    validade Validade;

                    printf("Digite o nome do produto: ");
                    fgets(nome, 100, stdin);
                    nome[strcspn(nome, "\n")] = '\0';

                    printf("Digite o fabricante do produto: ");
                    fgets(fabricante, 100, stdin);
                    fabricante[strcspn(fabricante, "\n")] = '\0';

                    printf("Digite a quantidade em estoque: ");
                    scanf("%d", &quantidade);
                    while(getchar() != '\n');

                    printf("Digite a data de fabricacao (dia mes ano): ");
                    scanf("%d %d %d", &Fabricacao.dia, &Fabricacao.mes, &Fabricacao.ano);
                    while(getchar() != '\n');

                    printf("Digite a data de validade (dia mes ano): ");
                    scanf("%d %d %d", &Validade.dia, &Validade.mes, &Validade.ano);
                    while(getchar() != '\n');

                    registro *novo = CriaRegistro(chave, nome, fabricante, quantidade, Fabricacao, Validade);
                    raiz = aloca(raiz, novo, &H, DiferencaCodigo);
                    printf("Produto cadastrado com sucesso!\n");
                }
                break;
            }

            case 2:{
                printf("Digite o código de barras do produto a buscar: ");
                scanf("%d",&chave);
                while(getchar() != '\n');

                registro busca;
                busca.CodigoDeBarras = chave;
                arvore *encontrado = BuscaNo(raiz, &busca, DiferencaCodigo);

                if(encontrado != NULL){
                    ExibeProduto((registro*)encontrado->chave);
                }else{printf("Produto nao encontrado\n");}

                break;
            }

            case 3:{
                printf("Digite o código de barras do produto a excluir: ");
                scanf("%d",&chave);
                while(getchar() != '\n');

                registro busca;
                busca.CodigoDeBarras = chave;
                arvore *encontrado = BuscaNo(raiz, &busca, DiferencaCodigo);
                char confirmacao[100];

                if(encontrado != NULL){
                    ExibeProduto((registro*)encontrado->chave);
                    printf("confirme a exclusao do profuto: (sim ou nao)");
                    fgets(confirmacao, 100, stdin);
                    confirmacao[strcspn(confirmacao, "\n")] = '\0';
                    if(strcmp(confirmacao, "sim") == 0){
                        raiz = removeAVL(raiz, &busca, &H, DiferencaCodigo, ApagaRegistro);
                    }else{printf("cancelando exclusao\n");}
                }
                else{printf("Produto nao encontrado\n");}

                break;
            }

            case 4:
                printf("\nEstrutura da arvore:\n");
                imprime(raiz,0,PrintaCodigo);
                break;

            case 5:
                LiberaArvore(raiz, ApagaRegistro);
                printf("encerrando sistema...\n");
                break;

            default:
                printf("opcao invalida!\n");
        }

    }while(opcao!=5);
    return 0;
}


