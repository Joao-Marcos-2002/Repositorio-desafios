# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++11 -I./include

# Diretórios de origem e binário
SRCDIR = src
BINDIR = bin

# Lista de arquivos-fonte
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Nome do executável a ser gerado
TARGET = $(BINDIR)/pa6.out

# Regra principal para construir o diretório "bin" e o executável
all: $(BINDIR) $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(TARGET): $(SRCS) include/graph.cpp include/listaAdjacencia.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) include/graph.cpp include/listaAdjacencia.cpp

# Regra para limpar o executável
clean:
	rm -f $(TARGET)

.PHONY: all clean
