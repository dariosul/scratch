#include <stdio.h>
#include <GL/glut.h>

int viewportWidth;
int viewportHeight;
GLint clickX1 = 0;
GLint clickX2 = 0;
GLint clickY1 = 0;
GLint clickY2 = 0;

#define CORRECT_Y(y) (viewportHeight - y)

typedef int bool;
#define true 1
#define false 0

void displayRect()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2i(clickX1, clickY1);
    glVertex2i(clickX1, clickY2);
    glVertex2i(clickX2, clickY2);
    glVertex2i(clickX2, clickY1);
    glEnd(); 

    glFlush();
}

void keyboardCallback(unsigned char key, int x, int y)
{
    if (key == 'q') {
        exit(0);
    }
}

void mouseClickCallback(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        int correctedY = CORRECT_Y(y);

        clickX1 = x;
        clickY1 = correctedY;
        clickX2 = x;
        clickY2 = correctedY;

        glutPostRedisplay();
    }
}

void mouseMoveCallback(int x, int y)
{
    clickX2 = x;
    clickY2 = CORRECT_Y(y);

    glutPostRedisplay();
}

void init()
{
    /* Set the clear color to black. */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /* Set the fill color to white. */
    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLfloat) viewportWidth, 0.0, (GLfloat) viewportHeight);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, viewportWidth, viewportHeight);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    viewportWidth = 500;
    viewportHeight = 500;
    glutInitWindowSize(viewportWidth, viewportHeight);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow(argv[0]);
    
    glutDisplayFunc(displayRect);
    
    glutKeyboardFunc(keyboardCallback);
    glutMouseFunc(mouseClickCallback);
    glutMotionFunc(mouseMoveCallback);

    init();

    glutMainLoop();

    return 0;
}
