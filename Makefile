CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main

produto:
	$(CC) $(CFLAGS) -c src/produto.cpp -o build/produto.o

estoque:
	$(CC) $(CFLAGS) -c src/estoque.cpp -o build/estoque.o

main: produto estoque
	$(CC) $(CFLAGS) build/produto.o build/estoque.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)