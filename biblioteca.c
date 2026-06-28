#include "biblioteca.h"

historico *criaNo(char locatario[], data emprestimo, data devolucao){
    historico *novoNo = (historico*)malloc(sizeof(historico));
    if(novoNo == NULL){
        printf("Falha de alocacao!\n");
        exit(1);
    }
    strcpy(novoNo->locatario, locatario);
    novoNo->emprestimo->dia = emprestimo->dia;
    novoNo->emprestimo->mes = emprestimo->mes;
    novoNo->emprestimo->ano = emprestimo->ano;
    novoNo->devolucao ->dia = devolucao ->dia;
    novoNo->devolucao ->mes = devolucao ->mes;
    novoNo->devolucao ->ano = devolucao ->ano;
    novoNo->prox = NULL;
    return novoNo;
}

historico *addHistorico(historico *emprestimos, char locatario[], data emprestimo, data devolucao){
    historico *novoNo = criaNo(locatario, emprestimo, devolucao);
    if(emprestimos == NULL){
        return novoNo;
    }
    historico *aux = emprestimos->prox;
    emprestimos->prox = novoNo;
    novoNo->prox = aux;
   
    return emprestimos;
}

void destroiHistorico(historico *emprestimos){
    historico *aux;
    while(emprestimos != NULL){
        aux = emprestimos;
        emprestimos = emprestimos->prox;
        free(aux);
    }
}



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

livro *consultaLivro(char titulo[], char autor[], int ed, livro *no){

    if(no == NULL)
        return NULL;
    if(strcmp(no->titulo, titulo) == 0 && strcmp(no->autor, autor) == 0 && ed == 0)
        return no;

    if(strcmp(no->titulo, titulo) == 0 && strcmp(no->autor, autor) == 0 && ed == no->ed)
        return no;

    return NULL;

}

void removeLivro( livro *no){

    if(no == NULL)
        return;
    destroiHistorico(no->emprestimos);
    free(no);

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
