#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct arv {
	char info;
	struct arv *esq;
	struct arv *dir;
} Arv;

Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;
}

bool ArvBinCheia(Arv *j) {
    if (j == NULL) return true;
    if (j->esq == NULL && j->dir == NULL) return true;

    if (j->esq != NULL && j->dir != NULL) {
        return ArvBinCheia(j->esq) && ArvBinCheia(j->dir);
    }

   return false;
}

int main() {
  	Arv *Juh = arvore('c', arvore('e',  arvore('b', NULL, NULL), arvore('d', NULL, NULL)), arvore('a', NULL, NULL));

    if(ArvBinCheia(Juh)) cout << "Arvore Cheia!";
    else cout << "Arvore Vazia!";
}
