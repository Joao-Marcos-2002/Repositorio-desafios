#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa vetop
# Autor		: João Marcos Ribeiro Tolentino (joao2002@ufmg.br)
# Histórico	: 2023-09-23 - arquivo criado
#---------------------------------------------------------------------
# Opções	: 
# 			  make run para executar o programa e medir o tempo de relógio
#             make gprof para gerar os resultados do gprof
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------



CC = g++
CFLAGS = -Wall -pg -Iinclude
LDFLAGS = -pg -lm


SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin


SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))


EXE = $(BIN_DIR)/main

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXE) gmon.out

run: $(EXE)
	./$(EXE)

gprof: run
	gprof $(EXE) gmon.out

.PHONY: all clean run gprof