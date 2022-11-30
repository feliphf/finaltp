#include "loginpessoa.hpp"

int LoginPessoa::Logar()
{
    int stop = -1;
    do
        {
        std::cout << "Escolha uma das opcoes de login:(G) para logar como Gerente ou (F) para logar como Funcionario!\n";
        std::string opcao;
        std::cin >> opcao;
        if (opcao == "G" || opcao == "g")
        {
            std::cout << "Digite a senha do Gerente: ";
            std::cin >> _senha;
            if (_senha == _senha_Gerente)
            {
            std::cout << "Voce logou como Gerente!\n";
            stop = 1;
            }
            else
            {
                while (_senha != _senha_Gerente || stop != 0)
                {
                std::cout << "Senha invalida!\n";
                std::cout << "Digite a senha novamente ou aperte (Q) para escolher outra opcao!\n";
                std::cin >> _senha;
                if (_senha == "q" || _senha == "Q")
                stop = 0;
                }
                if (_senha == _senha_Gerente)
                {
                std::cout << "Voce logou como Gerente!\n";
                stop = 1;
                }
            }
        }
        else if (opcao == "F" || opcao == "f")
        {
            std::cout << "Digite a senha do Funcionario: ";
            std::cin >> _senha;
            if (_senha == _senha_Funcionario)
            {
            std::cout << "Voce logou como Funcionario!\n";
            stop = 2;
            }
            else
            {
                while (_senha != _senha_Funcionario || stop != 0)
                {
                std::cout << "Senha invalida!\n";
                std::cout << "Digite a senha novamente ou aperte (Q) para escolher outra opcao!\n";
                std::cin >> _senha;
                if (_senha == "q" || _senha == "Q")
                stop = 0;
                }
                if (_senha == _senha_Funcionario)
                {
                std::cout << "Voce logou como Funcionario!\n";
                stop = 2;
                }
            }
        }
        else
        {
            std::cout << "Opcao escolhida invalida!\n";
        }
    }
    while (stop != 1 || stop != 2);

    return stop;
}
