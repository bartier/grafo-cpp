template<typename T>
Grafo<T>::Grafo(TipoGrafo tipo) {
    this->arestas = new MatrizEsparsa<int>(-1);
    this->indicesDosVertices = new std::map<T, int>();

    this->tipo = tipo;
    this->indiceAtual = 0;
}

template<typename T>
void Grafo<T>::adicionarVertice(T vertice) {
    auto it = this->indicesDosVertices->find(vertice);

    if (it != indicesDosVertices->end()) {
        throw std::invalid_argument("Vertice ja existente");
    }

    std::pair<T, int> par(vertice, indiceAtual++);
    this->indicesDosVertices->insert(par);
}

template<typename T>
void Grafo<T>::removerVertice(T vertice) {
    throw "implementa ae";
}

template<typename T>
void Grafo<T>::adicionarAresta(T v1, T v2) {
    throw "implementa ae";
}

template<typename T>
void Grafo<T>::removerAresta(T v1, T v2) {
    throw "implementa ae";
}

template<class U>
std::ostream &operator<<(std::ostream & os, Grafo<U> grafo) {
    return os << "implementa ae";
}
