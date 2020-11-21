#Makefile para "PetFera" em C++
#Feito por Lauro Bezerra (16/11/2020)

#Arquivos "Raízes" para distribuição em diretórios.
BIN = ./bin
SRC = ./src
INC = ./include

#Definições gerais: Nome do Executável Main e Flags do compilador.
PROG = petFera	#Nome do executável gerado.
CXX = g++
CXXFLAGS = -O0 -g -Wall -std=c++11

#ATENÇÃO: Sub-Diretórios (DEVE SER IGUAL EM SRC E INCLUDE);
DIRS = . funcionarios
#Busca de arquivos .hpp e .cpp nos sub-diretórios.
SRCpaths = $(foreach dir, $(DIRS), $(addprefix $(SRC)/, $(dir)))
INCpaths = $(foreach dir, $(DIRS), $(addprefix $(INC)/, $(dir)))
BINpaths = $(foreach dir, $(DIRS), $(addprefix $(BIN)/, $(dir)))

#Declarando diretórios dos cabeçalhos para cada sub-diretório.
INCLUDES = $(foreach dir, $(INCpaths), $(addprefix -I, $(dir)))

VPATH = $(SRC/..)

#Busca arquivos ".cpp" em cada diretório dentro de SRC.
SOURCES = $(foreach dir, $(SRCpaths), $(wildcard $(dir)/*.cpp))

#Compilação principal
all: $(PROG)

$(PROG): $(SOURCES:.cpp=.o)
	@echo Linkando os arquivos no executável: $@
	@$(CXX) -o $@ $^

#Compilação das classes em arquivos-objetos ".o"
%.o: %.cpp
	@echo Compilando a classe: $@
	@$(CXX) -c $< $(INCLUDES) -o $@


-include $(SOURCES:.cpp=.d)

%.d: %.cpp
	@$(CXX) $< -MM -MT '$*.o $*.d' -o $*.d $(INCLUDES)

#Tarefa para limpeza de arquivos...
clean:
	@-rm -f *.d $(PROG)
	@find . -name "*.o" -type f -delete
	@find . -name "*.d" -type f -delete
	@echo Limpando Arquivos da compilação...