//2-Desenhe este símbolo:

#include <GL/glut.h>
#include <cmath>

void drawCircle(float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro do círculo
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Círculos concêntricos
    drawCircle(0.6f, 0.0f, 0.0f, 0.5f); // Azul escuro
    drawCircle(0.4f, 0.0f, 0.0f, 0.7f); // Azul médio
    drawCircle(0.2f, 0.0f, 0.0f, 1.0f); // Azul claro

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Alvo");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fundo branco
    glutMainLoop();
    return 0;
}
