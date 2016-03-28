#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "parada.h"
#include "textura.h"
#include "personagem.h"

void converteCoordenadas(int x, int y, struct posicao *mouse, struct posicao tamanhoTela){
	mouse->y=-1*(y-(tamanhoTela.y/2));
	mouse->x=x-(tamanhoTela.x/2);
}

bool clique(struct posicao mouse, struct botoes botao){
	if ((mouse.y>=(botao.coordenadas.y-botao.tamanho.y))&&(mouse.y<=(botao.coordenadas.y+botao.tamanho.y))&&(mouse.x>=(botao.coordenadas.x-botao.tamanho.x))&&(mouse.x<=(botao.coordenadas.x+botao.tamanho.x))){    
		return true;
	}
	return false;
}

void reinicia(struct parametrosJogo *parametro, struct parada obj[], struct personagem *jogador) {
    glClearColor(1, 1, 1, 0);
    *jogador=setupPersonagem(*jogador,-50,-50,30,3);
    setupParada(obj, *parametro);
    setupParametros(parametro);  
}

void setupParametros(struct parametrosJogo *parametros){
	parametros->constanteTempo=60;
	parametros->tempoDeJogo=0;
	parametros->tempoEntreCriaParadas=0;
	setupBotoes(&parametros->play, -parametros->tamanhoTela.x/2+50, -parametros->tamanhoTela.y/2+100, 80, 80);
	setupBotoes(&parametros->sim,-30, -10, 50, 50 );
	setupBotoes(&parametros->nao,30, -10, 50, 50 );
	int aux = parametros->tamanhoTela.x/2*68/662;
	setupBotoes(&parametros->barraDeTempo,0,-parametros->tamanhoTela.y/2+20,parametros->tamanhoTela.x/2,aux);
	desenhaFundo(*parametros);
}
void setupBotoes (struct botoes *botao, int x, int y, int tamx, int tamy)	{
	botao->coordenadas.x= x;
	botao->coordenadas.y= y;
	botao->tamanho.x=tamx;
	botao->tamanho.y=tamy;
}
void desenhaBotoes(struct botoes botao){
  	glPushMatrix();
  	glTranslatef(botao.coordenadas.x, botao.coordenadas.y, 0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, botao.textura);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-botao.tamanho.x/2, -botao.tamanho.y/2,  0);
        glTexCoord2f(1, 0); glVertex3f( botao.tamanho.x/2, -botao.tamanho.y/2,  0);
        glTexCoord2f(1, 1); glVertex3f( botao.tamanho.x/2,  botao.tamanho.y/2,  0);
        glTexCoord2f(0, 1); glVertex3f(-botao.tamanho.x/2,  botao.tamanho.y/2,  0);
    glEnd();
   	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void desenhaFundo(struct parametrosJogo parametros){
  	glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    switch(parametros.telaAtual){
    	case inicial:
    		glBindTexture(GL_TEXTURE_2D, parametros.texturaInicial);
    		break;
    	case jogo:
    		glBindTexture(GL_TEXTURE_2D, parametros.texturaJogo);
    		break;
    	case pausa:
    		glBindTexture(GL_TEXTURE_2D, parametros.texturaPausa);
    		break;
    	case gameOver:
    		glBindTexture(GL_TEXTURE_2D, parametros.texturaGameOver);
    		break;
    	case Win:
    		glBindTexture(GL_TEXTURE_2D, parametros.texturaWin);
    		break;
    	case confirmaSair:
    	case confirmaReiniciar:
    		glBindTexture(GL_TEXTURE_2D, parametros.texturaConfirma);
    		break;
    }
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-parametros.tamanhoTela.x/2, -parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(1, 0); glVertex3f( parametros.tamanhoTela.x/2, -parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(1, 1); glVertex3f( parametros.tamanhoTela.x/2,  parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(0, 1); glVertex3f(-parametros.tamanhoTela.x/2,  parametros.tamanhoTela.y/2,  0);
    glEnd();
   	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	switch(parametros.telaAtual){
    	case inicial:
    		desenhaBotoes(parametros.play);
    		break;
    	case jogo:
    		desenhaBotoes(parametros.barraDeTempo);
    		break;
    	case pausa:
    		break;
    	case gameOver:
    		break;
    	case Win:	
    		break;
    	case confirmaSair:
    	case confirmaReiniciar:
    		desenhaBotoes(parametros.sim);
    		desenhaBotoes(parametros.nao);
    		break;
    }
}