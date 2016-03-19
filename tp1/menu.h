enum menu{ inicial, pausa, jogo, gameOver};
struct posicao{
	int x;
	int y;	
};
struct parametrosJogo{
	struct posicao tamanhoTela;
	int tempoDeJogo;
	int tempoEntreCriaParadas;
	int textura;
};
void setupParametros(struct parametrosJogo *parametros);