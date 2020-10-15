#include <GL/glut.h>
#include<iostream>
using namespace std;

int state = 1;

float z_position = -12;
float x_position = 4;


//Drawing funciton
void init(){
    glClearColor(0, 0, 0, 1);
}

void draw(void)
{
  float x = -10.0 , y = 1.0, z = 0;
  float a = 1, b = 0, c = 0;
  //Background color
//   glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );
  glLoadIdentity();

  //camera rotate
  glRotatef(0, -1, 0, 0);

  // Normal Point
  glTranslatef(x_position, 0, z_position);
  //Draw order

  for(int i = 0; i < 9; i++){
    switch (i)
  {
  case 1:
    x = x + 5;
    b = b + 1;
    break;

  case 2:
    x = x + 5;
    c = c + 1;
    break;  

  case 3:
    x = -10;
    z = -5;
    a = 0;
    break;

  case 4:
    x = x + 5;
    z = -5;
    b = 0;
    break;

  case 5:
    x = x + 5;
    z = -5;
    a = 1;
    break;

  case 6:
    x = -10;
    z = -10;
    a = 0;
    b = 1;
    c = 0;
    break;

  case 7:
    x = x + 5;
    a = 1;
    b = 0.5;
    break;

  case 8:
    x = x + 5;
    a = 0.5;
    b = 0;
    c = 1;
    break;
  
  }

  //Front
  glBegin(GL_LINE_STRIP);
    glColor3f(a,b,c);
    glVertex3f(x, y, z); 
    glVertex3f(x, -y, z);
    glVertex3f(x + 2, -y, z); 
    glVertex3f(x + 2, y, z);
    glVertex3f(x, y, z); 
  glEnd();
  //Back
  glBegin(GL_LINE_STRIP);
    glColor3f(a,b,c);
    glVertex3f(x, y, z - 2); // for left start
    glVertex3f(x, -y, z - 2);
    glVertex3f(x + 2, -y, z - 2);// for right start
    glVertex3f(x + 2, y, z - 2);
    glVertex3f(x, y, z - 2); 
  glEnd();
  //Left
  glBegin(GL_LINE_STRIP);
    glColor3f(a,b,c);
    glVertex3f(x, y, z - 2); 
    glVertex3f(x, y, z); 
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, z - 2);
  glEnd();
  //Right
  glBegin(GL_LINE_STRIP);
    glColor3f(a,b,c);
    glVertex3f(x + 2, -y, z - 2);
    glVertex3f(x + 2, -y, z);
    glVertex3f(x + 2, y, z);
    glVertex3f(x + 2, y, z - 2);
  glEnd();
  

  }

  glutSwapBuffers();
}

void reshape (int w, int h){
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // FP and BP
    gluPerspective(60, 1, 1, 30);
    glMatrixMode(GL_MODELVIEW);
}

void timerZ(int value){
  glutPostRedisplay();
  glutTimerFunc(1000/60, timerZ, 0);
  
  switch (state)
  {
  case 1:
    if(z_position < 5){
      
      z_position += 0.10;
    }
    else{
      state = -1;
    }
    break;

  case -1:
    if(z_position > -15){
      z_position -= 0.10;
    }
    else{
      state = 1;
    }
    break;
  
  
  }
}

void timerX(int value){
  glutPostRedisplay();
  glutTimerFunc(1000/60, timerX, 0);
  
  switch (state)
  {
  case 1:
    if(x_position < 8){
      
      x_position += 0.10;
    }
    else{
      state = -1;
    }
    break;

  case -1:
    if(x_position > -3){
      x_position -= 0.10;
    }
    else{
      state = 1;
    }
    break;
  
  
  }
}

//Main program
int main(int argc, char **argv)
{
  char i;
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(200,100);
  glutInitWindowSize(500,500);

  glutCreateWindow("Window 1");
  //Call to the drawing function
   
  glutDisplayFunc(draw);
  glutReshapeFunc(reshape);

  // forward backward
  glutTimerFunc(0, timerZ, 0);

  // left right
  //glutTimerFunc(0,timerX,0);

  init();
  
  //scanf("%c", &i);
  glutMainLoop();

  return 0;
}
