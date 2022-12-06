CC := g++
DIRETORIO_SOURCE := src
DIRETORIO_OBJETOS := build
DIRETORIO_TESTES := tests
MAIN := system/main.cpp

EXTENSAO_SOURCE := cpp
SOURCES := $(shell find $(DIRETORIO_SOURCE) -type f -name *.$(EXTENSAO_SOURCE))
OBJETOS := $(patsubst $(DIRETORIO_SOURCE)/%,$(DIRETORIO_OBJETOS)/%,$(SOURCES:.$(EXTENSAO_SOURCE)=.o))
SOURCES_TESTES := $(shell find $(DIRETORIO_TESTES) -type f -name *.$(EXTENSAO_SOURCE))

TARGET := main
INC := -I include/movimentacao -I include/estoque -I include/login -I include/sistema
INC2 := -I third_party
CFLAGS := -g -Wall -O3 -std=c++11 $(INC)

all: main

$(DIRETORIO_OBJETOS)/%.o: $(DIRETORIO_SOURCE)/%.$(EXTENSAO_SOURCE)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

tests: $(OBJETOS)
	$(CC) $(CFLAGS) $(INC2) $(SOURCES_TESTES) $^ -o tester

main: $(OBJETOS)
	$(CC) $(CFLAGS) $(MAIN) $^ -o $(TARGET)

clean:
	$(RM) -r $(DIRETORIO_OBJETOS)/* *.gcda *.gcno