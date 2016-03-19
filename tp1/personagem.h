struct personagem{
	struct posicao coordenadas;
  	GLuint textura;
  	int tamanho; // id textura
  	// int textura-pulo;
 	int vidas;
 	int lista;
};
void criaLista(struct personagem perso);
void personagemMorre(struct personagem *jogador);
void desenhaPersonagem(struct personagem perso);
GLuint texturaPersonagem(struct personagem perso);
int moveRight(struct personagem perso, int tam);
int moveLeft(struct personagem perso, int tam);
struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas);