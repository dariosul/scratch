/*
 * Draws two spinning rectangles, one in a single buffered window and 
 * another in a double buffered window.  Right clicking in the single
 * buffered window pauses both windows; left clicking resumes.  Right
 * clicking in the double buffered window brings up a menu with the 
 * option to quite the application.
 */

#include <math.h>
#include <GL/glut.h>

#define DEG_TO_RAD 0.017453
GLfloat theta = 0.0;
int singleBufferedWindowId;
int doubleBufferedWindowId;

void displayCallback()
{
    // Make sure the window is cleared.
    glClear(GL_COLOR_BUFFER_BIT);
   
    GLfloat sinTheta = sin(DEG_TO_RAD * theta);
    GLfloat cosTheta = cos(DEG_TO_RAD * theta);
 
    glBegin(GL_POLYGON);
    glVertex2f(cosTheta, sinTheta);
    glVertex2f(-sinTheta, cosTheta);
    glVertex2f(-cosTheta, -sinTheta);
    glVertex2f(sinTheta, -cosTheta);
    glEnd();

    int currentWindow = glutGetWindow();
    if (currentWindow == singleBufferedWindowId) {
        glFlush();
    } else if (currentWindow == doubleBufferedWindowId) {
        glutSwapBuffers();
    }
}

void spinDisplay()
{
    theta += 2.0;
    if (theta > 360.0) {
        theta -= 360.0;
    }

    glutSetWindow(singleBufferedWindowId);
    glutPostWindowRedisplay(singleBufferedWindowId);

    glutSetWindow(doubleBufferedWindowId);
    glutPostWindowRedisplay(doubleBufferedWindowId);
}

void mouseCallback(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutIdleFunc(spinDisplay);
    }
    
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glutIdleFunc(NULL);
    }
}

void keyboardCallback(unsigned char key, int x, int y)
{
    if (key == 'q') {
        exit(0);
    }
}

void quitMenu(int id)
{
    if (id == 1) {
        exit(0);
    }
}

void reshapeCallback(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLfloat) viewportWidth, 0.0, (GLfloat) viewportHeight);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, viewportWidth, viewportHeight);
}*/

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    /* Create a single buffered window. */
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    singleBufferedWindowId = glutCreateWindow("Single buffered");
    //init();
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutIdleFunc(spinDisplay);
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);

    /* Create a double buffered window. */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(310, 0);
    doubleBufferedWindowId = glutCreateWindow("Double buffered");
    //init();
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutIdleFunc(spinDisplay);
    glutMouseFunc(mouseCallback);

    glutCreateMenu(quitMenu);
    glutAddMenuEntry("quit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return 0;
}
