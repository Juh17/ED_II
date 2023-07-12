#include <stdio.h>
#include <iostream>

using namespace std;

template<typename J>
struct ArvNo {
    J valor;
    ArvNo<J>* esq;
    ArvNo<J>* dir;

    ArvNo(const J& valor) : valor(valor), esq(NULL), dir(NULL) {}
};

template<typename J>
void incluir(ArvNo<J>*& r, const J& valor) {
    if (r == NULL) {
        r = new ArvNo<J>(valor);
    } else {
        if (valor < r->valor) {
            incluir(r->esq, valor);
        } else {
            incluir(r->dir, valor);
        }
    }
}

template<typename J>
void inOrder(ArvNo<J>* r) {
    if (r != NULL) {
        inOrder(r->esq);
        cout << r->valor << " ";
        inOrder(r->dir);
    }
}

template<typename J>
void preOrder(ArvNo<J>* r) {
    if (r != NULL) {
        cout << r->valor << " ";
        preOrder(r->esq);
        preOrder(r->dir);
    }
}

int main() {
    ArvNo<int>* r = NULL;

    incluir(r, 15);
    incluir(r, 5);
    incluir(r, 25);
    incluir(r, 6);
    incluir(r, 8);

    cout << "In-Order: ";
    inOrder(r);
    cout << endl;

    cout << "Pre-Order: ";
    preOrder(r);
    cout << endl;

    return 0;
}
