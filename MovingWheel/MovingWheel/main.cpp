#include<GLUT/glut.h>
#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<time.h>
#include<vector>
using namespace std;

GLfloat rectangleFirstBlack[5][3]={{10,0,0},{10,38,0},{5,38,0},{0,38,0},{0,0,0}};
GLfloat rectangleFirstW[5][3]={{0,0,0},{0,38,0},{-5,38,0},{-10,38,0},{-10,0,0}};
GLfloat rectangleFirstB[5][3]={{5,2,0},{5,36,0},{0,36,0},{-5,36,0},{-5,2,0}};


GLfloat rectangleSecondW[5][3]={{10,0,0},{10,38,0},{5,38,0},{0,38,0},{0,0,0}};
GLfloat rectangleSecondBlack[5][3]={{0,0,0},{0,38,0},{-5,38,0},{-10,38,0},{-10,0,0}};
GLfloat rectangleSecondB[5][3]={{5,2,0},{5,36,0},{0,36,0},{-5,36,0},{-5,2,0}};



void draw_RectangleSecond(void){
    
    
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    for(int i=0;i<5;i++){
        glVertex3fv(rectangleSecondBlack[i]);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for(int i=0;i<5;i++){
        glVertex3fv(rectangleSecondW[i]);
    }
    glEnd();
    
    
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for(int i=0;i<5;i++){
        glVertex3fv(rectangleSecondB[i]);
    }
    glEnd();
    
    
    
    
    
    
    glFlush();
}


void draw_RectangleFirst(void){
    
    
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    for(int i=0;i<5;i++){
        glVertex3fv(rectangleFirstBlack[i]);
    }
    glEnd();
    
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for(int i=0;i<5;i++){
        glVertex3fv(rectangleFirstW[i]);
    }
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for(int i=0;i<5;i++){
        glVertex3fv(rectangleFirstB[i]);
    }
    glEnd();
    
    
    
    
    glFlush();
}


void draw_ring(void){
    for(int r=0;r<360;r+=45){
        glPushMatrix();
        glRotated(r,0,0,1);
        glTranslated(0,40,0);
        draw_RectangleFirst();
        glPopMatrix();
        
    }
    
}

void draw_ring2(void){
    for(int r=0;r<360;r+=45){
        glPushMatrix();
        glRotated(r,0,0,1);
        glTranslated(0,40,0);
        draw_RectangleSecond();
        glPopMatrix();
        
    }
}


void display(void){
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    
    
    double dx=250.0;
    double dy=250.0;
    
    
    for(int i=0;i<2;i++){
        if(i==0){
            for(int j=0;j<4;j++){
                if(j%2==0){
                    glPushMatrix();
                    glTranslated(j*dx,i*dy,0);
                    glScaled(1.3,1.3,1.3);
                    draw_ring2();
                    glPopMatrix();
                }else{
                    glPushMatrix();
                    glTranslated(j*dx,i*dy,0);
                    glScaled(1.3,1.3,1.3);
                    draw_ring();
                    glPopMatrix();
                }
            }
        }else{
            for(int j=0;j<4;j++){
                if(j%2==1){
                    glPushMatrix();
                    glTranslated(j*dx,i*dy,0);
                    glScaled(1.3,1.3,1.3);
                    draw_ring2();
                    glPopMatrix();
                }else{
                    glPushMatrix();
                    glTranslated(j*dx,i*dy,0);
                    glScaled(1.3,1.3,1.3);
                    draw_ring();
                    glPopMatrix();
                }
            }
        }
    }
    
    
    glFlush();
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);//1000，500
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Project2");
    glClearColor(0.8, 0.8, 0.0, 0.0);
    glEnable(GL_BLEND);
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH,GL_NICEST);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(875,-125,-125,375,100,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    system("pause");
    return 0;
}
