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

struct parada createParada(struct parada p, int tamOrtX, int tamOrty){
	if (p.estado == inativo) {
	    p.x=rand()%((tamOrtX/2)-5*p.tamanho);
	    if (p.x%2==0)
	      p.x*=-1;
	    p.tamanho = 10;
	    p.y=((tamOrty/2)-p.tamanho);
	    p.estado=ativo;  
  	}
   return p;
}
struct parada paradasCaem(struct parada p, int tamOrtX, int tamOrty){
  if (p.y>-tamOrty/2 && p.estado == ativo){
    p.y-=1;
  }
  else{
  	p.estado = inativo;
    p=createParada(p, tamOrtX ,tamOrty);
    printf("%d\n", p.estado );
  }
    return p;
}
/*struct parada* setupParada(struct parada* p){
	for (int i = 0; i < qntParadas; ++i)	{
		p[i].estado = inativo;
  	
	}
	return *p;
}*/