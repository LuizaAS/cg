struct personagem{
  int x;
  int y;
  GLuint textura;
  int tamanho; // id textura
  // int textura-pulo;
  int vidas;
};

void desenhaPersonagem(struct personagem perso);
GLuint texturaPersonagem(struct personagem perso);
int moveRight(struct personagem perso, int tam);
int moveLeft(struct personagem perso, int tam);
struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas);