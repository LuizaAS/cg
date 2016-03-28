struct personagem{
	struct posicao coordenadas;
  	GLuint texturaAtual;
  	GLuint textura10;
  	GLuint textura12;
  	GLuint texturaPuso;
  	struct posicao tamanho; 
  	int vidas;
 	int texturaVidas;
 	int tempoPiscando;
 	est estado;
};

void personagemMorre(struct personagem *jogador, Tela *telaAtual);
void piscaPersonagem (struct personagem *jogador);
void desenhaVidas (struct personagem jogador, struct posicao tamanhoTela);
void desenhaPersonagem(struct personagem jogador, struct posicao tamanhoTela);
int moveRight(struct personagem perso, int tam);
int moveLeft(struct personagem perso, int tam);
struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas);