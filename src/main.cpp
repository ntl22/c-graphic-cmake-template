#include <stdlib.h>
#include <GL/glut.h>

#include "callback.h"

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  
  glutCreateWindow("Hello, World!");
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);

  glutMainLoop();
  return EXIT_SUCCESS;
}
