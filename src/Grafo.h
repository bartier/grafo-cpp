#ifndef GRAFO_CPP_GRAFO_H
#define GRAFO_CPP_GRAFO_H

#include <iostream>
#include <map>
#include "../matriz-esparsa-cpp/src/MatrizEsparsa.h"

enum TipoGrafo {
    DIRIGIDO,    // SÓ UMA DIREÇÃO
    NAO_DIRIGIDO // VAI e VOLTA
};

template <typename T>
class Grafo {
public:
    Grafo(TipoGrafo tipo);

    void adicionarVertice(T vertice);
    void removerVertice(T vertice);

    void adicionarAresta(T origem, T destino, int peso);
    void removerAresta(T origem, T destino);

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, Grafo<U> grafo);

private:
    TipoGrafo tipo;
    std::map<T, int> *indicesDosVertices;
    int indiceAtual;
    MatrizEsparsa<int> *arestas;
};



#include "Grafo.inl"

#endif //GRAFO_CPP_GRAFO_H
