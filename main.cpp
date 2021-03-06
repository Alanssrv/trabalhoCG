#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "Camera.h"
#include "ObjLoader.h"

void init();
void desenha();
void teclas_especiais(int key, int x, int y);
void teclado(unsigned char key, int x, int y);
void mouse(int x, int y);
void reshape(int w, int h);

void chooseFigure();

Camera camera(4.f, 0.f, 90.f);

static int figure;
static unsigned blenderModelId;
float wWidth, wHeight;

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Trabalho CG");

    init();

    glutDisplayFunc(desenha);
    glutSpecialFunc(teclas_especiais);
    glutKeyboardFunc(teclado);
    glutMotionFunc(mouse);
    glutMainLoop();

    return 0;
}

void init() {
    glClearColor(0.55, 0.55, 0.55, 0);

    figure = 1;

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);

    float globalAmb[] = {0.3, 0.3, 0.3, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

    float light0[4][4] = {
        {0.1, 0.1, 0.1, 1},
        {0.8, 0.8, 0.8, 1},
        {1, 1, 1, 1},
        {5, 5, 0, 1}
    };

    float light1[4][4] = {
        {0.1, 0.1, 0.1, 1},
        {0.8, 0.8, 0.8, 1},
        {1, 1, 1, 1},
        {-5, -5, 0, 1}
    };

    glLightfv(GL_LIGHT0, GL_AMBIENT,  &light0[0][0]);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  &light0[1][0]);
    glLightfv(GL_LIGHT0, GL_SPECULAR, &light0[2][0]);
    glLightfv(GL_LIGHT0, GL_POSITION, &light0[3][0]);

    glLightfv(GL_LIGHT1, GL_AMBIENT,  &light1[0][0]);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  &light1[1][0]);
    glLightfv(GL_LIGHT1, GL_SPECULAR, &light1[2][0]);
    glLightfv(GL_LIGHT1, GL_POSITION, &light1[3][0]);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
}

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float wWidth = glutGet(GLUT_WINDOW_WIDTH);
    float wHeight = glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, wWidth, wHeight);

    reshape(wWidth, wHeight);

    camera.ativar();

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
            ObjLoader::loadObj(blenderModelId, "objetos/1.obj");
            break;
        case 2:
            ObjLoader::loadObj(blenderModelId, "objetos/2.obj");
            break;
        case 3:
            ObjLoader::loadObj(blenderModelId, "objetos/3.obj");
            break;
    }
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
            camera.forward();
            break;
        case 's':case 'S':
            camera.back();
            break;
    }
    glutPostRedisplay();
}

void teclas_especiais(int key, int x, int y) {
}

void mouse(int xpos, int ypos){
    static float lastMousePosx = 0.f;
	float dx;
	static float lastMousePosy = 0.f;
	float dy;

    dx = xpos - lastMousePosx;
    if (fabs(dx) > 10.f) dx = 10.f;
    lastMousePosx = xpos;
    camera.updateTheta(dx);

    dy = ypos - lastMousePosy;
    if (fabs(dy) > 10.f) dy = 10.f;
    lastMousePosy = ypos;
    camera.updatePhi(dy);
    glutPostRedisplay();
    
}

void reshape(int w, int h) {
    float aspect = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, aspect, 0.1, 500);
}