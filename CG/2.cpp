//2-Desenhe este símbolo:

#include <GL/glut.h> // Para usar GLUT.
#include <cmath>

// Função para desenhar um círculo preenchido
void drawCircle(float centerX, float centerY, float radius, float r, float g, float b) {
    glColor3f(r, g, b); // Define a cor (RGB)
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Centro do círculo
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100.0f; // Divide o círculo em 100 partes
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Função para desenhar os círculos concêntricos
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa a tela

    // Desenha os círculos do maior para o menor
    drawCircle(0.0f, 0.0f, 0.8f, 0.1f, 0.1f, 0.3f); // Círculo grande (azul escuro)
    drawCircle(0.0f, 0.0f, 0.6f, 0.0f, 0.0f, 0.6f); // Círculo médio (azul claro)
    drawCircle(0.0f, 0.0f, 0.4f, 0.1f, 0.1f, 0.3f); // Círculo pequeno (azul escuro)
    drawCircle(0.0f, 0.0f, 0.2f, 1.0f, 1.0f, 1.0f); // Bola no centro (branca)

    glFlush(); // Garante que tudo seja desenhado
}

// Configuração inicial da janela OpenGL
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fundo branco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define a visão ortogonal
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800); // Tamanho da janela
    glutCreateWindow("Círculos Concêntricos - OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

