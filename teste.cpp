#include <iostream>

#include "TorreHanoi.cpp"

int main() {
  try {
    int num_discos, passos;

    cout << "Torre de Hanoi" << endl;
    cout << "Digite o numero de discos (max 10): ";
    cin >> num_discos;

    cout << "Digite quantos movimentos mostrar entre cada visualizacao (1 para "
            "passo a passo): ";
    cin >> passos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    TorreHanoi torreHanoi(num_discos, passos);
    torreHanoi.visualizar();
    torreHanoi.resolver();

  } catch (const exception& e) {
    cerr << "Erro: " << e.what() << endl;
    return 1;
  }

  return 0;
}