#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#include "parada.h"

//Variaveis globais
int tamOrtX = 500;
int tamOrty =600;
struct personagem jogador;
struct parada obj[qntParadas];

void animacao (){
  for (int i = 0; i < qntParadas; ++i)  {
    obj[i] = paradasCaem( obj[i] , tamOrtX, tamOrty);
    if(((obj[i].y+obj[i].tamanho)>=(jogador.y-jogador.tamanho)) && ((obj[i].y-obj[i].tamanho)<=(jogador.y+jogador.tamanho) )&& ((obj[i].x+obj[i].tamanho)>=(jogador.x-jogador.tamanho)) && ((obj[i].x-obj[i].tamanho)<=(jogador.x+jogador.tamanho)) && obj[i].estado == ativo ) {
      obj[i].estado=inativo;
      printf("-1vida\n");
    }
  }
  glutPostRedisplay();
}
//LOGICA DE UM QUADRADO



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
    desenhaParada(obj);
    glutSwapBuffers();
}
// Inicia algumas vari�veis de estado
void inicializa(void) {
    // cor para limpar a tela
    glClearColor(1, 1, 1, 0);// branco
    jogador=setupPersonagem(jogador,-50,-50,25,3);
    // obj=setupParada(obj);
    for (int i = 0; i < qntParadas; ++i) {
      obj[i].estado = inativo;
    }
    obj[0] = createParada(obj[0], tamOrtX, tamOrty);   
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
    glutIdleFunc(animacao);
    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}
