#Makefile para "PetFera" em C++
#Feito por Lauro Bezerra (16/11/2020)

BIN = ./bin
SRC = ./src
INC = ./include

PROG = petFera	#Nome do executável gerado.
CC = g++
FLAGS = -O0 -g -Wall -std=c++11 -I$(INC)

#Pré-compilados para cada arquivo, deve-se incluir para cada classe.
OBJS = $(BIN)/main.o

#Compilação principal
$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

#Fazer um ".o" para cada classe em SRC.
$(BIN)/main.o : $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

#Tarefa para limpeza de arquivos...
clean:
	rm -f core $(PROG) $(OBJS)