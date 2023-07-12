#include <iostream>
#include <string.h>
#include "./arv.hpp"

using namespace std;

int calc(int esquerda, int direita, char op) {
    if(op == '+') return esquerda + direita;
    if(op == '-') return esquerda - direita;
    if(op == '*') return esquerda * direita;

    return esquerda / direita;

}

int valor(Arv J) {
    if(J->esq == J->dir) {
        return J->item;
    } else {
        int esq = valor(J->esq);
        int dir = valor(J->dir);
        return calc(esq, dir, char(J->item));
    }
}

int main() {
    Arv Juh = criarArv(criarArv(criarArv(criarArv(NULL, 2, NULL), '+', criarArv(NULL, 4, NULL)), '/', criarArv(NULL, 3, NULL)), '*', criarArv(criarArv(NULL, 5, NULL), '-', criarArv(NULL, 1, NULL)));

    int v = valor(Juh);

    cout << "Resultado: " << v << endl;
}
