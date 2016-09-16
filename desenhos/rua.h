#include <windows.h>
#include <gl/glut.h>

void desenhaRua(GLfloat windowWidth, int nivelAltura) {
    //RUA
     glBegin(GL_QUADS);
               glColor3f(0.5f, 0.5f, 0.5f);
               glVertex2i(0.0, 120.0 + (120.0 * nivelAltura)); 
               glVertex2i(windowWidth, 120.0 + (120.0 * nivelAltura));
               glVertex2i(windowWidth, 30.0 + (120.0 * nivelAltura));
               glVertex2i(0.0, 30.0 + (120.0 * nivelAltura));               
     glEnd();
     // Divisoria Rua
     glBegin(GL_LINES);
               glColor3f(2.0f,2.0f,2.0f);
               glVertex2i(0, 75.0 + (120.0 * nivelAltura)); 
               glVertex2i(windowWidth, 75.0 + (120.0 * nivelAltura));
     glEnd(); 
}
