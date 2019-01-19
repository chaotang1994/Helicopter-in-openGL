

#include <iostream>
#include <GLUT/GLUT.h>
using namespace std;

GLfloat pos[]={-2,4,5,1},
amb[]={0.3,0.3,0.3,1};
GLfloat front_amb_diff[]={0.3,0.3,0.3,1};
GLfloat back_amb_diff[]={1,1,1,1};

GLfloat theta=0, dt=0.5;
GLfloat i=0;
 
int axis=0;
int spin = -1;
float propeller = 1.5;
void display(void){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    
    
    //creat the axis
    glPushMatrix();
    glColor3f(1,1,1);
    glRotated(theta,0,0,1);
    glutSolidSphere(0.02,20,10);
    glColor3f(1,1,1);
    glRotated(theta,0,0,1);
    glutSolidCone(.04,.05,20,20);
    glPopMatrix();
    
    
    
    //create the propeller
    glPushMatrix();
    glRotated(theta,0,0,spin);
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    
    glVertex3f(0,0.0,.1);
    glVertex3f(.1,-propeller,.1);
    glVertex3f(-.1,-propeller,.1);
    
    glVertex3f(0,0.0,.1);
    glVertex3f(.1,propeller,.1);
    glVertex3f(-.1,propeller,.1);
    
    glVertex3f(0,0.0,.1);
    glVertex3f(-propeller,.1,.1);
    glVertex3f(-propeller,-.1,.1);
    
    glVertex3f(0,0.0,.1);
    glVertex3f(propeller,.1,.1);
    glVertex3f(propeller,-.1,.1);
    
    glEnd();
    
    glPopMatrix();
    
    
    glutSwapBuffers();
}
void idle(void){
    
    
    theta+=i;
    glutPostRedisplay();
    
    
}

void key(unsigned char key, int x, int y) {
    
    if (key == 'a' || key == 'A') {
        spin = 1;
    }
    
    if (key == 'd' || key == 'D') {
        spin = -1;
    }
    
    if (key == 'w' || key == 'W') {
        i+=1;
    }
    if (key == 's' || key == 'S') {
        i-=1;
    }
    
    if (key == 'q' || key == 'Q') {
        propeller -=0.1;
    }
    
    if (key == 'e' || key == 'E') {
        propeller +=0.1;
    }
    
    if (key == 'r' || key == 'R') {
        propeller= .5;
        i=0;
    }
    
    glutPostRedisplay();
}
int main(int argc,char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Wing");
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1.0,2,8);
    
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,front_amb_diff);
    glMaterialfv(GL_BACK,GL_AMBIENT_AND_DIFFUSE,back_amb_diff);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,75);
    glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0,0,-5);
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
     
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    
    glutKeyboardFunc(key);
    
    
    cout << "Press the 'W' to increase the speed" << endl;
    cout << "Press the 'S' to slow the speed" << endl;
    cout << "Press the 'E' to increase the size " << endl;
    cout << "Press the 'q' to decrease the size "  << endl;
    cout << "Press the 'D' choice Clockwise direction "   << endl;
    cout << "Press the 'D' Counter-clockwise Clockwise direction "   << endl;
    cout << "Presee 'R' for reset" << endl;
    
    
    
    glutMainLoop();
}

