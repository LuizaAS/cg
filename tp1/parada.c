#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.hpp>
#include "menu.h"
#include "parada.h"
#include "textura.h"
#include "personagem.h"
#include "animacoes.h"

void desenhaParada(struct parada* p){
	glEnable(GL_BLEND);
    for (int i = 0; i < qntParadas; ++i){
    	if (p[i].estado == ativo){
	    	glPushMatrix();
	        glTranslatef(p[i].coordenadas.x, p[i].coordenadas.y, 0);
	        glEnable(GL_TEXTURE_2D);
	        glBindTexture(GL_TEXTURE_2D, p[i].textura);
	        glBegin(GL_QUADS);
	          glTexCoord2f(0, 0); glVertex3f(-p[i].tamanho, -p[i].tamanho,  0);
	          glTexCoord2f(1, 0); glVertex3f( p[i].tamanho, -p[i].tamanho,  0);
	          glTexCoord2f(1, 1); glVertex3f( p[i].tamanho,  p[i].tamanho,  0);
	          glTexCoord2f(0, 1); glVertex3f(-p[i].tamanho,  p[i].tamanho,  0);
	        glEnd();
	    	glPopMatrix();
	  		glDisable(GL_TEXTURE_2D);
   		}
    }
    glDisable(GL_BLEND);
}

int createParada(struct parada obj[], int i, int nParadasCriadas, struct parametrosJogo parametro){
	if (obj[i].estado == inativo && nParadasCriadas<2 && parametro.tempoEntreCriaParadas==0) {
	    obj[i].coordenadas.x=rand()%((parametro.tamanhoTela.x/2)-4*obj[i].tamanho);
	    if (obj[i].coordenadas.x%2==0)
	      obj[i].coordenadas.x*=-1;
	    obj[i].tamanho = 10;
	    obj[i].coordenadas.y=((parametro.tamanhoTela.y/2)-obj[i].tamanho);
	    obj[i].estado=ativo;  
	    nParadasCriadas++;
  	}
   return nParadasCriadas;
}
void paradasCaem(struct parada obj[], struct personagem *jogador, struct parametrosJogo *parametro){
	for (int i = 0, nParadasCriadas = 0 ; i < qntParadas; ++i)  {
		if (obj[i].coordenadas.y>-parametro->tamanhoTela.y/2 && obj[i].estado == ativo){
		    obj[i].coordenadas.y-=1;
		  	if((((obj[i].coordenadas.y+obj[i].tamanho)>=(jogador->coordenadas.y-jogador->tamanho.y)) && ((obj[i].coordenadas.y-obj[i].tamanho)<=(jogador->coordenadas.y+jogador->tamanho.y) )&& ((obj[i].coordenadas.x+obj[i].tamanho)>=(jogador->coordenadas.x-jogador->tamanho.x)) && ((obj[i].coordenadas.x-obj[i].tamanho)<=(jogador->coordenadas.x+jogador->tamanho.x)) && obj[i].estado == ativo) && jogador->estado==ativo) {
		      obj[i].estado=inativo;
		      jogador->dano.contador=0;
		      musicaColisao();
		      personagemMorre(jogador);
	    	}
		}
		else{
			obj[i].estado = inativo;
		    nParadasCriadas=createParada(obj, i, nParadasCriadas, *parametro);
		}
  	}
}
void setupParada(struct parada obj[], struct parametrosJogo parametro){
	for (int i = 0; i < qntParadas; ++i) {
      obj[i].estado = inativo;
  	}
  	createParada(obj, 0, 0, parametro); 
}