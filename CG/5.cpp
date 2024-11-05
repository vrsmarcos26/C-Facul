//5-Crie uma animação de um círculo multicolorida girando no sentido horário.

#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;

void drawCircle() {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * 3.14159f / 180.0f;
        float r = (i % 3 == 0) ? 1.0f : 0.0f;
        float g = (i % 3 == 1) ? 1.0f : 0.0f;
        float b = (i % 3 == 2) ? 1.0f : 0.0f;
        glColor3f(r, g, b);
        glVertex2f(cos(theta) * 0.5f, sin(theta) * 0.5f);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    drawCircle();
    glPopMatrix();

    glFlush();
}

void timer(int) {
    angle += 2.0f; // Ajusta a velocidade de rotação
    if (angle > 360.0f) {
        angle -= 360.0f; // Mantém o ângulo dentro de 360 graus
    }
    glutPostRedisplay(); // Marca a janela para redesenho
    glutTimerFunc(16, timer, 0); // Chama o timer a cada ~16 ms para 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Círculo Girando");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fundo branco
    glutMainLoop();
    return 0;
}
