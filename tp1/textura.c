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

GLuint texturaPersonagem(struct personagem perso) {
  perso.textura = SOIL_load_OGL_texture(
    "imagens/img1-0.png",
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