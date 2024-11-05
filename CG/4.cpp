//4-Fazer uma animação de um quadrado roxo se movendo de um lado para o outro sem parar no eixo X.

#include <GL/glut.h>

float xPosition = -1.0f;
float direction = 0.01f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha o quadrado roxo
    glColor3f(0.5f, 0.0f, 0.5f);
    glPushMatrix();
    glTranslatef(xPosition, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glFlush();
}

void timer(int) {
    if (xPosition > 1.0f || xPosition < -1.0f) {
        direction = -direction; // Inverte a direção
    }
    xPosition += direction;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Animação Quadrado");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
