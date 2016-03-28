#define qntParadas 30
struct parada {
	struct posicao coordenadas;
  	GLuint textura;
 	int tamanho;
 	int tipo;
 	est estado;
};

void desenhaParada(struct parada* p);
int createParada(struct parada obj[], int i, int nParadasCriadas, struct parametrosJogo parametro);
//diminui o y das paradas ativas e verifica se atingem o personagem
void paradasCaem(struct parada obj[], struct personagem *jogador, struct parametrosJogo *parametro);
void setupParada(struct parada obj[], struct parametrosJogo parametro);