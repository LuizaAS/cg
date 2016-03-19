#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "personagem.h"
#include "parada.h"


void personagemMorre(struct personagem *jogador){
  jogador->vidas--;
}

void desenhaPersonagem(struct personagem perso){
  glPushMatrix();                 
  glTranslatef(perso.coordenadas.x, perso.coordenadas.y, 0);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, perso.textura);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 0); glVertex3f(-perso.tamanho, -perso.tamanho,  0);
      glTexCoord2f(1, 0); glVertex3f( perso.tamanho, -perso.tamanho,  0);
      glTexCoord2f(1, 1); glVertex3f( perso.tamanho,  perso.tamanho,  0);
      glTexCoord2f(0, 1); glVertex3f(-perso.tamanho,  perso.tamanho,  0);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
  return;
}

int moveRight(struct personagem perso, int tam){
  perso.coordenadas.x+=25;
  if(tam/2<perso.coordenadas.x+perso.tamanho){
    perso.coordenadas.x-=25;
  }
  return perso.coordenadas.x;
}

int moveLeft(struct personagem perso, int tam){
  perso.coordenadas.x-=25;
  if(-tam/2>perso.coordenadas.x-perso.tamanho){
    perso.coordenadas.x+=25;
  }
  return perso.coordenadas.x;
}

GLuint texturaPersonagem(struct personagem perso) {
  perso.textura = SOIL_load_OGL_texture(
    "imagens/Ninja1.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
}

struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas){
    perso.coordenadas.x= x;
    perso.coordenadas.y= y;
    perso.tamanho=tam;
    perso.vidas=vidas;
    perso.textura=texturaPersonagem(perso);
    return perso;
}

