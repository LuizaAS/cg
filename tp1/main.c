#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#define qntParadas 20
//Variaveis globais
int tamOrtX= 500;
int tamOrty =600;
struct personagem jogador;
struct parada {
  int x;
  int y;
  GLuint textura;
  int tamanho;
  int tipo;
  int estado;
};

//LOGICA DE UM QUADRADO
struct parada p;
void desenhaParada(){
  if(p.estado==1){
        glPushMatrix();
        glColor3f(0,0,0); 
        glTranslatef(p.x, p.y, 0);
        /*glEnable(GL_TEXTURE_2D);*/
        /*glBindTexture(GL_TEXTURE_2D, perso.textura);*/
        glBegin(GL_QUADS);
          /*glTexCoord2f(0, 0);*/ glVertex3f(-p.tamanho, -p.tamanho,  0);
          /*glTexCoord2f(1, 0);*/ glVertex3f( p.tamanho, -p.tamanho,  0);
          /*glTexCoord2f(1, 1);*/ glVertex3f( p.tamanho,  p.tamanho,  0);
          /*glTexCoord2f(0, 1);*/ glVertex3f(-p.tamanho,  p.tamanho,  0);
        glEnd();
    glPopMatrix();
  glDisable(GL_TEXTURE_2D);
  }
  return;
}
void createParada(){
  if (p.estado==0) {
    p.x=rand()%((tamOrtX/2)-5*p.tamanho);
    if (p.x%2==0)
      p.x*=-1;
    p.tamanho = 10;
    p.y=((tamOrty/2)-p.tamanho);
    p.estado=1;  
  }
    
}
void paradasCaem(){
  if (p.y>-tamOrty/2+5*p.tamanho && p.estado == 1){
    p.y-=1;
  }
  else{
    p.estado=0;
    createParada();
  }
  if(((p.y+p.tamanho)>=(jogador.y-jogador.tamanho)) && ((p.y-p.tamanho)<=(jogador.y+jogador.tamanho) )&& ((p.x+p.tamanho)>=(jogador.x-jogador.tamanho)) && ((p.x-p.tamanho)<=(jogador.x+jogador.tamanho))) {
      p.estado=0;
  }
  glutPostRedisplay();
}
void setupParada(){
  p.estado=0;
}
//LOGICA  DE VARIOS QUADRADOS
// struct parada obj[qntParadas];
// void createParada (int n) {
//   for (int i = 0, j= 0; i < n && j< qntParadas; j++ ) {
//     if (obj[n].estado==0) {
//       obj[n].tamanho = 10;
//       obj[n].x = rand()%tamOrtX;
//       if (obj[n].x%2==0)
//         obj[n].x*=-1;
//       obj[n].y = tamOrty+obj[n].tamanho;
//       obj[n].estado=1;
//       i++;
//     }
//   }
// }

// void desenhaParada(){
//   createParada(rand()%5);
//   glColor3f(0, 0, 0);
//   for (int i = 0; i < qntParadas; ++i) {
//     if (obj[i].estado==1){
//       /*    glPushMatrix();*/                 // Importante!!
//      glTranslatef(obj[i].x, obj[i].y, 0);
//       /*      glEnable(GL_TEXTURE_2D);
//       glBindTexture(GL_TEXTURE_2D, obj[i].textura);*/
//       glBegin(GL_QUADS);
//         // glTexCoord2f(0, 0);
//         glVertex3f(-obj[i].tamanho, -obj[i].tamanho,  0);
//         // glTexCoord2f(1, 0);
//         glVertex3f( obj[i].tamanho, -obj[i].tamanho,  0);
//         // glTexCoord2f(1, 1);
//         glVertex3f( obj[i].tamanho,  obj[i].tamanho,  0);
//         // glTexCoord2f(0, 1);
//         glVertex3f(-obj[i].tamanho,  obj[i].tamanho,  0);
//       glEnd();
//       /*  glPopMatrix();
//       glDisable(GL_TEXTURE_2D);*/
//     }
//   }
//   return;
// }
// void paradasCaem(void){
//   //createParada(rand()%5);
//   for (int i = 0; i < qntParadas; ++i) {
//     if (obj[i].estado==1){
//       obj[i].y-=0.1;
//     }
//   }
//   glutPostRedisplay();
//   // registra a callback novamente
// }

void desenhaCena(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaPersonagem(jogador);
    desenhaParada();
    glutSwapBuffers();
}
// Inicia algumas vari�veis de estado
void inicializa(void) {
    // cor para limpar a tela
    glClearColor(1, 1, 1, 0);// branco
    jogador=setupPersonagem(jogador,-50,-50,25,3);
    setupParada();
    createParada();
/*    for (int i = 0; i < qntParadas; ++i) {
      obj[i].estado = 0;
    }*/
}

// Callback de redimensionamento
void redimensiona(int w, int h) {
   glViewport(0, 0, 500, 500);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-w/2, w/2, -h/2, h/2, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   tamOrtX= w;
   tamOrty= h;
}
void teclaEspecial(int key, int x, int y){
  switch(key) {
      // Tecla ESC
      case GLUT_KEY_RIGHT:
        jogador.x = moveRight(jogador, tamOrtX);
        break;
      case GLUT_KEY_LEFT:
        jogador.x = moveLeft(jogador, tamOrtX);
        break;
      default:
         break;
   }
  glutPostRedisplay();
}
// Callback de evento de teclado
void teclado(unsigned char key, int x, int y) {
   switch(key) {
      // Tecla ESC
      case 27:
        exit(0);
        break;
      default:
         break;
   }
}

// Rotina principal
int main(int argc, char **argv)
{
    // Acordando o GLUT
    glutInit(&argc, argv);
    // Definindo a versão do OpenGL que vamos usar
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    // Configuração inicial da janela do GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    // Abre a janela
    glutCreateWindow("Luiza TP1");
    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclaEspecial);
    inicializa();
    glutIdleFunc(paradasCaem);
    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}
