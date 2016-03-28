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

//Variaveis globais
struct parametrosJogo parametro;
struct personagem jogador;
struct parada obj[qntParadas];

void animacao (){
  int aux;
  if (parametro.telaAtual==jogo){
    parametro.tempoDeJogo++;
    paradasCaem(obj , &jogador, &parametro);
    parametro.tempoEntreCriaParadas++;
    piscaPersonagem (&jogador);
    if (parametro.tempoEntreCriaParadas>parametro.constanteTempo)
      parametro.tempoEntreCriaParadas = 0;
    if (parametro.tempoDeJogo>tempoTotal){
          parametro.telaAtual=Win;
          printf("%d\n", parametro.tempoDeJogo);
    }
  }
  glutPostRedisplay();
}

void desenhaCena(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4f(1,1,1,1);
  desenhaFundo(parametro);
  if(parametro.telaAtual==jogo){
    desenhaPersonagem(jogador, parametro.tamanhoTela);
    desenhaParada(obj);
  }
  glutSwapBuffers();
}

void redimensiona(int w, int h) {
    float ra=w/h; // razao de aspecto (nao funciona)
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-w/2, w/2, -h/2, h/2, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   parametro.tamanhoTela.x= w;
   parametro.tamanhoTela.y= h;
}
void mouse (int button, int state, int x, int y) { 
  struct posicao mouse;
  converteCoordenadas(x, y,&mouse, parametro.tamanhoTela);
  if (button==GLUT_LEFT_BUTTON){
    switch(parametro.telaAtual){
      case jogo:
        break;
      case confirmaSair:
        if(clique(mouse, parametro.sim))
          exit(0);
        else if(clique(mouse, parametro.nao))
          parametro.telaAtual=parametro.telaAnterior;
        break;
      case confirmaReiniciar:
        if(clique(mouse, parametro.sim)){
          parametro.telaAtual=inicial;
          reinicia(&parametro, obj, &jogador);
        }
        else if(clique(mouse, parametro.nao))
            parametro.telaAtual=parametro.telaAnterior;
        break;
      case inicial:
        if(clique(mouse, parametro.play)){
          reinicia(&parametro, obj, &jogador);
          parametro.telaAtual=jogo;
        }
        break;
    }
  }
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
  if (parametro.telaAtual==gameOver||parametro.telaAtual== Win){
    parametro.telaAtual=inicial;
  }
  glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y) {
  switch(key) {
    case 27:
      parametro.telaAnterior = parametro.telaAtual;
      parametro.telaAtual = confirmaSair;
      break;
    case 'r':
    case 'R':
      parametro.telaAnterior = parametro.telaAtual;
      parametro.telaAtual = confirmaReiniciar;
      break;
    case 'p':
    case 'P':
      if (parametro.telaAtual==pausa)
        parametro.telaAtual=jogo;
      else{
        if (parametro.telaAtual==jogo)
          parametro.telaAtual=pausa;
      }
    default:
      break;
  }
  if (parametro.telaAtual==gameOver||parametro.telaAtual== Win){
    parametro.telaAtual=inicial;
  }
  glutPostRedisplay();
}

void inicializa() {
    glClearColor(1, 1, 1, 0);
    texturaParametro(&parametro);
    texturaParada(obj);
    texturaPersonagem(&jogador);
    jogador.texturaVidas=texturaVida(jogador.texturaVidas);
    parametro.tamanhoTela.x = 500;
    parametro.tamanhoTela.y =600;
    glutReshapeFunc(redimensiona);
    jogador=setupPersonagem(jogador,-50,-50,30,3);
    setupParada(obj, parametro);
    setupParametros(&parametro);  
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Luiza TP1");
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    srand(time(NULL));
    inicializa();
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouse);
    glutSpecialFunc(teclaEspecial);
    glutIdleFunc(animacao);
    glutMainLoop();
    return 0;
}