# indef PRODUTO.HPP
# define PRODUTO.HPP
# include <iostream>

class Produto{
  private:
  string nome;
  int codigo;
  string fabricante;
  float preco;
  string categoria;
  
  public:
  string get_nome ();
  int get_codigo ();
  string get_fabricante ();
  float get_preco ();
  string get_categoria ();
  void set_nome ();
  void set_codigo ();
  void set_fabricante ();
  void set_preco ();
  void get_categoria ();
};
#endif;
  
