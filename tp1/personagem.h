struct personagem{
	struct posicao coordenadas;
  	GLuint texturaAtual;
  	GLuint textura;
  	GLuint texturaPuso;
  	int tamanho; // id textura
  	// int textura-pulo;
  	int vidas;
 	int texturaVidas;
 	int tempoPiscando;
 	est estado;
};
void criaLista(struct personagem perso);
void personagemMorre(struct personagem *jogador, Tela *telaAtual);
void piscaPersonagem (struct personagem *jogador);
void desenhaPersonagem(struct personagem jogador, struct posicao tamanhoTela);
void desenhaVidas (struct personagem jogador, struct posicao tamanhoTela);
int moveRight(struct personagem perso, int tam);
int moveLeft(struct personagem perso, int tam);
struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas);