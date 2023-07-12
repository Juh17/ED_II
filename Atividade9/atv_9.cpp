#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

typedef struct arv {
    char info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv* criarNo(char info, Arv* esq = NULL, Arv* dir = NULL) {
    Arv* n = new Arv;
    n->info = info;
    n->esq = esq;
    n->dir = dir;
    return n;
}

int nos(Arv *J) {
    if(J == NULL) return 0;
    else
        return 1 + nos(J->esq) + nos(J->dir);
}

int alt(Arv *J) {
    if(J == NULL) return -1;
    else {
        int e = alt(J->esq);
        int d = alt(J->dir);
        if(e > d)
            return e + 1;
        else
            return d + 1;
    }
}

bool arvCompleta(Arv* J) {
    queue<Arv*> no;
    no.push(J);

    int nivel_inicial = 0;
    int nos_nivel = 1;
    bool nivel_final = false;

    while (!no.empty()) {
        Arv* n = no.front();
        no.pop();

        nos_nivel--;

        if (n->esq != NULL) {
            no.push(n->esq);
        }

        if (n->dir != NULL) {
            no.push(n->dir);
        }

        if (nos_nivel == 0) {
            if (nivel_final) {
                if (!no.empty()) {
                    return false;
                }
            } else {
                nivel_inicial++;
                nos_nivel = no.size();
                if (nos_nivel != pow(2, nivel_inicial)) {
                    nivel_final = true;
                }
            }
        }
    }

    return true;
}


int main() {

    Arv* j = criarNo('a');
    j->esq = criarNo('b');
    j->dir = criarNo('c');
    j->esq->esq = criarNo('d');
    j->esq->dir = criarNo('e');
    j->dir->esq = criarNo('f');
    j->dir->dir = criarNo('g');


    if (arvCompleta(j)) cout << "Arvore Binaria Completa!" << endl;
    else cout << "Arvore Binaria Incompleta!" << endl;

}
