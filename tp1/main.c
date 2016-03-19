#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "parada.h"
#include "personagem.h"


//Variaveis globais
struct parametrosJogo parametro;
struct personagem jogador;
struct parada obj[qntParadas];

void animacao (){
  int aux;
  parametro.tempoDeJogo++;
  paradasCaem(obj , &jogador, &parametro);
  parametro.tempoEntreCriaParadas++;
  piscaPersonagem (&jogador);
  if (parametro.tempoEntreCriaParadas>40)
    parametro.tempoEntreCriaParadas = 0;
  glutPostRedisplay();
}

void desenhaCena(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  desenhaFundo(parametro);
  if(parametro.telaAtual==jogo){
    desenhaPersonagem(jogador, parametro.tamanhoTela);
    desenhaParada(obj);
  }
  glutSwapBuffers();
}
// Inicia algumas vari�veis de estado

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
    case GLUT_KEY_RIGHT:
      jogador.coordenadas.x = moveRight(jogador, parametro.tamanhoTela.x);
      break;
    case GLUT_KEY_LEFT:
      jogador.coordenadas.x = moveLeft(jogador, parametro.tamanhoTela.x);
      break;
    default:
      break;
  }
  if (parametro.telaAtual==gameOver){
    inicializa(&parametro, &jogador, obj);
    parametro.telaAtual=inicial;
  }
  glutPostRedisplay();
}
// Callback de evento de teclado
void teclado(unsigned char key, int x, int y) {
  switch(key) {
    case 27:
      exit(0);
      break;
    case 'r':
    case 'R':
      if (parametro.telaAtual==jogo){
        parametro.telaAtual=inicial;
        inicializa(&parametro, &jogador, obj);
      }
      break;
    case 'p':
    case 'P':
      if (parametro.telaAtual==pausa)
        parametro.telaAtual=jogo;
      else{
        if (parametro.telaAtual==jogo)
          parametro.telaAtual=pausa;
      }
    case 's':
    case 'S':
      if (parametro.telaAtual==inicial)
        parametro.telaAtual=jogo;
    default:
      break;
  }
  if (parametro.telaAtual==gameOver){
    parametro.telaAtual=inicial;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Luiza TP1");
    srand(time(NULL));
    inicializa(&parametro, &jogador, obj);
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclaEspecial);
    glutIdleFunc(animacao);
    glutMainLoop();
    return 0;
}