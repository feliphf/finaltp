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

loginpessoa:
	$(CC) $(CFLAGS) -c src/loginpessoa.cpp -o build/loginpessoa.o

funcionario:
	$(CC) $(CFLAGS) -c src/funcionario.cpp -o build/funcionario.o

gerente:
	$(CC) $(CFLAGS) -c src/gerente.cpp -o build/gerente.o

main: produto estoque loginpessoa funcionario gerente
	$(CC) $(CFLAGS) build/produto.o build/estoque.o build/gerente.o build/funcionario.o build/loginpessoa.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)