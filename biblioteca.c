#include "biblioteca.h"

historico *criaNo(char locatario[], data emprestimo, data devolucao){
    historico *novoNo = (historico*)malloc(sizeof(historico));
    if(novoNo == NULL){
        printf("Falha de alocacao!\n");
        exit(1);
    }
    strcpy(novoNo->locatario, locatario);
    novoNo->emprestimo.dia = emprestimo.dia;
    novoNo->emprestimo.mes = emprestimo.mes;
    novoNo->emprestimo.ano = emprestimo.ano;
    novoNo->devolucao.dia = devolucao.dia;
    novoNo->devolucao.mes = devolucao.mes;
    novoNo->devolucao.ano = devolucao.ano;
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



int ordenaLivro(void *pontA, void *pontB){
    livro *a=(livro *)pontA;
    livro *b=(livro *)pontB;
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

void acaoConsulta(void *pontA, void *pontB) {
    livro *LivroArvore = (livro *)pontA;
    livro *LivroBuscar = (livro *)pontB;

    // O truque: igualamos temporariamente a edição para a ordenaLivro 
    // ignorar o desempate por edição e checar apenas Título e Autor
    LivroBuscar->ed = LivroArvore->ed;

    // Reaproveitando a sua função original!
    if (ordenaLivro(LivroBuscar, LivroArvore) == 0) {
        
        printf("\n----------- \n");
        printf("Titulo: %s\n", LivroArvore->titulo);
        printf("Autores: %s\n", LivroArvore->autor);
        printf("Edicao: %d\n", LivroArvore->ed);
        printf("Editora: %s\n", LivroArvore->editora);
        printf("Ano de Lancamento: %d\n", LivroArvore->lancamento);
        printf("Status: %s\n", (LivroArvore->status == 1) ? "Disponivel" : "Emprestado");
        printf("----------- \n");
        
        LivroBuscar->status = 1; // Usamos o campo status do busca como flag de "encontrado"
    }
}




livro *criaLivro(char titulo[], char autor[], int ed){
    livro *novoLivro = (livro*) calloc(1,sizeof(livro));
    if(novoLivro == NULL){
        printf("Falha de alocacao!\n");
        exit(1);
    }
    strcpy(novoLivro -> titulo , titulo );
    strcpy(novoLivro -> autor  , autor  ); 
    novoLivro -> ed = ed;


    return novoLivro;

}

void removeLivro( void*pont){
    livro *no=(livro *)pont;
    if(no == NULL)
        return;
    destroiHistorico(no->emprestimos);
    free(no);
 
}



int main(){
    int H=0,opcao, edicao;
    data DataRet, DataDev={0, 0, 0};
    char AutorLivro[200], NomLivro[200], Locatario[50];
    livro *LivroVaz;
    arvore *arvoreinicial=NULL;
    char CaractereConfirm;
    

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
                printf("\n Digite o nome do livro: ");
                scanf(" %199[^\n]", NomLivro);
                printf("\n Digite o nome dos autores: ");
                scanf(" %199[^\n]", AutorLivro);
                printf("\n Digite a edicao do livro: ");
                scanf("%d", &edicao);
                LivroVaz=criaLivro(NomLivro,AutorLivro,edicao);
                
                if (BuscaNo(arvoreinicial,LivroVaz, ordenaLivro)!=NULL)
                {
                    printf("Este exemplar ja se encontra cadastrado");
                    free(LivroVaz);
                }
                else{
                    printf("\n Digite o nome da editora: ");
                    scanf(" %49[^\n]", LivroVaz->editora);
                    printf("\n Digite o ano de lancamento: ");
                    scanf("%d", &LivroVaz->lancamento);
                    LivroVaz -> status = 1;
                    H = 0;
                    arvoreinicial=aloca(arvoreinicial,LivroVaz,&H,ordenaLivro);
                }

                break;
        

            case 2:
                printf("\nDigite o nome do livro: ");
                scanf(" %199[^\n]", NomLivro);
                printf("\nDigite o nome dos autores: ");
                scanf(" %199[^\n]", AutorLivro);
                LivroVaz=criaLivro(NomLivro,AutorLivro, 0);
                printf("\n  ----- EXEMPLARES CORRESPONDENTES ----- ");
                CamEmOrdem(arvoreinicial,LivroVaz,acaoConsulta);
                if (LivroVaz->status == 0) {
                    printf("\nErro: Livro nao encontrado\n");
                }
                free(LivroVaz);
                break;
            

            case 3:
                printf("\nDigite o nome do livro a ser removido: ");
                scanf(" %199[^\n]", NomLivro);
                printf("\nDigite o nome dos autores: ");
                scanf(" %199[^\n]", AutorLivro);
                LivroVaz=criaLivro(NomLivro,AutorLivro, 0);
                printf("\n  ----- EXEMPLARES CORRESPONDENTES ----- ");
                CamEmOrdem(arvoreinicial,LivroVaz,acaoConsulta);
                if (LivroVaz->status == 0) {
                    printf("\nErro: Livro nao encontrado\n");
                }
                else{
                    printf("\nDigite a edicao do livro a ser removido: ");
                    scanf("%d", &edicao);
                    LivroVaz->ed=edicao;
                    arvore *noEncontrado = BuscaNo(arvoreinicial, LivroVaz, ordenaLivro);
                    if (noEncontrado == NULL){
                        printf("\n Erro: Livro inexistente \n");
                    }
                    else
                    {
                        printf("\nDeseja remover esse livro? (S/N): ");
                        scanf(" %c", &CaractereConfirm);
                        if (CaractereConfirm == 's' || CaractereConfirm == 'S')
                        {
                            H = 0;
                            arvoreinicial = removeAVL(arvoreinicial, LivroVaz, &H, ordenaLivro, removeLivro);
                            printf("\n Livro removido com exito. \n");
                        }
                        else
                        {
                            printf("\n Livro nao removido. \n");
                        }
                    }
                }
                free(LivroVaz);
                break;
            

            case 4:
                printf("\nDigite o nome do livro que deseja fazer o emprestimo: ");
                scanf(" %199[^\n]", NomLivro);
                printf("\nDigite o nome dos autores: ");
                scanf(" %199[^\n]", AutorLivro);
                LivroVaz=criaLivro(NomLivro,AutorLivro, 0);
                printf("\n  ----- EXEMPLARES CORRESPONDENTES ----- ");
                CamEmOrdem(arvoreinicial,LivroVaz,acaoConsulta);
                if (LivroVaz->status == 0) {
                    printf("\nErro: Livro nao encontrado\n");
                }
                else{
                    printf("\nDigite a edicao do livro que deseja fazer o emprestimo: ");
                    scanf("%d", &edicao);
                    LivroVaz->ed=edicao;
                    arvore *noEncontrado = BuscaNo(arvoreinicial, LivroVaz, ordenaLivro);
                    if (noEncontrado == NULL){
                        printf("\n Erro: Livro nao encontrado \n");
                    }
                    else
                    {
                        livro *livroReal = (livro *)noEncontrado->chave;
                        if(livroReal->status==0){
                        printf("\n Alerta! Operacao abortada, livro indisponivel para emprestimo. \n");

                        }
                        else{
                            printf("\nDigite o nome do locatario: ");
                            scanf(" %49[^\n]", Locatario);
                            printf("\nDigite o nome a data de retirada em formado de [Dia mes ano]: ");
                            scanf("%d %d %d", &DataRet.dia, &DataRet.mes, &DataRet.ano);
                            livroReal->emprestimos=addHistorico(livroReal->emprestimos,Locatario,DataRet,DataDev);
                            livroReal->status = 0;
                            printf("\n Emprestimo realizado com exito. \n");
                        }
                    }
                }
                free(LivroVaz);
                break;

            case 5:
                printf("\n Sistema encerrado. \n");
                LiberaArvore(arvoreinicial, removeLivro);
                arvoreinicial = NULL;
                break;

            default:
                printf("opcao invalida!\n");
        }

    }while(opcao!=5);

    return 0;
}
