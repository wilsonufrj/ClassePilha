#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "Pilha.hpp"

using namespace std;

class TorreHanoi {
 private:
  Pilha<int, 10> pinos[3];
  int num_discos;
  int movimentos;
  int passos_por_visualizacao;
  const string nomes[3] = {"Inicial", "Auxiliar", "Destino"};

  void mover_disco(int origem, int destino) {
    if (pinos[origem].pilha_esta_vazia()) {
      throw runtime_error("Tentativa de mover de pino vazio");
    }

    if (!pinos[destino].pilha_esta_vazia() &&
        pinos[origem].topo_pilha() > pinos[destino].topo_pilha()) {
      throw runtime_error("Violação da regra: disco maior sobre menor");
    }

    int disco = pinos[origem].desempilha();
    pinos[destino].empilha(disco);
    movimentos++;

    if (movimentos % passos_por_visualizacao == 0 ||
        movimentos == (1 << num_discos) - 1) {
      visualizar();
      cout << "Movimentos acumulados: " << movimentos << endl;
      cout << "Pressione ENTER para continuar...";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  void resolver_recursivo(int n, int origem, int destino, int auxiliar) {
    if (n == 0) return;

    resolver_recursivo(n - 1, origem, auxiliar, destino);
    mover_disco(origem, destino);
    resolver_recursivo(n - 1, auxiliar, destino, origem);
  }

  string criar_linha_disco(int tamanho) const {
    return numero_para_hashes(tamanho) + "|" + numero_para_hashes(tamanho);
  }

  string numero_para_hashes(int n) const {
    if (n <= 0) {
      return "";
    }
    return std::string(n, '#');
  }

 public:
  TorreHanoi(int n, int passos = 1)
      : num_discos(n), movimentos(0), passos_por_visualizacao(passos) {
    if (n > 10) {
      throw invalid_argument("Numero maximo de discos e 10");
    }

    for (int i = n; i >= 1; --i) {
      pinos[0].empilha(i);
    }
  }

  void resolver() {
    visualizar();
    cout << "Pressione ENTER para comecar a resolucao...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    resolver_recursivo(num_discos, 0, 2, 1);

    cout << "Resolucao completa em " << movimentos << " movimentos!" << endl;
  }

  void visualizar() const {
    system("clear || cls");

    cout << "Posição " << (movimentos == 0 ? "Inicial" : "Atual") << ": "
         << movimentos << (movimentos == 1 ? " passo" : " passos") << endl
         << endl;

    int altura_maxima =
        max({pinos[0].tamanho(), pinos[1].tamanho(), pinos[2].tamanho()});
    altura_maxima = max(altura_maxima, 1);

    for (int p = 0; p < 3; p++) {
      cout << "[";

      for (int d = pinos[p].tamanho() - 1; d >= 0; d--) {
        cout << pinos[p].get_elementos()[d];
        if (d > 0) cout << " ";
      }

      cout << "] ";

      switch (p) {
        case 0:
          cout << "Inicial";
          break;
        case 1:
          cout << "Intermediário";
          break;
        case 2:
          cout << "Final";
          break;
      }

      cout << endl;
    }

    cout << endl;
  }
};