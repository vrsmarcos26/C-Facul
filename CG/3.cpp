//3-Desenhe um quadrado vermelho na tela e programe para que ele sofra uma translação para cima (eixo Y positivo)  toda vez que apertar a barra de espaço.

#include <GL/glut.h>

float yPosition = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha o quadrado vermelho
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, yPosition, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == ' ') { // Barra de espaço
        yPosition += 0.1f; // Move para cima
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Quadrado Translação");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
