# Torre de Hanói em C++

Este projeto implementa o clássico quebra-cabeça da Torre de Hanói em C++. Ele permite ao usuário definir o número de discos e visualiza a solução passo a passo ou em intervalos definidos pelo usuário.

## Processo de Desenvolvimento

### Estruturas de Dados

A principal estrutura de dados utilizada neste projeto é a **pilha (stack)**, implementada na classe `Pilha<T, tamanho_max>` no arquivo `Pilha.hpp`.

*   Cada um dos três pinos da Torre de Hanói é representado por uma instância de `Pilha<int, 10>`.
*   Os discos são representados por números inteiros, onde um número menor representa um disco menor.
*   A pilha é implementada utilizando um array de tamanho fixo (`elementos[tamanho_max]`), o que significa que o número máximo de discos é pré-determinado pela constante `tamanho_max` (definida como 10 no contexto da `TorreHanoi`).
*   As operações padrão de pilha são fornecidas:
    *   `empilha(T dado)`: Adiciona um elemento ao topo.
    *   `desempilha()`: Remove e retorna o elemento do topo.
    *   `topo_pilha()`: Retorna o elemento do topo sem removê-lo.
    *   `pilha_esta_vazia()`: Verifica se a pilha está vazia.
    *   `pilha_esta_cheia()`: Verifica se a pilha está cheia.
    *   `tamanho()`: Retorna o número de elementos na pilha.

### Divisão de Módulos

O projeto é dividido nos seguintes arquivos:

*   **`Pilha.hpp`**:
    *   Contém a implementação de uma classe de pilha genérica (`Pilha`).
    *   Esta pilha é usada para representar os pinos na Torre de Hanói.
    *   É um componente reutilizável que poderia ser usado em outras aplicações que necessitem de uma estrutura de pilha simples baseada em array.

*   **`TorreHanoi.cpp`**:
    *   Contém a classe `TorreHanoi`, que encapsula toda a lógica do jogo.
    *   Responsável por inicializar os pinos, mover os discos de acordo com as regras, implementar o algoritmo de solução recursivo e visualizar o estado do jogo no console.
    *   Utiliza a classe `Pilha` para gerenciar os discos em cada pino.

*   **`teste.cpp`**:
    *   Serve como o ponto de entrada principal da aplicação (função `main`).
    *   Interage com o usuário para obter o número de discos e a frequência de visualização dos passos.
    *   Cria uma instância de `TorreHanoi` e inicia o processo de resolução.
    *   Inclui tratamento básico de exceções.

### Descrição das Rotinas e Funções

Principais rotinas e funções do sistema:

**Classe `Pilha<T, tamanho_max>` (`Pilha.hpp`)**

*   `Pilha()`: Construtor, inicializa a pilha como vazia.
*   `void empilha(T dado)`: Adiciona `dado` ao topo da pilha. Lança `std::out_of_range` se a pilha estiver cheia.
*   `T desempilha()`: Remove e retorna o `dado` do topo da pilha. Lança `std::out_of_range` se a pilha estiver vazia.
*   `bool pilha_esta_vazia() const`: Retorna `true` se a pilha não contém elementos, `false` caso contrário.
*   `bool pilha_esta_cheia() const`: Retorna `true` se a pilha atingiu sua capacidade máxima, `false` caso contrário.
*   `T topo_pilha() const`: Retorna o elemento no topo da pilha sem removê-lo. Lança `std::out_of_range` se a pilha estiver vazia.
*   `int tamanho() const`: Retorna o número atual de elementos na pilha.
*   `std::ostream& operator<<(std::ostream& os, const Pilha<T, tamanho_max>& p)`: Sobrecarga do operador de inserção para permitir a impressão do conteúdo da pilha.
*   `void troca()`: Troca os dois elementos do topo da pilha (não utilizado na lógica principal da Torre de Hanói).
*   `const T* get_elementos() const`: Retorna um ponteiro para o array interno de elementos (usado pela visualização em `TorreHanoi`).

**Classe `TorreHanoi` (`TorreHanoi.cpp`)**

