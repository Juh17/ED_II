#include <iostream>
#include "./arv.hpp"

using namespace std;


int f (Arv J) {
    if(J->dir == NULL && J->esq == NULL) return 1;
    int esq =  f(J->esq);
    int dir = f(J->dir);
    return esq + dir;
}


int main () {
    Arv Juh = criarArv(criarArv(criarArv(NULL, 'd', NULL), 'b', criarArv(NULL, 'e', NULL)) , 'a', criarArv(criarArv(NULL, 'f', NULL), 'c', criarArv(NULL, 'g', NULL)));

    int qtd_folhas = f(Juh);
    cout << "Folhas: "<< qtd_folhas << endl;

