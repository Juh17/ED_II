#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* criarNo(int valor) {
    No* n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}


int comp_arvs(No* x, No* y){
    if (x == NULL && y == NULL) return 1;
    if (x == NULL || y == NULL) return 0;
    if (x->valor != y->valor) return 0;
    return comp_arvs(x->esq, y->esq) && comp_arvs(x->dir, y->dir);
}

int main() {
    No* X = criarNo(1);
    X->esq = criarNo(2);
    X->dir = criarNo(3);
    X->esq->esq = criarNo(4);
    X->esq->dir = criarNo(5);
    X->esq->esq = criarNo(6);

    No* Y = criarNo(1);
    Y->esq = criarNo(2);
    Y->dir = criarNo(3);
    Y->esq->esq = criarNo(4);
    Y->esq->dir = criarNo(5);
    Y->dir->esq = criarNo(6);


    if (comp_arvs(X, Y))
        cout<< "As arvores sao iguais." <<endl;
    else
        cout<< "As arvores nao sao iguais." <<endl;

    return 0;
}

