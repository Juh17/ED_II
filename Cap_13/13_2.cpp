#include <iostream>
#include "./arv.hpp"

using namespace std;

int nos(Arv J) {
    if(J == NULL) return 0;
    int esq =  nos(J->esq);
    int dir = nos(J->dir);
    return esq + 1 + dir;
}



int main () {

    Arv Juh = criarArv(criarArv(criarArv(NULL, 'd', NULL), 'b', criarArv(NULL, 'e', NULL)) , 'a', criarArv(NULL, 'c', criarArv(NULL, 'f', NULL)));
    int qtd_nos = nos(Juh);

    cout << "Nos: " <<qtd_nos << endl;
}
