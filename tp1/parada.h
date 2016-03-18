 #define qntParadas 20
 enum est{ inativo, ativo } ;
struct parada {
  int x;
  int y;
  GLuint textura;
  int tamanho;
  int tipo;
  est estado;
  int teste;
};

void desenhaParada(struct parada* p);
struct parada createParada(struct parada p, int tamOrtX, int tamOrty);
struct parada paradasCaem(struct parada p, int tamOrtX, int tamOrty);
// struct parada* setupParada(struct parada* p);