/*
 * Try building this to see if everything is set up correctly.
 */

#include <stdio.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow* createWindowAndContext() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create in windowed mode
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello OpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);

	return window;
}

void initializeGLEW() {
	glewExperimental = GL_TRUE;
	glewInit();
}

void testGLEW() {
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	printf("A '1' should be printed on the next line if GLEW is working:\n");
	printf("%u\n", vertexBuffer);
}

int main() {
	glfwInit();

	GLFWwindow* window = createWindowAndContext();
	initializeGLEW();

	testGLEW();

	while(!glfwWindowShouldClose(window)) {
	    glfwSwapBuffers(window);
	    glfwPollEvents();
	}

	glfwTerminate();
}
