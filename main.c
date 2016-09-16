#include <windows.h>
#include <gl/glut.h>
#include "desenhos/rua.h"
#include "desenhos/desenhaCarro.h"

GLsizei rsize = 50; 
// Carro1
GLfloat x1 = 250.0f;
GLfloat y1 = 300.0f;
GLfloat corA1 = 1.0f;
GLfloat corB1 = 0.0f;
// Carro2
GLfloat x2 = -50.0f;
GLfloat y2 = 50.0f;
GLfloat corA2 = 1.0f;
GLfloat corB2 = 0.0f;
// Carro3
GLfloat x3 = 250.0f;
GLfloat y3 = 300.0f; 
GLfloat corA3 = 1.0f;
GLfloat corB3 = 0.0f;
// Carro4
GLfloat x4 = 0.0f;
GLfloat y4 = 50.0f;
GLfloat corA4 = 1.0f;
GLfloat corB4 = 0.0f;                                                   

// Tamanho do incremento nas direções x e y 
// (número de pixels para se mover a cada
// intervalo de tempo)
GLfloat xstep = -2.0f;
GLfloat ystep = -2.0f;
GLfloat xstep2 = 2.0f;
GLfloat ystep2 = 2.0f;
GLfloat xstep3 = -4.0f;
GLfloat ystep3 = -4.0f;
GLfloat xstep4 = 3.0f;
GLfloat ystep4 = 3.0f;


// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

// Posição do personagem
GLfloat personagemX = 200;
GLfloat personagemY = 10;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     glColor3f(0.5f, 0.5f, 0.5f);

     //RUAS
     desenhaRua(windowWidth, 0);
     desenhaRua(windowWidth, 1);
     
     // Personagem
     glBegin(GL_QUADS);
               glColor3f(1.0f, 1.0f, 1.0f);
               glVertex2i(personagemX, personagemY); 
               glVertex2i(personagemX, personagemY + 10);
               glVertex2i(personagemX + 10, personagemY + 10);
               glVertex2i(personagemX + 10, personagemY);
     glEnd();
            
     // Carro1
     // posicaoX, tamanhoCarro, faixa (0 ou 1), pista (0 ou 1), R, G, B
     desenhaCarro(x1, rsize, 0, 0, 0.0f, corB1, corA1);
     // Carro2
     // posicaoX, tamanhoCarro, faixa (0 ou 1), pista (0 ou 1), R, G, B
     desenhaCarro(x2, rsize, 1, 0, corA2, 1.0f, corB2);  
     // Carro3
     desenhaCarro(x3, rsize, 0, 1, corB3, 0.0f, corA3);
     // Carro4
     desenhaCarro(x4, rsize, 1, 1, corA4, corB4, 1.0f); 

     // Executa os comandos OpenGL
     glutSwapBuffers();
}

void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
                  personagemY = 10;
                  personagemX = windowWidth / 2.0;
    }
    glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) {
        if(personagemY < windowHeight)
           personagemY += 10;
        else {
           personagemY = 10;
           personagemX = windowWidth / 2.0;
        }
    }
    if(key == GLUT_KEY_DOWN) {
        if(personagemY > 10)
           personagemY -= 10;
    }
    if(key == GLUT_KEY_LEFT) {
        if(personagemX > 0)
           personagemX -= 10;
    }
    if(key == GLUT_KEY_RIGHT) {
        if(personagemX < windowWidth - 20)
           personagemX += 10;
    }    
    glutPostRedisplay();
}

void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case '1': // Facil
                     xstep = -2.0f;
                     ystep = -2.0f;
                     xstep2 = 2.0f;
                     ystep2 = 2.0f;
                     xstep3 = -4.0f;
                     ystep3 = -4.0f;
                     xstep4 = 3.0f;
                     ystep4 = 3.0f;
                     break;
            case '2': // Medio
                     xstep = -2.0f * 2.0;
                     ystep = -2.0f * 2.0;
                     xstep2 = 2.0f * 2.0;
                     ystep2 = 2.0f * 2.0;
                     xstep3 = -4.0f * 2.0;
                     ystep3 = -4.0f * 2.0;
                     xstep4 = 3.0f * 2.0;
                     ystep4 = 3.0f * 2.0;
                     break;
            case '3': // Dificil
                     xstep = -2.0f * 3.0;
                     ystep = -2.0f * 3.0;
                     xstep2 = 2.0f * 3.0;
                     ystep2 = 2.0f * 3.0;
                     xstep3 = -4.0f * 3.0;
                     ystep3 = -4.0f * 3.0;
                     xstep4 = 3.0f * 3.0;
                     ystep4 = 3.0f * 3.0;
                     break;
    }
    glutPostRedisplay();
}

