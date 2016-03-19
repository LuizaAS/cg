#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "personagem.h"
#include "parada.h"

void setupParametros(struct parametrosJogo *parametros){
	parametros->tempoDeJogo=0;
	parametros->tempoEntreCriaParadas=0;
	parametros->texturaJogo= texturaParametro(parametros->texturaJogo);
	desenhaFundo(*parametros);
}

void desenhaFundo(struct parametrosJogo parametros){
  	glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, parametros.texturaJogo);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-parametros.tamanhoTela.x/2, -parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(1, 0); glVertex3f( parametros.tamanhoTela.x/2, -parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(1, 1); glVertex3f( parametros.tamanhoTela.x/2,  parametros.tamanhoTela.y/2,  0);
        glTexCoord2f(0, 1); glVertex3f(-parametros.tamanhoTela.x/2,  parametros.tamanhoTela.y/2,  0);
    glEnd();
   	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

int texturaParametro(int textura) {
  textura = SOIL_load_OGL_texture(
    "imagens/muro.jpeg",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
}