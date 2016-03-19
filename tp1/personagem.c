#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "parada.h"
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
    GLint aux = jogador->texturaAtual;
    jogador->texturaAtual = jogador->texturaPuso;
    jogador->texturaPuso = aux;
    jogador->tempoPiscando++;
    if(jogador->tempoPiscando == 200){
      jogador->texturaAtual = jogador->textura;
      jogador->tempoPiscando = 0;
      jogador-> estado = ativo;
    }
  }
}
void desenhaVidas (struct personagem jogador, struct posicao tamanhoTela){
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
}
void desenhaPersonagem(struct personagem jogador, struct posicao tamanhoTela){
  glPushMatrix();                 
  glTranslatef(jogador.coordenadas.x, jogador.coordenadas.y, 0);
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, jogador.texturaAtual);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 0); glVertex3f(-jogador.tamanho, -jogador.tamanho,  0);
      glTexCoord2f(1, 0); glVertex3f( jogador.tamanho, -jogador.tamanho,  0);
      glTexCoord2f(1, 1); glVertex3f( jogador.tamanho,  jogador.tamanho,  0);
      glTexCoord2f(0, 1); glVertex3f(-jogador.tamanho,  jogador.tamanho,  0);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
  desenhaVidas(jogador, tamanhoTela);
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
int texturaVida (int textura){
  textura = SOIL_load_OGL_texture(
    "imagens/coracao2.png",
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
    perso.texturaAtual=perso.textura;
    perso.texturaVidas=texturaVida(perso.texturaVidas);
    return perso;
}

