// Algoritma DDA
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL\freeglut.h>
#include <GL\glut.h>
#include <math.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void dda(void);

//  posisi window di layar
int window_x;
int window_y;

void init()
{ 
	glClearColor(1.0, 1.0, 1.0, 1.0); //set warna background 
	glColor3f(0.0, 0.0, 0.0); //set warna titik
	glPointSize(4.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	dda(); //panggil fungsi dda 
	glutSwapBuffers(); //swap buffer 
}

void dda(void) {
	int x1, y1, x2, y2;
	float x,y,dx, dy, steps, x_inc, y_inc;
	//tentukan titik awal dan akhir
	x1 = 100;
	y1 = 200;
	x2 = 300;
	y2 = 400;
	x = x1;
	y = y1;

	//hitung dx dan dy
	dx = x2 - x1;
	dy = y2 - y1;

	//hitung steps
	if (dx > dy) {
		steps = dx;
	}
	else steps = dy;

	//hitung perubahan nilai x (x_inc) dan y (y_inc)
	x_inc = dx / steps;
	y_inc = dy / steps;

	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y); // gambar titik awal

	//perulangan untuk menggambar titik-titik 
	do {
		x += x_inc; // x = x + x_inc
		y += y_inc; // y = y + y_inc
		glVertex2i(round(x), round(y)); //gambar titik
	} while (x < x2);

	glEnd();
	glFlush();
}

//  Membuat window program
int main (int argc, char **argv) { 
  glutInit(&argc,argv); 
  glutCreateWindow("Algoritma DDA");
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
  init(); 
  glutDisplayFunc(display);
  glutMainLoop();
}
