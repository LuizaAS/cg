#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "parada.h"
#include "personagem.h"

void certeza(){

}

void inicializa(struct parametrosJogo *parametro, struct personagem *jogador, struct parada obj[]) {
    glClearColor(1, 1, 1, 0);
    parametro->tamanhoTela.x = 500;
    parametro->tamanhoTela.y =600;
    *jogador=setupPersonagem(*jogador,-50,-50,25,3);
    setupParada(obj, *parametro);
    setupParametros(parametro);  
}

void setupParametros(struct parametrosJogo *parametros){
	parametros->tempoDeJogo=0;
	parametros->tempoEntreCriaParadas=0;
	texturaParametro(parametros);
	desenhaFundo(*parametros);
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
    }
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-parametros.tamanhoTela.x/2, -parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(1, 0); glVertex3f( parametros.tamanhoTela.x/2, -parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(1, 1); glVertex3f( parametros.tamanhoTela.x/2,  parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(0, 1); glVertex3f(-parametros.tamanhoTela.x/2,  parametros.tamanhoTela.y/2,  0);
    glEnd();
   	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void texturaParametro(struct parametrosJogo *parametros) {
  parametros->texturaInicial = SOIL_load_OGL_texture(
    "imagens/castelo.jpg",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->texturaJogo = SOIL_load_OGL_texture(
    "imagens/muro.jpeg",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->texturaPausa = SOIL_load_OGL_texture(
    "imagens/pausa.jpg",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->texturaGameOver = SOIL_load_OGL_texture(
    "imagens/gameOver.jpeg",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
}