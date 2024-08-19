#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-18 - arquivo criado
#		: 2021-10-21 - estrutura de diretórios
#               : 2021-11-15 - Versao 1.1 memlog
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/matop.o $(OBJ)/mat.o 
HDRS = $(INC)/mat.h $(INC)/msgassert.h
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/matop

all: $(EXE)
#all:  mem perf gprof

mem: $(EXE)
	$(EXE) -s -p /tmp/somalog.out -l -x 4 -y 5
	$(EXE) -m -p /tmp/multlog.out -l -x 5 -y 5
	$(EXE) -t -p /tmp/transplog.out -l -x 5 -y 4
	$(EXE) -c /tmp/out.txt -p /tmp/transplog.out -l -x 5 -y 4

perf: $(EXE)
	$(EXE) -s -p /tmp/soma100.out  -x 100 -y 100
	$(EXE) -m -p /tmp/mult100.out  -x 100 -y 100
	$(EXE) -t -p /tmp/transp100.out  -x 100 -y 100
	$(EXE) -s -p /tmp/soma200.out  -x 200 -y 200
	$(EXE) -m -p /tmp/mult200.out  -x 200 -y 200
	$(EXE) -t -p /tmp/transp200.out  -x 200 -y 200
	$(EXE) -s -p /tmp/soma300.out  -x 300 -y 300
	$(EXE) -m -p /tmp/mult300.out  -x 300 -y 300
	$(EXE) -t -p /tmp/transp300.out  -x 300 -y 300
	$(EXE) -s -p /tmp/soma400.out  -x 400 -y 400
	$(EXE) -m -p /tmp/mult400.out  -x 400 -y 400
	$(EXE) -t -p /tmp/transp400.out  -x 400 -y 400
	$(EXE) -s -p /tmp/soma500.out  -x 500 -y 500
	$(EXE) -m -p /tmp/mult500.out  -x 500 -y 500
	$(EXE) -t -p /tmp/transp500.out  -x 500 -y 500
	$(EXE) -m -p /tmp/mult100log.out -l -x 100 -y 100

gprof: $(BIN)/matop
	$(EXE) -s -p /tmp/soma500gprof.out  -x 500 -y 500
	gprof $(EXE) gmon.out > /tmp/soma500gprof.txt
	$(EXE) -m -p /tmp/mult500gprof.out  -x 500 -y 500
	gprof $(EXE) gmon.out > /tmp/mult500gprof.txt
	$(EXE) -t -p /tmp/transp500gprof.out  -x 500 -y 500
	gprof $(EXE) gmon.out > /tmp/transp500gprof.txt
	

$(BIN)/matop: $(OBJS)
	$(CC) -g -o $(BIN)/matop $(OBJS) $(LIBS)

$(OBJ)/matop.o: $(HDRS) $(SRC)/matop.c
	$(CC) $(CFLAGS) -o $(OBJ)/matop.o $(SRC)/matop.c 

$(OBJ)/mat.o: $(HDRS) $(SRC)/mat.c
	$(CC) $(CFLAGS) -o $(OBJ)/mat.o $(SRC)/mat.c 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
