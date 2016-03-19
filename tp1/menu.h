enum Tela{ inicial, pausa, jogo, gameOver};
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
	Tela telaAtual;
	Tela telaAnterior;
};
void setupParametros(struct parametrosJogo *parametros);
void desenhaFundo(struct parametrosJogo parametros);
int texturaParametro(int textura);
