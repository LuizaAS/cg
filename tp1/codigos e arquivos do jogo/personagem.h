struct animacao{
	GLuint textura[8];
	int contador;
	int tamanho;
	int tempo;
	bool reinicia;
};
struct personagem{
	struct posicao coordenadas;
  	GLuint texturaAtual;
  	GLuint texturaPuso;
  	struct posicao tamanho; 
  	int vidas;
 	int texturaVidas;
 	int tempoPiscando;
 	est estado;
 	struct animacao normal;
 	struct animacao dano;
 	struct animacao morre;
 	struct animacao corre;
 	est lado; // caso a imagem seja invertida lado é ativo
};

void personagemMorre(struct personagem *jogador);
void desenhaVidas (struct personagem jogador, struct posicao tamanhoTela);
void desenhaPersonagem(struct personagem jogador, struct posicao tamanhoTela);
void moveRight(struct personagem *perso, int tam);
void moveLeft(struct personagem *perso, int tam);
struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas);