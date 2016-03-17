#include "GL/glew.h"
#include "GL/freeglut.h"
#include <math.h>
GLint nl=3, c;
GLfloat r=0, g=0, b=0, a;

void desenhaCena(void)
{
    // Limpa a tela (com a cor definida por glClearColor(r,g,b)) para que
    // possamos desenhar
    glClear(GL_COLOR_BUFFER_BIT);

    // Começa a usar a cor amarela
   if (c%2==0){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    }
  	glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
      glVertex3f(0, 0, 0);
      glVertex3f(50, 0, 0);
      a=2*M_PI/nl;
      for ( int b = 1, x, y; b<=nl; b++){  
        x= 50*cos(a*b);
        y= 50*sin(a*b);
        glVertex3f(x, y, 0);
      }
    glEnd();

    // Começa a desenhar um pol�gono com os v�rtices especificados

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
   glViewport(0, 0, 500, 500);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100, 100, -100, 100, -1, 1);
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
        c++;
         glutPostRedisplay();
        break;
      case '+':
        nl++;
         glutPostRedisplay();
        break;
      case '-':
        nl--;
        if(nl<3)
      	  nl=3;
        glutPostRedisplay();
        break;
      case 'r':
        r+=0.1;
        if(r>1)
  	  	  r=1;
        glutPostRedisplay();
        break;
      case 'g':
        g+=.1;
        if(g>1)
  	  	  g=1;
        glutPostRedisplay();
        break;
      case 'b':
        b+=.1;
        if(b>1)
  	  	  b=1;
        glutPostRedisplay();
        break;
      case 'R':
        r-=0.1;
        if(r<0)
  	  	  r=0;
        glutPostRedisplay();
        break;
      case 'G':
        g-=.1;
        if(g<0)
  	  	  g=0;
        glutPostRedisplay();
        break;
      case 'B':
        b-=.1;
        if(b<0)
  	  	  b=0;
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    // Abre a janela
    glutCreateWindow("Luiza L1 exercicio 3");

    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    inicializa();

    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}