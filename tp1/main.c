#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "personagem.h"
#include "parada.h"

//Variaveis globais
struct parametrosJogo parametro;
struct personagem jogador;
struct parada obj[qntParadas];

void animacao (){
  parametro.tempoDeJogo++;
  paradasCaem(obj , &jogador, parametro);
  parametro.tempoEntreCriaParadas++;
  if (parametro.tempoEntreCriaParadas>45)
    parametro.tempoEntreCriaParadas = 0;
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
    parametro.tamanhoTela.x = 500;
    parametro.tamanhoTela.y =600;
    jogador=setupPersonagem(jogador,-50,-50,25,3);
    setupParada(obj, parametro);
    setupParametros(&parametro);  
}

// Callback de redimensionamento
void redimensiona(int w, int h) {
   glViewport(0, 0, 500, 500);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-w/2, w/2, -h/2, h/2, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   parametro.tamanhoTela.x= w;
   parametro.tamanhoTela.y= h;
}
void teclaEspecial(int key, int x, int y){
  switch(key) {
      // Tecla ESC
      case GLUT_KEY_RIGHT:
        jogador.coordenadas.x = moveRight(jogador, parametro.tamanhoTela.x);
        break;
      case GLUT_KEY_LEFT:
        jogador.coordenadas.x = moveLeft(jogador, parametro.tamanhoTela.x);
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
      case 'r':
      case 'R':
        //funcao q reinicia;
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
    inicializa();
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclaEspecial);
    glutIdleFunc(animacao);
    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}
