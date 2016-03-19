enum Tela{ inicial, pausa, jogo, gameOver};
enum est{inativo, ativo};
struct posicao{
	int x;
	int y;	
};
struct parametrosJogo{
	struct posicao tamanhoTela;
	int tempoDeJogo;
	int tempoEntreCriaParadas;
	int texturaJogo;
	int texturaInicial;
	int texturaPausa;
	int texturaGameOver;
	Tela telaAtual;
	Tela telaAnterior;
};
void setupParametros(struct parametrosJogo *parametros);
void desenhaFundo(struct parametrosJogo parametros);
void texturaParametro(struct parametrosJogo *parametros);
void inicializa(struct parametrosJogo *parametro, struct personagem *jogador, struct parada obj[]);