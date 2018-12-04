#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {

    cout << "Projeto de Grafo" << endl;

    Grafo<char> *meuGrafo = new Grafo<char>(DIRIGIDO);

    meuGrafo->adicionarVertice('A');
    //meuGrafo->adicionarVertice('A'); exceção
    meuGrafo->adicionarVertice('B');
    meuGrafo->adicionarVertice('C');
    meuGrafo->adicionarVertice('D');

    cout << *meuGrafo << endl << endl;

    meuGrafo->adicionarAresta('A', 'B', 5);
    meuGrafo->adicionarAresta('A', 'D', 10);

    meuGrafo->adicionarAresta('C', 'D', 15);
    //meuGrafo->adicionarAresta('D', 'C'); // lançar excessão quando grafo é DIRIGIDO
    cout << *meuGrafo << endl;
    // remover os vertices
    meuGrafo->removerVertice('A');
    meuGrafo->removerVertice('B');
    meuGrafo->removerVertice('C');
    meuGrafo->removerVertice('D');

    cout << *meuGrafo << endl;
    return 0;
}