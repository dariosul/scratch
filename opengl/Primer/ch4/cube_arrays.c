#include <GL/glut.h>

GLfloat vertices[][3] = {{-1.0, -1.0, -1.0}, {-1.0, -1.0, 1.0},
                         {1.0, -1.0, 1.0}, {1.0, -1.0, -1.0},
                         {-1.0, 1.0, -1.0}, {-1.0, 1.0, 1.0},
                         {1.0, 1.0, 1.0}, {1.0, 1.0, -1.0}};

GLfloat colors[][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0},
                       {1.0, 1.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0},
                       {0.0, 1.0, 1.0}, {0.5, 0.5, 0.5}};

/* Indices of cube, going counterclockwise. */
GLubyte cubeIndices[] = { 0, 3, 2, 1, 
                          2, 3, 7, 6,
                          0, 4, 7, 3,
                          1, 2, 6, 5,
                          4, 5, 6, 7,
                          0, 1, 5, 4 };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0, 
              0.0, 0.0, 0.0, 
              0.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) width / (GLfloat) height, 0.1, 12);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    
    glShadeModel(GL_FLAT);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cube");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();

    return 0;
}