*   `TorreHanoi(int n, int passos = 1)`: Construtor. Inicializa o jogo com `n` discos no pino de origem. `passos` define a frequência de visualização. Lança `std::invalid_argument` se `n > 10`.
*   `void mover_disco(int origem, int destino)`: Move um disco do pino `origem` para o pino `destino`. Verifica a validade do movimento (pino de origem não vazio, disco maior não pode ser colocado sobre menor). Incrementa a contagem de movimentos e chama `visualizar()` conforme a frequência definida.
*   `void resolver_recursivo(int n, int origem, int destino, int auxiliar)`: Implementa o algoritmo recursivo padrão para resolver a Torre de Hanói.
    1.  Move `n-1` discos do pino `origem` para o pino `auxiliar`, usando `destino` como temporário.
    2.  Move o `n`-ésimo disco do pino `origem` para o pino `destino`.
    3.  Move `n-1` discos do pino `auxiliar` para o pino `destino`, usando `origem` como temporário.
*   `void visualizar() const`: Limpa o console e exibe o estado atual dos três pinos, mostrando os discos em cada um. Também exibe o número de movimentos.
*   `void resolver()`: Inicia o processo de resolução. Exibe o estado inicial, aguarda o usuário e então chama `resolver_recursivo()`. Ao final, mostra o total de movimentos.
*   `string criar_linha_disco(int tamanho) const`: (Não diretamente chamada, mas estrutura similar é usada em `visualizar` implicitamente) Função auxiliar para formatação da visualização dos discos (não presente explicitamente com este nome no código fornecido, mas a lógica de exibição de discos está em `visualizar`).
*   `string numero_para_hashes(int n) const`: (Não diretamente chamada, mas estrutura similar é usada em `visualizar` implicitamente) Função auxiliar para formatação da visualização dos discos (não presente explicitamente com este nome no código fornecido, mas a lógica de exibição de discos está em `visualizar`).

**`teste.cpp`**

*   `int main()`: Ponto de entrada do programa. Solicita ao usuário o número de discos e a frequência de visualização. Cria um objeto `TorreHanoi` e chama `resolver()` para iniciar a solução. Captura e trata exceções.

### Complexidade de Tempo e Espaço

*   **Complexidade de Tempo:**
    *   A solução para o problema da Torre de Hanói requer um mínimo de **O(2<sup>n</sup> - 1)** movimentos, onde `n` é o número de discos. Portanto, a complexidade de tempo do algoritmo `resolver_recursivo` é **O(2<sup>n</sup>)**, pois cada chamada recursiva resulta em operações de tempo constante (movimentação de disco, verificações).
    *   As operações da pilha (`empilha`, `desempilha`, `topo_pilha`) são todas **O(1)** (tempo constante), pois são acessos diretos a elementos de um array.

*   **Complexidade de Espaço:**
    *   **Pilha de Recursão:** A profundidade máxima da pilha de recursão para `resolver_recursivo` é `n`. Portanto, o espaço consumido pela pilha de chamadas é **O(n)**.
    *   **Armazenamento dos Discos:** Os três pinos (pilhas) armazenam um total de `n` discos. Se considerarmos `tamanho_max` como uma constante (10), o espaço para os discos é O(1) em termos de `tamanho_max`. No entanto, em relação ao número de discos `n` efetivamente utilizados, o espaço é **O(n)**.
    *   A complexidade de espaço geral do algoritmo é dominada pelo maior desses fatores, sendo portanto **O(n)**.

### Problemas e Observações Encontrados Durante o Desenvolvimento

