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
void morrisIn(ArvNo<J>* r) {
    ArvNo<J>* atual = r;
    while (atual != NULL) {
        if (atual->esq == NULL) {
            cout << atual->valor << " ";
            atual = atual->dir;
        } else {
            ArvNo<J>* ant = atual->esq;
            while (ant->dir != NULL && ant->dir != atual)
                ant = ant->dir;

            if (ant->dir == NULL) {
                ant->dir = atual;
                atual = atual->esq;
            } else {
                ant->dir = NULL;
                cout << atual->valor << " ";
                atual = atual->dir;
            }
        }
    }
}


template<typename J>
void entrada(ArvNo<J>* no) {
    cout << no->valor << " ";
}

template<typename J>
void MorrisPre(ArvNo<J>* root) {
    ArvNo<J> *p = root, *tmp;
    while (p != 0) {
        if (p->esquerda == 0) {
            entrada(p);
            p = p->dir;
        } else {
            tmp = p->esq;
            while (tmp->dir != 0 && tmp->dir != p)
                tmp = tmp->dir;

            if (tmp->dir == 0) {
                entrada(p);
                tmp->dir = p;
                p = p->esq;
            } else {
                tmp->dir = 0;
                p = p->dir;
            }
        }
    }
}


template<typename J>
void morrisPre(ArvNo<J>* r) {
    ArvNo<J>* atual = r;
    while (atual != NULL) {
        if (atual->esq == NULL) {
            cout << atual->valor << " ";
            atual = atual->dir;
        } else {
            ArvNo<J>* ant = atual->esq;
            while (ant->dir != NULL && ant->dir != atual)
                ant = ant->dir;

            if (ant->dir == NULL) {
                cout << atual->valor << " ";
                ant->dir = atual;
                atual = atual->esq;
            } else {
                ant->dir = NULL;
                atual = atual->dir;
            }
        }
    }
}



int main() {

    ArvNo<int>* r = new ArvNo<int>(10);
    r->esq = new ArvNo<int>(15);
    r->dir = new ArvNo<int>(20);
    r->esq->esq = new ArvNo<int>(25);
    r->esq->dir = new ArvNo<int>(30);

    cout << "In-Order: ";
    morrisIn(r);
    cout << endl;

    cout << "Pre-Order: ";
    morrisPre(r);
    cout << endl;

    return 0;
}
