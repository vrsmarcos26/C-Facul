//1-Recrie esse desenho o mais fielmente possível:


#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Cor de fundo (amarelo claro)
    glClearColor(1.0f, 0.95f, 0.8f, 1.0f);

    // Base do barco (vermelho)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, -0.5f);
    glVertex2f(0.6f, -0.5f);
    glVertex2f(0.4f, -0.7f);
    glVertex2f(-0.4f, -0.7f);
    glEnd();

    // Vela (cinza) - maior e mais próxima da base
    glColor3f(0.75f, 0.75f, 0.75f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.3f);  // Topo do mastro
    glVertex2f(-0.35f, -0.4f); // Lado esquerdo mais próximo da base
    glVertex2f(0.55f, -0.4f);  // Lado direito mais próximo da base
    glEnd();

    // Mastro (marrom)
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.02f, -0.5f);
    glVertex2f(0.02f, -0.5f);
    glVertex2f(0.02f, 0.3f);
    glVertex2f(-0.02f, 0.3f);
    glEnd();

    // Bandeira (azul) - diretamente acima do mastro
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.02f, 0.3f);   // Alinhado ao topo do mastro
    glVertex2f(0.18f, 0.3f);    // Alinhado horizontalmente
    glVertex2f(0.18f, 0.4f);    // Altura da bandeira
    glVertex2f(-0.02f, 0.4f);   // Retorno ao topo do mastro
    glEnd();

    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Barco em OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
