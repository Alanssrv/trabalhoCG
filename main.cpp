#include <windows.h> //Biblioteca usada no Windows para uso da glut
#include <GL/glut.h>
#include <math.h>
#include "Camera.h"

void init();
void desenha();
void teclas_especiais(int key, int x, int y);
void teclado(unsigned char key, int x, int y);
void mouse(int x, int y);
void reshape(int w, int h);

void chooseFigure();
void cubo();
void piramide();
void cilindro();

Camera camera(3.f, 0.f, 90.f);

int figure;
float anguloInicial = M_PI/6.0;
float wWidth, wHeight;

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Trabalho CG");

    init();

    glutReshapeFunc(reshape);
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclas_especiais);
    glutMotionFunc(mouse);
    glutMainLoop();

    return 0;
}

void init()
{
    glClearColor(0.55, 0.55, 0.55, 0);

    figure = 1;

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    float globalAmb[] = {0.3, 0.3, 0.3, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

    float light0[4][4] = {
        {0.1, 0.1, 0.1, 1},
        {0.8, 0.8, 0.8, 1},
        {1, 1, 1, 1},
        {5, 5, 5, 1}
    };
    glLightfv(GL_LIGHT0, GL_AMBIENT,  &light0[0][0]);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  &light0[1][0]);
    glLightfv(GL_LIGHT0, GL_SPECULAR, &light0[2][0]);
    glLightfv(GL_LIGHT0, GL_POSITION, &light0[3][0]);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
}

void desenha() {
    wWidth = glutGet(GLUT_WINDOW_WIDTH);
    wHeight = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, wWidth, wHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float altura, largura;

    largura = 4;
    altura = largura*wWidth/wHeight;

    glFrustum(-largura / 2, largura / 2, -altura / 2, altura / 2, 1, 100);

    camera.Ativar();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float matEspecular[] = {1, 1, 1, 1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, matEspecular);
    glMaterialf(GL_FRONT, GL_SHININESS, 128);

    chooseFigure();

    glFlush();
    glutSwapBuffers();
}

void chooseFigure(){
    switch (figure){
        case 1:
            cubo();
            break;
        case 2:
            piramide();
            break;
        case 3:
            cilindro();
            break;
    }
}

void teclas_especiais( int key, int x, int y ) {

    if (key == GLUT_KEY_RIGHT){

    } else if (key == GLUT_KEY_LEFT){

    } else if (key == GLUT_KEY_UP) {

    } else if (key == GLUT_KEY_DOWN){

    }
  
    glutPostRedisplay();

}

void teclado(unsigned char key, int x, int y){
    switch (key) {
        case '1': 
            figure = 1;
            break;
        case '2':
            figure = 2;
            break;
        case '3':
            figure = 3;
            break;
        case 'w':case 'W':
            camera.Forward();
            break;
        case 's':case 'S':
            camera.Back();
            break;
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

void reshape(int w, int h) {
    wHeight = w;
    wHeight = h;   
}

void cubo() {
    //face vermelha
    glNormal3f(0,0,-1);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    //face branca
    glNormal3f(0,0,1);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();

    //face magenta
    glNormal3f(1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glEnd();

    //face verde
    glNormal3f(-1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glEnd();

    //face azul
    glNormal3f(0,1,0);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glEnd();

    //face ciano
    glNormal3f(0,-1,0);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glEnd();
}

void piramide() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();
}

void cilindro(){
    float delta = 2.0*M_PI/25;
    float angulo, x, y;

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i <= 25; i++){
        angulo = anguloInicial + i*delta;
        x = cos(angulo);
        y = sin(angulo);

        glVertex3f(x, y, 1);
        glVertex3f(x, y, -1);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i <= 25; i++){
        angulo = anguloInicial + i*delta;
        x = cos(angulo);
        y = sin(angulo);

        glVertex3f(x, y, 1.0);
    }
    
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for (int i = 25; i >= 0; i--){
        angulo = anguloInicial + i*delta;
        x = cos(angulo);
        y = sin(angulo);

        glVertex3f(x, y, -1.0);
    }
    
    glEnd();
}
