#include <math.h>

/* glut.h includes gl.h and glu.h.  Probably would be better to include
   them explicitly though. */
#include <GL/glut.h>

#define DEG_TO_RAD 0.017453
GLfloat theta = 0.0;

void idle()
{
    theta += 0.01;
    if (theta > 360.0) {
        theta -= 360.0;
    }
    glutPostRedisplay();
}

void display()
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

    glFlush();
}

void init()
{
    /* Set the clear color to black. */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /* Set the fill color to white. */
    glColor3f(1.0, 1.0, 1.0);

    /* Set up standard orthogonal view with clipping box as a cube with
       side length 2 centered at the origin.  This is the default view and
       these statements could be removed. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    /* Initialize mode and open a window in the upper-left corner of 
       the screen.  Window title is the name of the program. */

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
 
    glutCreateWindow(argv[0]);

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    init();
    
    glutMainLoop();

    return 0;
}

