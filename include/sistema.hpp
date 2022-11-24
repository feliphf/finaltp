#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "estoque.hpp"
#include "loginpessoa.hpp"

class Sistema {
    private:
        Estoque _estoque;
    public:
        Sistema()=default;
        void menuInicial();
};

#endif