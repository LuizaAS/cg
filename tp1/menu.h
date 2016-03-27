enum Tela{ inicial, pausa, jogo, gameOver, confirmaSair, confirmaReiniciar};
enum est{inativo, ativo};
struct posicao{
	int x;
	int y;	
};
struct botoes {
	struct posicao coordenadas;
	struct posicao tamanho;
  	GLuint textura;
};
struct parametrosJogo{
	struct posicao tamanhoTela;
	int tempoDeJogo;
	int tempoEntreCriaParadas;
	int texturaJogo;
	int texturaInicial;
	int texturaPausa;
	int texturaGameOver;
	int texturaConfirma;
	Tela telaAtual;
	Tela telaAnterior;
	struct botoes barraDeTempo;
	struct botoes play;
	struct botoes sim;
	struct botoes nao;
};
/*void certeza( est *certeza);*/
void converteCoordenadas(int x, int y, struct posicao *mouse, struct posicao tamanhoTela);
bool clique(struct posicao mouse, struct botoes botao);
void setupParametros(struct parametrosJogo *parametros);
void setupBotoes (struct botoes *botao, int x, int y, int tamx, int tamy);
void desenhaFundo(struct parametrosJogo parametros);
void desenhaBarra(struct parametrosJogo parametros);
void reinicia(struct parametrosJogo *parametro, struct parada obj[], struct personagem *jogador);