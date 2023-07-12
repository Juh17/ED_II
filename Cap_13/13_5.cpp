#include <iostream>
#include "./arv.hpp"

using namespace std;


int tem(Arv J, char item) {
    if(J == NULL) return 0;
    if(J->item == item) return 1;
    int esq =  tem(J->esq, item);
    int dir = tem(J->dir , item);
    return esq + dir;
}


int main () {
    Arv Juh = criarArv(criarArv(criarArv(NULL, 'd', NULL), 'b', criarArv(NULL, 'e', NULL)) , 'a', criarArv(NULL, 'c', criarArv(NULL, 'f', NULL)));
    int qtd_folhas = tem(Juh, 6);

    if(qtd_folhas) cout << "Possui o item X"<< endl;
    else cout << "Nao possui o item X"<< endl;
}
