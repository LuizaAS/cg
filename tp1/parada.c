#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#include "parada.h"
void desenhaParada(struct parada* p){
    for (int i = 0; i < qntParadas; ++i)    {
    	if (p[i].estado == ativo){
	    	    glPushMatrix();
	        glColor3f(0,0,0); 
	        glTranslatef(p[i].x, p[i].y, 0);
	        /*glEnable(GL_TEXTURE_2D);*/
	        /*glBindTexture(GL_TEXTURE_2D, perso.textura);*/
	        glBegin(GL_QUADS);
	          /*glTexCoord2f(0, 0);*/ glVertex3f(-p[i].tamanho, -p[i].tamanho,  0);
	          /*glTexCoord2f(1, 0);*/ glVertex3f( p[i].tamanho, -p[i].tamanho,  0);
	          /*glTexCoord2f(1, 1);*/ glVertex3f( p[i].tamanho,  p[i].tamanho,  0);
	          /*glTexCoord2f(0, 1);*/ glVertex3f(-p[i].tamanho,  p[i].tamanho,  0);
	        glEnd();
	    	glPopMatrix();
	  		// glDisable(GL_TEXTURE_2D);
   		}
    }
}

int createParada(struct parada obj[], int i, int tamOrtX, int tamOrty, int nParadasCriadasPorExecucao, int nParadasCriadas){
	if (obj[i].estado == inativo && nParadasCriadas<=nParadasCriadasPorExecucao) {
	    obj[i].x=rand()%((tamOrtX/2)-5*obj[i].tamanho);
	    if (obj[i].x%2==0)
	      obj[i].x*=-1;
	    obj[i].tamanho = 10;
	    obj[i].y=((tamOrty/2)-obj[i].tamanho);
	    obj[i].estado=ativo;  
	    nParadasCriadas++;
  	}
   return nParadasCriadas;
}
void paradasCaem(struct parada obj[], struct personagem *jogador, int tamOrtX, int tamOrty){
	for (int i = 0, nParadasCriadasPorExecucao=rand()%5, nParadasCriadas = 0 ; i < qntParadas; ++i)  {
	  if (obj[i].y>-tamOrty/2 && obj[i].estado == ativo){
	    obj[i].y-=1;
	  	if(((obj[i].y+obj[i].tamanho)>=(jogador->y-jogador->tamanho)) && ((obj[i].y-obj[i].tamanho)<=(jogador->y+jogador->tamanho) )&& ((obj[i].x+obj[i].tamanho)>=(jogador->x-jogador->tamanho)) && ((obj[i].x-obj[i].tamanho)<=(jogador->x+jogador->tamanho)) && obj[i].estado == ativo ) {
	      obj[i].estado=inativo;
    	}
	  }
	  else{
	  	obj[i].estado = inativo;
	    nParadasCriadas=createParada(obj, i, tamOrtX ,tamOrty, nParadasCriadasPorExecucao, nParadasCriadas);
	  }
  	}
}
void setupParada(struct parada obj[]){
	for (int i = 0; i < qntParadas; ++i) {
      obj[i].estado = inativo;
  	}
}