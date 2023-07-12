#include <iostream>
#include "./arv.hpp"

using namespace std;


int alt(Arv J) {
    if(J == NULL) return 0;
    int esq =  alt(J->esq);
    int dir = alt(J->dir);
    if(esq > dir) return 1 + esq;
    return  1 + dir;
}


int main () {

    Arv Juh = criarArv(criarArv(criarArv(NULL, 'd', NULL), 'b', criarArv(NULL, 'e', NULL)) , 'a', criarArv(NULL, 'c', criarArv(NULL, 'f', NULL)));
    int a = alt(Juh);
    cout << "Altura: "<< a << endl;
}
