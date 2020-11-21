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
#subBINS = $(foreach dir, $(DIRS), $(addprefix $(BIN)/, $(dir)))

#Declarando diretórios dos cabeçalhos para cada sub-diretório.
INCLUDES = $(foreach dir, $(INCpaths), $(addprefix -I, $(dir)))

VPATH = $(SRC/..)

#Busca arquivos ".cpp" em cada diretório dentro de SRC.
SOURCES = $(foreach dir, $(SRCpaths), $(wildcard $(dir)/*.cpp))

#Compilação principal
all: $(PROG)

$(PROG): $(SOURCES:.cpp=.o)
	$(CXX) -o $@ $^

#Compilação das classes em arquivos-objetos ".o"
%.o: %.cpp
	$(CXX) -c $< $(INCLUDES) -o $@


-include $(SOURCES:.cpp=.d)

%.d: %.cpp
	$(CXX) $< -MM -MT '*.o *.d' -MD $(INCLUDES)

#Tarefa para limpeza de arquivos...
clean:
	@-rm -f *.d $(PROG)
	@find . -name "*.o" -type f -delete
	@echo Limpando Arquivos da compilação...