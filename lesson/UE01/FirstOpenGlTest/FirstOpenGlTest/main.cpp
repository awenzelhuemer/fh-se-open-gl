#include <cstdlib>

#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

#define KEY_SPACE 32
#define KEY_ESCAPE 27

using namespace std;
int windowid;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0.0, 1.0); // clear color is yellow
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case KEY_SPACE: // space
			glClearColor(0.0, 1.0, 1.0, 1.0); // clear color is cyan
			glutSwapBuffers();
			break;
		case 'g': // lowercase character 'g' pressed
			glClearColor(0.0, 1.0, 0.0, 1.0); // clear color is green
			glutSwapBuffers();
			break;
		case 'a': // lowercase character 'a' pressed
			cout << "You just pressed 'a'" << endl;
			break;
		case KEY_ESCAPE: // escape key pressed
			glutDestroyWindow(windowid);
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void onMouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "Left button clicked at position " << "x: " << x << " y: " << y << endl;
	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		glClearColor(1.0, 0, 0, 1.0); // clear color is red
		glutSwapBuffers();
	}
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // rgba color schema, double buffering
	glutInitWindowPosition(500, 500); // determines the initial position of the window
	glutInitWindowSize(800, 600); // determines the size of the window
	windowid = glutCreateWindow("OpenGL First Window"); // create and name window
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(onMouseClick);

	glutMainLoop(); // start the main loop of GLUT

	return EXIT_SUCCESS;
}