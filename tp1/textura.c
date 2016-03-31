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

void texturaPersonagem(struct personagem *perso) {
  perso->normal.textura[0] = SOIL_load_OGL_texture(
    "imagens/img1-0.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->normal.textura[1] = SOIL_load_OGL_texture(
    "imagens/img1-1.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->normal.textura[2] = SOIL_load_OGL_texture(
    "imagens/img1-2.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->dano.textura[0] = SOIL_load_OGL_texture(
    "imagens/img2-0.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->dano.textura[1] = SOIL_load_OGL_texture(
    "imagens/img2-1.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->dano.textura[2] = SOIL_load_OGL_texture(
    "imagens/img2-2.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->dano.textura[3] = SOIL_load_OGL_texture(
    "imagens/img2-3.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->dano.textura[4] = SOIL_load_OGL_texture(
    "imagens/img2-4.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[0] = SOIL_load_OGL_texture(
    "imagens/img3-0.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[1] = SOIL_load_OGL_texture(
    "imagens/img3-1.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[2] = SOIL_load_OGL_texture(
    "imagens/img3-2.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[3] = SOIL_load_OGL_texture(
    "imagens/img3-3.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[4] = SOIL_load_OGL_texture(
    "imagens/img3-4.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[5] = SOIL_load_OGL_texture(
    "imagens/img3-5.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[6] = SOIL_load_OGL_texture(
    "imagens/img3-6.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  perso->morre.textura[7] = SOIL_load_OGL_texture(
    "imagens/img3-7.png",
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

void texturaParada(struct parada obj[]) {
  for (int i = 0; i < qntParadas; ++i)
  {
    obj[i].textura = SOIL_load_OGL_texture(
      "imagens/star.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y
      );
  }
}
void texturaParametro(struct parametrosJogo *parametros) {
  parametros->texturaInicial = SOIL_load_OGL_texture(
    "imagens/inicial.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->texturaJogo = SOIL_load_OGL_texture(
    "imagens/muro1.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->texturaPausa = SOIL_load_OGL_texture(
    "imagens/pausa1.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->texturaGameOver = SOIL_load_OGL_texture(
    "imagens/gameover.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->texturaWin = SOIL_load_OGL_texture(
    "imagens/win.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
    parametros->texturaConfirma = SOIL_load_OGL_texture(
    "imagens/ctz.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
    parametros->play.textura = SOIL_load_OGL_texture(
    "imagens/play1.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->sim.textura = SOIL_load_OGL_texture(
    "imagens/tick.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );
  parametros->nao.textura = SOIL_load_OGL_texture(
    "imagens/nao.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
  );  
}