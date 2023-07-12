#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
}Arv;


Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;

}

void imprime(Arv *n){

			if (n!=NULL){

				cout<<"<"<<n->info;
				imprime(n->esq);
				imprime(n->dir);
				cout<<">";
			   }
			   else
			     cout<<"<>";
}


int calculaQuantNos(Arv *no){
        if(no == NULL) return 0;
        int esq = calculaQuantNos(no->esq);
        int dir = calculaQuantNos(no->dir);

        return esq + 1 + dir;
}


int calculaQuantNosFolha(Arv *no){
        if(no->dir == NULL && no->esq == NULL) return 1;
        int esq = calculaQuantNosFolha(no->esq);
        int dir = calculaQuantNosFolha(no->dir);
        return esq + dir;
}



int alturaArvore(Arv *no){
       if(no == NULL) return 0;
       int esq =  alturaArvore(no->esq);
       int dir = alturaArvore(no->dir);
       if(esq > dir) return 1 + esq;
       return  1 + dir;
}

Arv* procura(Arv *no, char valor){
        while(no) {
        if(valor < no->info)
           no = no->esq;
        else if(valor > no->info)
           no = no->dir;
        else
            return no;
    }
        return NULL;
}

void removeSubArvore(Arv **no, char valor){
         if (*no == NULL) return ;

         if ((*no)->info > valor) {
             removeSubArvore(&((*no)->esq), valor);
         } else if ((*no)->info < valor) {
             removeSubArvore(&((*no)->dir), valor);
         } else {

                Arv *aux;

                if ((*no)->esq == NULL) {
                     aux = *no;
                     *no = (*no)->dir;
                     free(aux);

                } else if ((*no)->dir == NULL) {
                     aux = *no;
                     *no = (*no)->esq;
                     free(aux);
                } else {
                     aux = (*no)->dir;

                     while (aux->esq != NULL) {
                        aux = aux->esq;
                      }

                     (*no)->info = aux->info;
                     removeSubArvore(&((*no)->dir), aux->info);
        }
    }
}



int main(){
      Arv *a = arvore('a',NULL,NULL);
      Arv *b = arvore('b',0,0);
      Arv *c = arvore('c',0,0);

     a->esq = b;
     a->dir = c;

    imprime(a);
    removeSubArvore(&a, 'c');
    cout << endl;
    imprime(a);

    return 0;
}
