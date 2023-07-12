#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct arv {
	struct arv *dir;
	char item;
    struct arv *esq;
} *Arv;

Arv criarArv(Arv e, char item, Arv d){
	Arv n = (Arv)malloc(sizeof(arv));
	n->esq = e;
	n->item = item;
	n->dir = d;
	return n;
}

void emOrdem(Arv J) {
    if(J == NULL) return;
    emOrdem(J->esq);
    cout << J->item << endl;
    emOrdem(J->dir);
}
void preOrdem(Arv J) {
    if(J == NULL) return;
    cout << J->item << endl;
    emOrdem(J->esq);
    emOrdem(J->dir);
}
void posOrdem(Arv J) {
    if(J == NULL) return;
    emOrdem(J->esq);
    emOrdem(J->dir);
    cout << J->item << endl;
}

void destroiArv(Arv *J) {
    if(*J == NULL) return;
    destroiArv(&(*J)->esq);
    destroiArv(&(*J)->dir);
    free(*J);
    *J = NULL;

}
