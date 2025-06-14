# Makefile para Torre de Hanói

# Compilador
CXX = g++
# Flags de compilação
CXXFLAGS = -Wall -g

# Nome do executável
TARGET = torreHanoi

# Arquivos fonte
SOURCES = teste.cpp TorreHanoi.cpp
# Arquivos de cabeçalho
HEADERS = Pilha.hpp

# Regra padrão
all: $(TARGET)

# Regra para construir o executável
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run