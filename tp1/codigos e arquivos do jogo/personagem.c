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

void personagemMorre(struct personagem *jogador){
  jogador->vidas--;
  jogador->tempoPiscando=0;
  jogador->estado = inativo;
}

void desenhaVidas (struct personagem jogador, struct posicao tamanhoTela){
  glEnable(GL_BLEND);
  for (int i = 0, distancia = 0; i < jogador.vidas; ++i, distancia+=20){
  glPushMatrix();                 
  glTranslatef(tamanhoTela.x/2-50-distancia,tamanhoTela.y/2-50 , 0);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, jogador.texturaVidas);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 0); glVertex3f(-10, -10,  0);
      glTexCoord2f(1, 0); glVertex3f( 10, -10,  0);
      glTexCoord2f(1, 1); glVertex3f( 10,  10,  0);
      glTexCoord2f(0, 1); glVertex3f(-10,  10,  0);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
  }
  glDisable(GL_BLEND);
}
void desenhaPersonagem(struct personagem jogador, struct posicao tamanhoTela){
  glPushMatrix();                 
  glTranslatef(jogador.coordenadas.x, jogador.coordenadas.y, 0);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
    glBindTexture(GL_TEXTURE_2D, jogador.texturaAtual);
    glBegin(GL_QUADS);
    if (jogador.lado== ativo){
      glTexCoord2f(1, 0); glVertex3f(-jogador.tamanho.x, -jogador.tamanho.y,  0);
      glTexCoord2f(0, 0); glVertex3f( jogador.tamanho.x, -jogador.tamanho.y,  0);
      glTexCoord2f(0, 1); glVertex3f( jogador.tamanho.x,  jogador.tamanho.y,  0);
      glTexCoord2f(1, 1); glVertex3f(-jogador.tamanho.x,  jogador.tamanho.y,  0);
    }
    else{
      glTexCoord2f(0, 0); glVertex3f(-jogador.tamanho.x, -jogador.tamanho.y,  0);
      glTexCoord2f(1, 0); glVertex3f( jogador.tamanho.x, -jogador.tamanho.y,  0);
      glTexCoord2f(1, 1); glVertex3f( jogador.tamanho.x,  jogador.tamanho.y,  0);
      glTexCoord2f(0, 1); glVertex3f(-jogador.tamanho.x,  jogador.tamanho.y,  0);
    }
    glEnd();
  glPopMatrix();
  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
  desenhaVidas(jogador, tamanhoTela);
  return;
}

void moveRight(struct personagem *perso, int tam){
  perso->coordenadas.x+=25;
  perso->lado=inativo;
  if(tam/2<perso->coordenadas.x+perso->tamanho.x){
    perso->coordenadas.x-=25;
  }
}

void moveLeft(struct personagem *perso, int tam){
  perso->coordenadas.x-=25;
  perso->lado=ativo;
  if(-tam/2>perso->coordenadas.x-perso->tamanho.x){
    perso->coordenadas.x+=25;
  }
}

struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas){
    perso.coordenadas.x= x;
    perso.coordenadas.y= y;
    perso.tamanho.y=tam;
    perso.tamanho.x=tam*67/124;
    perso.vidas=vidas;
    perso.texturaAtual=perso.normal.textura[0];
    perso.texturaPuso=perso.normal.textura[2];
    perso.estado=ativo;
    perso.lado=inativo;
    perso.normal.tamanho=2;
    perso.dano.tamanho=5;
    perso.morre.tamanho= 8;
    perso.corre.tamanho=6;
    perso.normal.reinicia=true;
    perso.dano.reinicia=false;
    perso.morre.reinicia=false;
    perso.corre.reinicia=true;
    return perso;
}