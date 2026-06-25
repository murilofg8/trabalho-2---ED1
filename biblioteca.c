#include "biblioteca.h"

int ordenaLivro(livro *a, livro *b){
     char tA[200];
     char tB[200];
     strcpy(tA,a->titulo);
     strcpy(tB,b->titulo);
     char aA[200];
     char aB[200];
     strcpy(aA,a->autor);
     strcpy(aB,b->autor);
     int i;
     int resultado;
     for(i=0; tA[i] != '\0'; i++){
          if(tA[i] >= 97 && tA[i] <= 122)
               tA[i] -= 32;
     }
     for(i=0; tB[i] != '\0'; i++){
          if(tB[i] >= 97 && tB[i] <= 122)
               tB[i] -= 32;
     }
     resultado = strcmp(tA,tB);
     if(resultado != 0)
          return resultado;

     for(i=0; aA[i] != '\0'; i++){
          if(aA[i] >= 97 && aA[i] <= 122)
               aA[i] -= 32;
     }
     for(i=0; aB[i] != '\0'; i++){
          if(aB[i] >= 97 && aB[i] <= 122)
               aB[i] -= 32;
     }
     resultado = strcmp(aA,aB);
     if(resultado != 0)
          return resultado;

     resultado = a -> ed - b -> ed;
     return resultado;


}
