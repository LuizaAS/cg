 #define qntParadas 20
 enum est{ inativo, ativo } ;
struct parada {
  int x;
  int y;
  GLuint textura;
  int tamanho;
  int tipo;
  est estado;
};

void desenhaParada(struct parada* p);
int createParada(struct parada obj[], int i, int tamOrtX, int tamOrty, int nParadasCriadasPorExecucao, int nParadasCriadas);
void paradasCaem(struct parada p[], struct personagem *jogador, int tamOrtX, int tamOrty);
void setupParada(struct parada obj[]);