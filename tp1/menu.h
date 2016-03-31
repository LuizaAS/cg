#define tempoTotal 16000

enum Tela{ inicial, pausa, jogo, gameOver, Win, confirmaSair, confirmaReiniciar};
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
	float tempoDeJogo;
	int constanteTempo;
	int tempoEntreCriaParadas;
	int texturaJogo;
	int texturaInicial;
	int texturaPausa;
	int texturaGameOver;
	int texturaConfirma;
	int texturaWin;
	Tela telaAtual;
	Tela telaAnterior;
	struct botoes play;
	struct botoes sim;
	struct botoes nao;
};
// funcao do main.c q toca quando o personagem é atingido
void musicaColisao();
// converte as coordenadas do mouse para o sistema de coordenadas do mundo
void converteCoordenadas(int x, int y, struct posicao *mouse, struct posicao tamanhoTela);
//verifica se o clique do mouse foi em um determinado botao
bool clique(struct posicao mouse, struct botoes botao);
// reinicia os parametros do jogo
void reinicia(struct parametrosJogo *parametro, struct parada obj[], struct personagem *jogador);
void setupParametros(struct parametrosJogo *parametros);
void setupBotoes (struct botoes *botao, int x, int y, int tamx, int tamy);
void desenhaBotoes(struct botoes botao);
void desenhaTempo(struct parametrosJogo parametros);
void desenhaFundo(struct parametrosJogo parametros);