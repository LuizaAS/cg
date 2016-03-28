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

void personagemMorre(struct personagem *jogador, Tela *telaAtual){
  jogador->vidas--;
  jogador->tempoPiscando=0;
  jogador->estado = inativo;
  if(jogador->vidas==0){
      printf("Voce perdeu\n");
      *telaAtual = gameOver;
  }
}
void piscaPersonagem (struct personagem *jogador){
  if ( jogador->estado == inativo ){
    jogador->tempoPiscando++;
    if(jogador->tempoPiscando%2 ==0){
      GLint aux = jogador->texturaAtual;
      jogador->texturaAtual = jogador->texturaPuso;
      jogador->texturaPuso = aux;
      if(jogador->tempoPiscando == 200){
        jogador->texturaAtual = jogador->textura10;
        jogador->tempoPiscando = 0;
        jogador-> estado = ativo;
      }
    }
  }
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
      glTexCoord2f(0, 0); glVertex3f(-jogador.tamanho.x, -jogador.tamanho.y,  0);
      glTexCoord2f(1, 0); glVertex3f( jogador.tamanho.x, -jogador.tamanho.y,  0);
      glTexCoord2f(1, 1); glVertex3f( jogador.tamanho.x,  jogador.tamanho.y,  0);
      glTexCoord2f(0, 1); glVertex3f(-jogador.tamanho.x,  jogador.tamanho.y,  0);
    glEnd();
  glPopMatrix();
  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
  desenhaVidas(jogador, tamanhoTela);
  return;
}

int moveRight(struct personagem perso, int tam){
  perso.coordenadas.x+=25;
  if(tam/2<perso.coordenadas.x+perso.tamanho.x){
    perso.coordenadas.x-=25;
  }
  return perso.coordenadas.x;
}

int moveLeft(struct personagem perso, int tam){
  perso.coordenadas.x-=25;
  if(-tam/2>perso.coordenadas.x-perso.tamanho.x){
    perso.coordenadas.x+=25;
  }
  return perso.coordenadas.x;
}

struct personagem setupPersonagem( struct personagem perso, int x, int y, int tam, int vidas){
    perso.coordenadas.x= x;
    perso.coordenadas.y= y;
    perso.tamanho.y=tam;
    perso.tamanho.x=tam*67/124;
    perso.vidas=vidas;
    perso.texturaAtual=perso.textura10;
    perso.texturaPuso=perso.textura12;
    perso.estado=ativo;
    return perso;
}