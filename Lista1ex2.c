#include "GL/glew.h"
#include "GL/freeglut.h"
#include "stdio.h"

// cmpilar usando g++ no linux
GLint contador = 0, listaAnel;
void criaListaAnelQuadrado(){
    listaAnel = glGenLists(1);
    glNewList(listaAnel, GL_COMPILE);
        glBegin(GL_TRIANGLE_FAN);
                glVertex3f(-10, 10, 0.0);
                glVertex3f(10, 10, 0.0);
                glVertex3f(5, 5, 0.0);
                glVertex3f(-5, 5, 0.0);
                glVertex3f(-10, -10, 0.0);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
                glVertex3f(-10, -10, 0.0);
                glVertex3f(-5, 5, 0.0);
                glVertex3f(-5, -5, 0.0);
                glVertex3f(10,- 10, 0.0);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
                glVertex3f(10,- 10, 0.0);
                glVertex3f(-5, -5, 0.0);
                glVertex3f(5, -5, 0.0);
                glVertex3f(10, 10, 0.0);
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
                glVertex3f(10, 10, 0.0);
                glVertex3f(5, 5, 0.0);
                glVertex3f(5, -5, 0.0);
        glEnd();
  glEndList();
}

void desenhaCena(void)
{
    // Limpa a tela (com a cor definida por glClearColor(r,g,b)) para que
    // possamos desenhar
    glClear(GL_COLOR_BUFFER_BIT);

    // Começa a usar a cor amarela
    if (contador%2==0){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(0, 1.0, 1.0);
    }
    else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0, 0, 0);
    }
    

    // Começa a desenhar um pol�gono com os v�rtices especificados
    glCallList(listaAnel);
    // Diz ao OpenGL para colocar o que desenhamos na tela
    glutSwapBuffers();
}

// Inicia algumas vari�veis de estado
void inicializa(void)
{
    // cor para limpar a tela
    glClearColor(1, 1, 1, 0);      // branco
}

// Callback de redimensionamento
void redimensiona(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-15, 15, -15, 15, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Callback de evento de teclado
void teclado(unsigned char key, int x, int y)
{
  int l;
   switch(key)
   {
      // Tecla ESC
      case 27:
        exit(0);
        break;
      case 'c':
        contador++;
        glutPostRedisplay();
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
    glutCreateWindow("Luiza L1 exercicio 2");

    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    inicializa();
    criaListaAnelQuadrado();
    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}