*   **Limite Fixo de Discos:** A classe `Pilha` é implementada com um array de tamanho fixo (`template <typename T, int tamanho_max>`). Na classe `TorreHanoi`, isso é instanciado como `Pilha<int, 10>`, limitando o jogo a um máximo de 10 discos. Uma melhoria seria usar uma estrutura de dados dinâmica (como `std::vector`) para a pilha, permitindo um número arbitrário de discos (limitado apenas pela memória).
*   **Método `troca()` não Utilizado:** A classe `Pilha` possui um método `troca()` que inverte os dois elementos do topo. Este método não é utilizado pela lógica da Torre de Hanói e poderia ser removido se a pilha for específica para este problema, ou mantido se a intenção é uma pilha de propósito mais geral.
*   **Limpeza de Tela Dependente do Sistema:** A função `visualizar()` em `TorreHanoi.cpp` usa `system("clear || cls")` para limpar o console. O comando `clear` é para sistemas baseados em Unix (Linux, macOS) e `cls` é para Windows. Embora o `||` tente executar o segundo se o primeiro falhar, isso pode não ser universalmente portátil ou pode ser considerado uma prática de segurança ruim em alguns contextos. Uma abordagem mais portável para manipulação de console seria usar bibliotecas como ncurses (para Unix-like) ou a API do Console do Windows, ou simplesmente imprimir novas linhas suficientes para "empurrar" o conteúdo antigo para fora da tela visível.
*   **Interatividade na Visualização:** O programa pausa a execução (`cin.ignore(...)`) após cada visualização (ou conjunto de visualizações, dependendo de `passos_por_visualizacao`). Isso é bom para a observação, mas para um grande número de discos e `passos_por_visualizacao = 1`, pode ser tedioso pressionar Enter repetidamente.
*   **Nomes dos Pinos na Visualização:** Na função `visualizar`, os pinos são nomeados "Inicial", "Intermediário" e "Final". No entanto, na função `resolver_recursivo` e `mover_disco`, eles são referenciados por índices (0, 1, 2), e os nomes "Inicial", "Auxiliar", "Destino" são usados nos parâmetros da função recursiva e em um array `nomes` não utilizado na visualização diretamente. A consistência poderia ser melhorada, embora a visualização atual seja clara.
*   **Inclusão de `.cpp`:** O arquivo `teste.cpp` inclui `TorreHanoi.cpp` (`#include "TorreHanoi.cpp"`). Geralmente, em C++, inclui-se arquivos de cabeçalho (`.hpp` ou `.h`) e compila-se os arquivos `.cpp` separadamente, ligando-os depois. Incluir um `.cpp` diretamente pode levar a problemas de múltiplas definições se `TorreHanoi.cpp` fosse incluído em outros lugares, embora funcione para este projeto simples. A prática padrão seria criar `TorreHanoi.hpp` com as declarações da classe e incluir este em `teste.cpp` e `TorreHanoi.cpp`.

## Conclusão sobre os Resultados Obtidos

O programa implementa com sucesso uma solução para o quebra-cabeça da Torre de Hanói em C++. Os principais resultados e funcionalidades obtidas são:

*   **Solução Funcional:** O algoritmo recursivo clássico resolve corretamente o problema para um número `n` de discos especificado pelo usuário (limitado a 10).
*   **Visualização Passo a Passo:** O estado dos pinos e o número de movimentos são exibidos no console, permitindo ao usuário acompanhar o processo de solução. A frequência dessa visualização pode ser controlada pelo usuário.
*   **Estruturação em Classes:** O uso das classes `Pilha` e `TorreHanoi` organiza o código de forma modular, separando a estrutura de dados genérica da lógica específica do jogo.
*   **Interação com o Usuário:** O programa solicita informações básicas ao usuário (número de discos, frequência de visualização) para configurar a execução.

O projeto serve como uma boa demonstração da aplicação de recursão e do uso de estruturas de dados como pilhas para resolver problemas algorítmicos. A complexidade exponencial O(2<sup>n</sup>) é inerente ao problema da Torre de Hanói, e o programa reflete isso: o tempo de execução torna-se significativamente longo para números maiores de discos (por exemplo, acima de 20-25, embora o limite atual seja 10).

As observações listadas na seção anterior destacam pontos onde o projeto poderia ser estendido ou refinado, como o uso de estruturas de dados dinâmicas para remover o limite de discos ou a melhoria da portabilidade da limpeza de tela. No geral, o programa atinge seus objetivos de resolver e visualizar a Torre de Hanói.
