# ifndef PRODUTO.HPP
# define PRODUTO.HPP
# include <iostream>

class Produto{
  
  private:
  
  int codigo;
  float preco;
  string nome;
  string categoria;
  string fabricante;
  
  public:
  
  void set_nome ();
  void set_codigo ();
  void set_fabricante ();
  void set_preco ();
  void set_categoria ();
  int get_codigo ();
  float get_preco ();
  string get_nome ();
  string get_categoria ();
  string get_fabricante ();
  
};
#endif;
  
