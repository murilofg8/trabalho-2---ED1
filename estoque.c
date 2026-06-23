#include "estoque.h"

int main(){
    int opcao;

    do{
        printf("\n----- MENU ESTOQUE -----\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Consultar Produto\n");
        printf("3 - Remover Produto\n");
        printf("4 - Exibir Estrutura da Árvore\n");
        printf("5 - Encerrar Sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("Digite o código de barras do produto: ");
                scanf("%d",&chave);
                break;

            case 2:
                printf("Digite o código de barras do produto a buscar: ");
                scanf("%d",&chave);
                break;

            case 3:
                printf("Digite o código de barras do produto a excluir: ");
                scanf("%d",&chave);
                break;

            case 4:
                printf("\nEstrutura da arvore:\n");
                break;

            case 5:
                printf("encerrando sistema...\n");
                break;

            default:
                printf("opcao invalida!\n");
        }

    }while(opcao!=5);
    return 0;
}