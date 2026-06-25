#include "biblioteca.h"

int ordenaLivro(livro *a, livro *b){
     int i;
     int resultado;
     char tituloA[200];
     char tituloB[200];
     strcpy(tituloA,a->titulo);
     strcpy(tituloB,b->titulo);
     
     for(i=0; tituloA[i] != '\0'; i++){
          if(tituloA[i] >= 'a' && tituloA[i] <= 'z')
               tituloA[i] -= 'a' - 'A';
     }
     for(i=0; tituloB[i] != '\0'; i++){
          if(tituloB[i] >= 'a' && tituloB[i] <= 'z')
               tituloB[i] -= 'a' - 'A';
     }
     resultado = strcmp(tituloA,tituloB);
     if(resultado != 0)
          return resultado;

     char autorA[200];
     char autorB[200];
     strcpy(autorA,a->autor);
     strcpy(autorB,b->autor);

     for(i=0; autorA[i] != '\0'; i++){
          if(autorA[i] >= 'a' && autorA[i] <= 'z')
               autorA[i] -= 'a' - 'A';
     }
     for(i=0; autorB[i] != '\0'; i++){
          if(autorB[i] >= 'a' && autorB[i] <= 'z')
               autorB[i] -= 'a' - 'A';
     }
     resultado = strcmp(autorA,autorB);
     if(resultado != 0)
          return resultado;

     resultado = a -> ed - b -> ed;
     return resultado;
}

livro *criaLivro(char titulo[], char autor[], char editora[], int ed, int lancamento){

    livro *novoLivro = (livro*) malloc(sizeof(livro));
    strcpy(novoLivro -> titulo , titulo );
    strcpy(novoLivro -> autor  , autor  ); 
    strcpy(novoLivro -> editora, editora);
    novoLivro -> ed = ed;
    novoLivro -> lancamento = lancamento;
    novoLivro -> status = 1;
    novoLivro -> historico = NULL;

    return novoLivro;

}



int main(){
    int opcao;

    do{
        printf("\n----- MENU BIBLIOTECA -----\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Consultar livro\n");
        printf("3 - Remover livro\n");
        printf("4 - realizar emprestimo\n");
        printf("5 - Encerrar Sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&opcao);
    
        switch(opcao){
            case 1:
             
                break;
        

            case 2:

                break;
            

            case 3:

                break;
            

            case 4:

                break;

            case 5:

                break;

            default:
                printf("opcao invalida!\n");
        }

    }while(opcao!=5);

    return 0;
}
