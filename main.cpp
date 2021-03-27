#include <windows.h> //Biblioteca usada no Windows para uso da glut
#include <GL/glut.h>
#include <math.h>
#include "Camera.h"

void init();
void desenha();
void teclas(int key, int x, int y);
void mouse(int x, int y);

Camera camera(5.f, 90.f, 90.f);

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Trabalho CG");

    init();

    glutDisplayFunc(desenha);
    glutSpecialFunc(teclas);
    glutMotionFunc(mouse);
    glutMainLoop();

    return 0;
}

void init()
{
    glClearColor(0, 0, 0, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
}

void desenha()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float altura, largura;

    float windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    float windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    largura = 2;
    altura = largura*windowWidth/windowHeight;

    glFrustum(-largura / 2, largura / 2, -altura / 2, altura / 2, 1, 100);

    camera.Ativar();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //face vermelha
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    //face branca
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    //face magenta
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    //face verde
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    //face azul
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    //face ciano
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    glFlush();
    // glutSwapBuffers();
}

void teclas( int key, int x, int y ) {

    if (key == GLUT_KEY_RIGHT){

    } else if (key == GLUT_KEY_LEFT){

    } else if (key == GLUT_KEY_UP) {

    } else if (key == GLUT_KEY_DOWN){

    }
  
    glutPostRedisplay();

}

void mouse(int xpos, int ypos){
    static float lastMousePosx = 0.f;
	float dx;
	static float lastMousePosy = 0.f;
	float dy;

    dx = xpos - lastMousePosx;
    if (fabs(dx) > 10.f) dx = 10.f;
    lastMousePosx = xpos;
    camera.UpdateTheta(dx);

    dy = ypos - lastMousePosy;
    if (fabs(dy) > 10.f) dy = 10.f;
    lastMousePosy = ypos;
    camera.UpdatePhi(dy);
    glutPostRedisplay();
    
}