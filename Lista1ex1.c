#include "GL/glew.h"
#include "GL/freeglut.h"

// variaveis globais

void quadrado(int x, int r){
	for (int y = 20, g=0; y < 200; y=y+80, g=g+3)
	{
		glColor3f((0.1*r), ( 0.1*g), 0.1);
		glBegin(GL_TRIANGLE_FAN);
        	glVertex3f(x, y, 0);
        	glVertex3f(x+60, y, 0);
        	glVertex3f(x+60, y+60, 0);
        	glVertex3f(x, y+60, 0);
    	glEnd();
	}

}

void desenhaCena(void)
{
    // Limpa a tela (com a cor definida por glClearColor(r,g,b)) para que
    // possamos desenhar
    glClear(GL_COLOR_BUFFER_BIT);

    // Começa a usar a cor amarela
    

    // Começa a desenhar um pol�gono com os v�rtices especificados
    for(int x= 20, r= 0 ; x<200; x=x+80, r=r+3){
    	quadrado(x, r);
	}
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
   glOrtho(0, 250, 0, 250, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Callback de evento de teclado
void teclado(unsigned char key, int x, int y)
{
   switch(key)
   {
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
    glutCreateWindow("Luiza L1 exercicio 1");

    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    inicializa();

    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}