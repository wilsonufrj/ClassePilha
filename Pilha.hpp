#include <iostream>
#include <stdexcept>

template <typename T, int tamanho_max>
class Pilha {
 private:
  T elementos[tamanho_max];
  int topo;

 public:
  Pilha() : topo(-1) {}

  void empilha(T dado) {
    if (pilha_esta_cheia()) {
      throw std::out_of_range("Pilha cheia!");
    }
    elementos[++topo] = dado;
  }

  T desempilha() {
    if (pilha_esta_vazia()) {
      throw std::out_of_range("Pilha vazia!");
    }
    return elementos[topo--];
  }

  bool pilha_esta_vazia() const { return topo == -1; }

  bool pilha_esta_cheia() const { return topo == tamanho_max - 1; }

  T topo_pilha() const {
    if (pilha_esta_vazia()) {
      throw std::out_of_range("Pilha vazia!");
    }
    return elementos[topo];
  }

  int tamanho() const { return topo + 1; }

  friend std::ostream& operator<<(std::ostream& os,
                                  const Pilha<T, tamanho_max>& p) {
    os << "[";
    for (int i = 0; i <= p.topo; ++i) {
      os << p.elementos[i];
      if (i < p.topo) {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }

  void troca() {
    T auxPenultimo = this->elementos[tamanho() - 2];
    this->elementos[tamanho() - 2] = this->elementos[tamanho() - 1];
    this->elementos[tamanho() - 1] = auxPenultimo;
  }

  const T* get_elementos() const { return elementos; }
};