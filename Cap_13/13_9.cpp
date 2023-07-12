#include <iostream>
#include "./arv.hpp"

using namespace std;

void exibe_dec(Arv J) {
    if(J == NULL) return;
    exibe_dec(J->dir);

    cout << J->item << endl;

    exibe_dec(J->esq);
}


int main() {
    Arv Juh = criarArv(criarArv(criarArv(NULL, 1, NULL), 2, criarArv(NULL, 3, NULL)) , 4, criarArv(NULL, 5, criarArv(NULL, 6, NULL)));
    exibe_dec(Juh);
}

