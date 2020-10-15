#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>


#include <unistd.h>
#include <fcntl.h>
int state = 1;
float x = -10.0 , y = 1.0, z = 0;
float z_position = -5;
float x_position = 4;


//Drawing funciton
void init(){
    glClearColor(0,0,0,1);
}

void draw(void)
{
  //Background color
//   glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT );
  glLoadIdentity();

  glTranslatef(x_position, 0, z_position);
  //Draw order

  
  //Cube 1
  //Front
  glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0);
    glVertex3f(x, y, z); 
    glVertex3f(x, -y, z);
    glVertex3f(x + 2, -y, z); 
    glVertex3f(x + 2, y, z);
    glVertex3f(x, y, z); 
  glEnd();
  //Back
  glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0);
    glVertex3f(x, y, z - 2); // for left start
    glVertex3f(x, -y, z - 2);
    glVertex3f(x + 2, -y, z - 2);// for right start
    glVertex3f(x + 2, y, z - 2);
    glVertex3f(x, y, z - 2); 
  glEnd();
  //Left
  glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0);
    glVertex3f(x, y, z - 2); 
    glVertex3f(x, y, z); 
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, z - 2);
  glEnd();
  //Right
  glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0);
    glVertex3f(x + 2, -y, z - 2);
    glVertex3f(x + 2, -y, z);
    glVertex3f(x + 2, y, z);
    glVertex3f(x + 2, y, z - 2);
  glEnd();


  // Cube 2
  //front
  glBegin(GL_LINE_STRIP);
    glColor3f(0,1,0);
    glVertex3f(x + 5, y, z); 
    glVertex3f(x + 5, -y, z);
    glVertex3f(x + 7, -y, z);
    glVertex3f(x + 7, y, z); 
    glVertex3f(x + 5, y, z); 
  glEnd();
  //Back
  glBegin(GL_LINE_STRIP);
    glColor3f(0,1,0);
    glVertex3f(x + 5, y, z - 2); // for left start
    glVertex3f(x + 5, -y, z - 2);
    glVertex3f(x + 7, -y, z - 2);// for right start
    glVertex3f(x + 7, y, z - 2);
    glVertex3f(x + 5, y, z - 2); 
  glEnd();
  //Left
  glBegin(GL_LINE_STRIP);
    glColor3f(0,1,0);
    glVertex3f(x + 5, y, z - 2); 
    glVertex3f(x + 5, y, z); 
    glVertex3f(x + 5, -y, z);
    glVertex3f(x + 5, -y, z - 2);
  glEnd();
  //Right
  glBegin(GL_LINE_STRIP);
    glColor3f(0,1,0);
    glVertex3f(x + 7, -y, z - 2);
    glVertex3f(x + 7, -y, z);
    glVertex3f(x + 7, y, z);
    glVertex3f(x + 7, y, z - 2);
  glEnd();



  glBegin(GL_POLYGON);

    glColor3f(0,0,1);
    glVertex3f(x + 10, 1.0, 0); 
    glVertex3f(x + 10, -1.0, 0);
    glVertex3f(x + 12.0, -1.0, 0);
    glVertex3f(x + 12.0, 1.0, 0);

  glEnd();
    glutSwapBuffers();
}

void reshape (int w, int h){
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 2, 50);
    glMatrixMode(GL_MODELVIEW);
}

void timerZ(){
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

void timerX(){
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
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE) ;
  glutInitWindowPosition(200,100);
  glutInitWindowSize(500,500);

  glutCreateWindow("Window 1");
  //Call to the drawing function
   
  glutDisplayFunc(draw);
  glutReshapeFunc(reshape);

  // forward backward
  glutTimerFunc(0,timerZ,0);

  // left right
  //glutTimerFunc(0,timerX,0);

  init();
  
  //scanf("%c", &i);
  glutMainLoop();

  return 0;
}
