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

void piscaPersonagem (struct personagem *jogador, Tela *telaAtual){
  jogador->tempoPiscando++;
  if(jogador->vidas==0){    
      if(jogador->tempoPiscando%5 ==0){
       if(jogador->tempoPiscando<50)
         anima(&jogador->morre, jogador);
       else{
        *telaAtual = gameOver;
       }
     }
  }
  else if ( jogador->estado == inativo ){
    if(jogador->tempoPiscando%5 ==0){
      if(jogador->tempoPiscando<35)
        anima(&jogador->dano, jogador);
      else{
        GLint aux = jogador->texturaAtual;
        jogador->texturaAtual = jogador->texturaPuso;
        jogador->texturaPuso = aux;
        if(jogador->tempoPiscando == 200){
          jogador->texturaAtual = jogador->normal.textura[0];
          jogador->tempoPiscando = 0;
          jogador-> estado = ativo;
        }
      }
    }
  }
}

void anima (struct animacao *anima,struct personagem *jogador){
  if(anima->contador<anima->tamanho){
  jogador->texturaAtual=anima->textura[anima->contador];
  anima->contador++;
  }
  else {
    jogador->texturaAtual=jogador->normal.textura[0];
    jogador->texturaPuso=jogador->normal.textura[2];
    if(anima->reinicia)
      anima->contador=0;
  }
}