// Função callback chamada pela GLUT a cada intervalo de tempo
// (a window não está sendo redimensionada ou movida)
void Timer(int value)
{
    // Retorna pra posição inicial quando atravessa a tela
      if(x1 < -50) {
            x1 = windowWidth;
            y1 = 300.0f;
            
            if(corA1 == 1.0f) {
                        corA1 = 0.0f;
                        corB1 = 1.0f;
            } else {
                        corA1 = 1.0f;
                        corB1 = 0.0f;
            }
      }
      if(x2 > windowWidth-rsize + 50) {
            x2 = -50.0f;
            y2 = 50.0f;
            
            if(corA2 == 1.0f) {
                        corA2 = 0.0f;
                        corB2 = 1.0f;
            } else {
                        corA2 = 1.0f;
                        corB2 = 0.0f;
            }
      }
      if(x3 < -50) {
            x3 = windowWidth;
            y3 = 300.0f;
            
            if(corA3 == 1.0f) {
                        corA3 = 0.0f;
                        corB3 = 1.0f;
            } else {
                        corA3 = 1.0f;
                        corB3 = 0.0f;
            }
      }
      if(x4 > windowWidth-rsize + 50) {
            x4 = -50.0f;
            y4 = 50.0f;
            
            if(corA4 == 1.0f) {
                        corA4 = 0.0f;
                        corB4 = 1.0f;
            } else {
                        corA4 = 1.0f;
                        corB4 = 0.0f;
            }
      }
    
    if(
        (x1 < personagemX && x1 + rsize > personagemX) && (personagemY > (50.0 + 0 + 120.0 * 0) - 10 && personagemY < (50.0 + 0 + 120.0 * 0) + 20) ||
        (x2 < personagemX && x2 + rsize > personagemX) && (personagemY > (50.0 + 30.0 + 120.0 * 0) - 10 && personagemY < (50.0 + 30.0 + 120.0 * 0) + 20) ||
        (x3 < personagemX && x3 + rsize > personagemX) && (personagemY > (50.0 + 0 + 120.0 * 1) - 10 && personagemY < (50.0 + 0 + 120.0 * 1) + 20) ||
        (x4 < personagemX && x4 + rsize > personagemX) && (personagemY > (50.0 + 30.0 + 120.0 * 1) - 10 && personagemY < (50.0 + 30.0 + 120.0 * 1) + 20)
    ) {
        personagemY = 10;
        personagemX = windowWidth / 2.0;
    }

    // Move o Carro1
    x1 += xstep;
    y1 += ystep;
    // Move o Carro2
    x2 += xstep2;
    y2 += ystep2;
    // Move o Carro3
    x3 += xstep3;
    y3 += ystep3;
    // Move o Carro4
    x4 += xstep4;
    y4 += ystep4;

    // Redesenha o quadrado com as novas coordenadas 
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
     // Evita a divisao por zero
     if(h == 0) h = 1;
                           
     // Especifica as dimensões da Viewport
     glViewport(0, 0, w, h);

     // Inicializa o sistema de coordenadas
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     // Estabelece a janela de seleção (left, right, bottom, top)     
     if (w <= h)  {
		windowHeight = 250.0f*h/w;
		windowWidth = 250.0f;
     }
     else  { 
		windowWidth = 250.0f*w/h;
		windowHeight = 250.0f;
     }
     
     gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal 
int main(void)
{
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Roberto Oliveira 14257042");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutTimerFunc(33, Timer, 1);
     glutKeyboardFunc(GerenciaTeclado);
     glutMouseFunc(GerenciaMouse);
     glutSpecialFunc(TeclasEspeciais); 
     Inicializa();
     glutMainLoop();
}

