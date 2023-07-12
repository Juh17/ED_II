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


int estr_bin(No* n) {
    if (n == NULL) return 1;
    if (n->esq == NULL && n->dir == NULL) return 1;
    if (n->esq == NULL || n->dir == NULL) return 0;

    return estr_bin(n->esq) && estr_bin(n->dir);
}

int main() {
    No* j = criarNo(1);
    j->esq = criarNo(2);
    j->dir = criarNo(3);
    j->esq->esq = criarNo(4);
    j->esq->dir = criarNo(5);
    j->dir->esq = criarNo(6);
    j->dir->dir = criarNo(7);
    j->dir->dir->esq = criarNo(8);


    if (estr_bin(j))
        cout<<"Esta arvore eh estritamente binaria."<<endl;
    else
        cout<<"Esta arvore nao eh estritamente binaria."<<endl;

    return 0;
}
