#include "AVL.h"

arvore *criano(void *valor){
    arvore *novo;
    novo = (arvore *)calloc(1, sizeof(arvore));
    if (novo == NULL){
        printf("Falha de alocacao!\n");
        exit(1);
    }
    novo->chave = valor;
    return novo;
}

arvore *aloca(arvore *raiz, void *chave, int *H, int (*diferenca)(void *, void *)){
    if (raiz == NULL){
        *H = 1;
        return criano(chave);
    }
    if (diferenca(chave, raiz->chave) == 0){
        printf("Valor existente na arvore!\n");
        return raiz;
    }

    if (diferenca(chave, raiz->chave) > 0){
        raiz->dir = aloca(raiz->dir, chave, H, diferenca);
        if (*H == 1){
            switch (raiz->fb)
            {
            case 1:
                raiz->fb = 0;
                break;
            case 0:
                raiz->fb = -1;
                break;
            case -1:
                raiz = BalanceiaPEsq(raiz, H);
                *H = 0;
                break;
            }
        }
    }

    else{
        raiz->esq = aloca(raiz->esq, chave, H, diferenca);
        if (*H == 1){
            switch (raiz->fb){
            case -1:
                raiz->fb = 0;
                break;
            case 0:
                raiz->fb = 1;
                break;
            case 1:
                raiz = BalanceiaPDir(raiz, H);
                *H = 0;
                break;
            }
        }
    }
    return raiz;
}

arvore *BalanceiaPDir(arvore *raiz, int *H) { 
    arvore *filhoE = raiz->esq, *netoED = raiz->esq->dir;
    if (raiz->esq->fb >= 0){
        raiz->esq = filhoE->dir;
        filhoE->dir = raiz;
        if (filhoE->fb == 1){
            raiz->fb = 0;
            filhoE->fb = 0;
        }
        else{
            *H = 0;
            raiz->fb = 1;
            filhoE->fb = -1;
        }
        return filhoE;
    }
    else{
        switch (netoED->fb){
        case -1:
            filhoE->fb = 1;
            raiz->fb = 0;
            break;
        case 0:
            filhoE->fb = 0;
            raiz->fb = 0;
            break;
        case 1:
            filhoE->fb = 0;
            raiz->fb = -1;
            break;
        }
        netoED->fb = 0;
        raiz->esq = netoED->dir;
        netoED->dir = raiz;
        filhoE->dir = netoED->esq;
        netoED->esq = filhoE;
        return netoED;
    }
}// rotaciona p/direita

arvore *BalanceiaPEsq(arvore *raiz, int *H){ 
    arvore *filhoD = raiz->dir, *netoDE = raiz->dir->esq;
    if (raiz->dir->fb <= 0){
        raiz->dir = filhoD->esq;
        filhoD->esq = raiz;
        if (filhoD->fb == -1){
            raiz->fb = 0;
            filhoD->fb = 0;
        }
        else{
            *H = 0;
            raiz->fb = -1;
            filhoD->fb = 1;
        }
        return filhoD;
    }
    else{
        switch (netoDE->fb){
        case -1:
            filhoD->fb = 0;
            raiz->fb = 1;
            break;
        case 0:
            filhoD->fb = 0;
            raiz->fb = 0;
            break;
        case 1:
            filhoD->fb = -1;
            raiz->fb = 0;
            break;
        }
        netoDE->fb = 0;
        raiz->dir = netoDE->esq;
        netoDE->esq = raiz;
        filhoD->esq = netoDE->dir;
        netoDE->dir = filhoD;
        return netoDE;
    }
}// rotaciona p/esquerda


arvore *removeAVL(arvore *raiz, void *chave, int *H, int (*diferenca)(void *, void *), void (*apaga)(void *)){
    if (raiz == NULL){
        *H = 0;
        return NULL;
    }
    arvore *Temp;
    if (diferenca(chave, raiz->chave) == 0){
        *H = 1;
        if (raiz->esq == NULL){
            if (raiz->dir == NULL){
                Temp = NULL;
            }
            else{
                Temp = raiz->dir;
            }
            apaga(raiz->chave);
            free(raiz);
            return Temp;
        }
        else{
            if (raiz->dir == NULL){
                Temp = raiz->esq;
                apaga(raiz->chave);
                free(raiz);
                return Temp;
            }
            else{
                raiz->dir = sucessor(raiz, raiz->dir, H, apaga);
                return raiz;
            }
        }
    }
    if (diferenca(chave, raiz->chave) > 0){
        raiz->dir = removeAVL(raiz->dir, chave, H, diferenca, apaga);
        if (*H == 1){
            switch (raiz->fb){
            case 1:
                raiz = BalanceiaPDir(raiz, H);
                break;
            case 0:
                raiz->fb = 1;
                *H = 0;
                break;
            case -1:
                raiz->fb = 0;
                break;
            }
        }
    }
    else{
        raiz->esq = removeAVL(raiz->esq, chave, H, diferenca, apaga);
        if (*H == 1){
            switch (raiz->fb){
            case -1:
                raiz = BalanceiaPEsq(raiz, H);
                break;
            case 0:
                raiz->fb = -1;
                *H = 0;
                break;
            case 1:
                raiz->fb = 0;
                break;
            }
        }
    }
    return raiz;
}

arvore *sucessor(arvore *raiz, arvore *Suc, int *H, void (*apaga)(void *)){
    if (Suc->esq == NULL){
        arvore *Temp = Suc->dir;
        apaga(raiz->chave);
        raiz->chave = Suc->chave;
        free(Suc);
        *H = 1;
        return Temp;
    }
    Suc->esq = sucessor(raiz, Suc->esq, H, apaga);
    if (*H == 1){
        switch (Suc->fb){
        case -1:
            Suc = BalanceiaPEsq(Suc, H);
            break;
        case 0:
            Suc->fb = -1;
            *H = 0;
            break;
        case 1:
            Suc->fb = 0;
            break;
        }
    }
    return Suc;
}

void imprime(arvore *raiz, int espacos, void (*printar)(void *)){
    if (raiz == NULL){
        return;
    }

    imprime(raiz->dir, espacos + 1, printar);

    int i;
    for (i = 0; i < espacos; i++){
        printf("    ");
    }
    printar(raiz->chave);
    printf("  fb=%d\n", raiz->fb);
    imprime(raiz->esq, espacos + 1, printar);
}

arvore *BuscaNo(arvore *raiz, void *dado, int (*diferenca)(void *, void *)){
    while (raiz != NULL){
        if (diferenca(dado, raiz->chave) == 0){
            break;
        }
        if (diferenca(dado, raiz->chave) > 0){
            raiz = raiz->dir;
        }
        else{
            raiz = raiz->esq;
        }
    }
    return raiz;
}

void LiberaArvore(arvore *raiz, void (*cb)(void*)){
    if(raiz == NULL) return;
    LiberaArvore(raiz->esq, cb);
    LiberaArvore(raiz->dir, cb);
    cb(raiz->chave);
    free(raiz);
}