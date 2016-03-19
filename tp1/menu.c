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
}