#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {

    cout << "Projeto de Grafo" << endl;

    Grafo<char> *meuGrafo = new Grafo<char>(DIRIGIDO);

    meuGrafo->adicionarVertice('A');
    meuGrafo->adicionarVertice('A');
    meuGrafo->adicionarVertice('B');
    meuGrafo->adicionarVertice('C');
    meuGrafo->adicionarVertice('D');

//    meuGrafo->adicionarAresta('A', 'B');
//    meuGrafo->adicionarAresta('A', 'D');
//    meuGrafo->adicionarAresta('C', 'D');
//    //meuGrafo->adicionarAresta('D', 'C'); // lançar excessão quando grafo é DIRIGIDO
//
//    // remover os vertices remove automaticamente as arestas relacionadas
//    meuGrafo->removerVertice('A');
//    meuGrafo->removerVertice('B');
//    meuGrafo->removerVertice('C');
//    meuGrafo->removerVertice('D');
    return 0;
}