#include <stdlib.h>
#include <GL/glut.h>

#include "callback.h"

void keyboard(unsigned char key, int, int)
{
    switch (key)
    {
    case '\x1B':
        exit(EXIT_SUCCESS);
        break;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();
}
