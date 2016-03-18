#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "personagem.h"
#include "parada.h"

//Variaveis globais
int tamOrtX = 500;
int tamOrty =600;
struct personagem jogador;
struct parada obj[qntParadas];

void animacao (){
  paradasCaem( obj, &jogador, tamOrtX, tamOrty);
  glutPostRedisplay();
}

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
    setupParada(obj);
   /* for (int i = 0; i < qntParadas; ++i) {
      obj[i].estado = inativo;
    }*/
    createParada(obj, 0, tamOrtX, tamOrty, 1, 0);   
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
    srand(time(NULL));
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
