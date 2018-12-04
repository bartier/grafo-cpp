template<typename T>
Grafo<T>::Grafo(TipoGrafo tipo) {
    this->arestas = new MatrizEsparsa<int>(10, 10, -1);
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
    auto parVerticeIndice = this->indicesDosVertices->find(vertice);
    int linha = parVerticeIndice->second;

    this->indicesDosVertices->erase(vertice);

    for (int i = 0; i < 10; ++i) { // 100 posicoes fixas na matriz (limite de 100 vertices)
        this->arestas->set(linha, i, -1);
    }
}

template<typename T>
void Grafo<T>::adicionarAresta(T origem, T destino, int peso) {
    auto origemIterator = this->indicesDosVertices->find(origem);
    auto destinoIterator = this->indicesDosVertices->find(destino);

    if (origemIterator != this->indicesDosVertices->end() && destinoIterator != this->indicesDosVertices->end()) {
        this->arestas->set(origemIterator->second, destinoIterator->second, peso);

        if (this->tipo == NAO_DIRIGIDO) { // o peso do caminho de IDA  eh o mesmo do de VOLTA
            this->arestas->set(destinoIterator->second, origemIterator->second, peso);
        }
    } else {
        throw std::invalid_argument("Par de vertices invalidos para adicionar aresta");
    }
}

template<typename T>
void Grafo<T>::removerAresta(T origem, T destino) {
    auto origemIterator = this->indicesDosVertices->find(origem);
    auto destinoIterator = this->indicesDosVertices->find(destino);

    if (origemIterator != this->indicesDosVertices.end() && destinoIterator != this->indicesDosVertices.end()) {
        this->arestas->set(origemIterator->second, destinoIterator->second, -1); // -1 eh valorPadrao na matriz

        if (this->tipo == NAO_DIRIGIDO) {
            this->arestas->set(destinoIterator->second, origemIterator->second, -1); // -1 eh valorPadrao na matriz
        }
    } else {
        throw std::invalid_argument("Par de vertices invalidos para remover aresta");
    }
}

template<class U>
std::ostream &operator<<(std::ostream & os, Grafo<U> grafo) {
    os << "Vertices: {" << std::endl;

    for (auto it = grafo.indicesDosVertices->begin(); it != grafo.indicesDosVertices->end(); ++it)
        os << "  " << it->first << ": " << it->second << std::endl;

    os << "}" << std::endl;

    auto matrizDeArestas = grafo.arestas;
    os << "Matriz de arestas: " << *matrizDeArestas << std::endl;
}
