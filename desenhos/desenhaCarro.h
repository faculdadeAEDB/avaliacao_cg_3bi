#include <windows.h>
#include <gl/glut.h>

void desenhaCarro(
    GLfloat posicaoX,
    GLfloat tamanhoCarro,
    int faixa,
    int pista,
    GLfloat R,
    GLfloat G,
    GLfloat B
) {
    float alturaFaixa = 30.0f;
    if(faixa == 0) {
        alturaFaixa = 0.0f;
    }

    glBegin(GL_QUADS);
               glColor3f(R, G, B);
               glVertex2i(posicaoX, 50.0 + alturaFaixa + 120.0 * pista); 
               glVertex2i(posicaoX, 70.0 + alturaFaixa + 120.0 * pista);
               glVertex2i(posicaoX+tamanhoCarro, 70.0 + alturaFaixa + 120.0 * pista);
               glVertex2i(posicaoX+tamanhoCarro, 50.0 + alturaFaixa + 120.0 * pista);
     glEnd();
}
