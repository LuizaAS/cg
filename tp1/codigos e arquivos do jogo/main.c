#include "GL/glew.h"
#include "GL/freeglut.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.hpp>
#include "menu.h"
#include "parada.h"
#include "textura.h"
#include "personagem.h"
#include "animacoes.h"

//Variaveis globais
struct parametrosJogo parametro;
struct personagem jogador;
struct parada obj[qntParadas];

sf::Music musicColisao,musicGameOver,musicJogo,musicWin,musicInicial;
void musicaColisao(){
  musicColisao.play();
}
void animacao (){
  int aux;
  if (parametro.telaAtual==jogo)
  {
    parametro.tempoDeJogo++;
    paradasCaem(obj , &jogador, &parametro);
    parametro.tempoEntreCriaParadas++;
    piscaPersonagem (&jogador, &parametro.telaAtual);
    if (parametro.telaAtual==gameOver){
      musicJogo.stop();
      musicGameOver.play();
    }
    if (parametro.tempoEntreCriaParadas>parametro.constanteTempo)
      parametro.tempoEntreCriaParadas = 0;
    if (parametro.tempoDeJogo>tempoTotal){
      parametro.telaAtual=Win;
      musicJogo.stop();
      musicWin.play();
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
          musicJogo.stop(); 
          musicInicial.setLoop(true);
          musicInicial.play();
        }
        else if(clique(mouse, parametro.nao))
            parametro.telaAtual=parametro.telaAnterior;
        break;
      case inicial:
        if(clique(mouse, parametro.play)){
          reinicia(&parametro, obj, &jogador);
          parametro.telaAtual=jogo;
          musicInicial.stop();
          musicJogo.play();
        }
        break;
    }
  }
}
void teclaEspecial(int key, int x, int y){
  switch(key) {
    case GLUT_KEY_RIGHT:
      moveRight(&jogador, parametro.tamanhoTela.x);
      break;
    case GLUT_KEY_LEFT:
      moveLeft(&jogador, parametro.tamanhoTela.x);
      break;
    default:
      break;
  }
  if (parametro.telaAtual==gameOver||parametro.telaAtual== Win){
    parametro.telaAtual=inicial;
    musicGameOver.stop();
    musicWin.stop();
    musicInicial.setLoop(true);
    musicInicial.play();
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
      if (parametro.telaAtual==pausa){
        parametro.telaAtual=jogo;
        musicJogo.play();
      }
      else if (parametro.telaAtual==jogo){
          parametro.telaAtual=pausa;
          musicJogo.pause();
      }
    default:
      break;
  }
  if (parametro.telaAtual==gameOver||parametro.telaAtual== Win){
    parametro.telaAtual=inicial;
    musicGameOver.stop();
    musicWin.stop(); 
    musicInicial.setLoop(true);
    musicInicial.play();
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
    jogador=setupPersonagem(jogador,-50,-150,30,3);
    setupParada(obj, parametro);
    setupParametros(&parametro);  
    musicColisao.openFromFile("audios/colisao.ogg");
    musicJogo.openFromFile("audios/jogo.ogg");
    musicWin.openFromFile("audios/win.ogg");
    musicInicial.openFromFile("audios/inicial.ogg");
    musicWin.setVolume(50);
    musicColisao.setVolume(75);
    musicJogo.setVolume(50);
    musicGameOver.setVolume(50);
    musicInicial.setLoop(true);
    musicInicial.play();
    musicGameOver.openFromFile("audios/GameOver.ogg");
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