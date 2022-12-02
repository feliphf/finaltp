CC := g++
DIRETORIO_SOURCE := src
DIRETORIO_OBJETOS := build
MAIN := system/main.cpp

EXTENSAO_SOURCE := cpp
SOURCES := $(shell find $(DIRETORIO_SOURCE) -type f -name *.$(EXTENSAO_SOURCE))
OBJETOS := $(patsubst $(DIRETORIO_SOURCE)/%,$(DIRETORIO_OBJETOS)/%,$(SOURCES:.$(EXTENSAO_SOURCE)=.o))

TARGET := main
INC := -I include/movimentacao -I include/estoque -I include/login -I include/sistema
CFLAGS := -g -Wall -O3 -std=c++11 $(INC)


all: main

$(DIRETORIO_OBJETOS)/%.o: $(DIRETORIO_SOURCE)/%.$(EXTENSAO_SOURCE)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJETOS) #$(MAIN) 
	$(CC) $(CFLAGS) $(MAIN) $^ -o $(TARGET)

clean:
	$(RM) -r $(DIRETORIO_OBJETOS)/* $(TARGET)