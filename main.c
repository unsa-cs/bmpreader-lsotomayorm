#include "bmp.h"
#include <GL/glut.h>
#include <stdio.h>

BMPImage *image;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  if (image) {
    drawBMP(image);
  }
  glFlush();
}

int main(int argc, char *argv[]) {
  //char filename[256];

  if (argc > 0 && argc < 2) {
    printf("Uso: %s <archivo.bmp>\n", argv[0]);
    return 1;
  } else {
    printf("Cantidad de argumentos incorrecta! Solo debe haber 1 argumento.\n");
    return 0;
  }

  char *filename = argv[1];

  // Pedir al usuario el nombre del archivo BMP
  /* Se comenta como requisito del ejercicio 1
  printf("Ingrese el nombre del archivo BMP (con extensión): ");
  scanf("%255s", filename);
  */

  image = readBMP(filename);
  if (!image) return 1;

  // Inicializar GLUT
  //int argc = 1; // Necesario para evitar problemas con glutInit  	SABOTAJEEE
  //char *argv[1] = { "" }; // Argumento vacío para GLUT		SABOTAJE!! >:V
  glutInit(&argc, argv);

  // Establecer el modo de visualización
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(image->width, image->height);
  glutCreateWindow("Visualizador de BMP");

  glLoadIdentity();
  glOrtho(0, image->width, image->height, 0, -1, 1);

  glutDisplayFunc(display);
  glutMainLoop();

  freeBMP(image);
  return 0;
}
