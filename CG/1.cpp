//1-Recrie esse desenho o mais fielmente possível:


#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha o casco do barco (retângulo vermelho)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, -0.2f);
        glVertex2f(0.6f, -0.2f);
        glVertex2f(0.4f, 0.0f);
        glVertex2f(-0.4f, 0.0f);
    glEnd();

    // Desenha o mastro (retângulo marrom)
    glColor3f(0.5f, 0.25f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.05f, 0.0f);
        glVertex2f(0.05f, 0.0f);
        glVertex2f(0.05f, 0.5f);
        glVertex2f(-0.05f, 0.5f);
    glEnd();

    // Desenha a vela (triângulo cinza)
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(-0.4f, 0.0f);
        glVertex2f(0.4f, 0.0f);
    glEnd();

    // Desenha a bandeira (retângulo azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.3f, 0.5f);
        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.0f, 0.6f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Barco");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 0.9f, 1.0f); // Cor de fundo
    glutMainLoop();
    return 0;
}
