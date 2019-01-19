#include<stdlib.h>
#include<glut/glut.h>
#include<iostream>
using namespace std;

GLfloat pos[]={-2,4,5,1},amb[]={0.3,0.3,0.3,1.0};
GLfloat front_amb_diff[]={0.7,0.5,0.1,1.0};
GLfloat back_amb_diff[]={0.4,0.7,0.1,1.0};
GLfloat spe[]={00.25,0.25,0.25,1.0};
GLfloat theta =0, dt=0.5,axes[3][3]={{1,0,0},{0,1,0},{0,0,1}};
int width=800, height=600;
int x_axis=0, y_axis=0, z_axis=0, t=0, w=0 ,j=0, ColorOfWing=0;;
bool xa=false, ya=false, za=false;//off
int i=0, k=0;
int axis=0;

void Wing(){
    glBegin(GL_TRIANGLES);
    
    
    if(ColorOfWing%2==0){
        glColor3ub(255,140,0);
        glVertex3f(0,0.1,0);
        
        glColor3ub(255,180,0);
        glVertex3f(0.05,0.2,0.4);
        glVertex3f(-0.05,0.2,0.4);
        
        glColor3ub(255,140,0);
        glVertex3f(0,0.1,0);
        
        glColor3ub(255,180,0);
        glVertex3f(0.05,0.2,-0.4);
        glVertex3f(-0.05,0.2,-0.4);
        
        glColor3ub(255,140,0);
        glVertex3f(0,0.1,0);
        
        glColor3ub(255,180,0);
        glVertex3f(0.4,0.2,0.05);
        glVertex3f(0.4,0.2,-0.05);
        
        glColor3ub(255,140,0);
        glVertex3f(0,0.1,0);
        
        glColor3ub(255,180,0);
        glVertex3f(-0.4,0.2,0.05);
        glVertex3f(-0.4,0.2,-0.05);
        
    }else{
        
        glColor3ub(238,238,0);
        glVertex3f(0,0.1,0);
        glColor3ub(0,255,255);
        glVertex3f(0.05,0.2,0.4);
        glColor3ub(127,255,0);
        glVertex3f(-0.05,0.2,0.4);
        
        glColor3ub(238,238,0);
        glVertex3f(0,0.1,0);
        glColor3ub(0,255,255);
        glVertex3f(0.05,0.2,-0.4);
        glColor3ub(127,255,0);
        glVertex3f(-0.05,0.2,-0.4);
        
        glColor3ub(238,238,0);
        glVertex3f(0,0.1,0);
        glColor3ub(0,255,255);
        glVertex3f(0.4,0.2,0.05);
        glColor3ub(127,255,0);
        glVertex3f(0.4,0.2,-0.05);
        
        glColor3ub(238,238,0);
        glVertex3f(0,0.1,0);
        glColor3ub(0,255,255);
        glVertex3f(-0.4,0.2,0.05);
        glColor3ub(127,255,0);
        glVertex3f(-0.4,0.2,-0.05);
    }
    
    glEnd();
}




void display(void){
    
    
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    
    
    
    glPushMatrix();
    glScalef(1.6,1.6,1.6);
    
    
    
    if(axis<3&&xa==false&&ya==false&&za==false){
        glRotated(theta, axes[axis][0],axes[axis][1],axes[axis][2]);
    }else if(xa==true){
        glRotated(theta, axes[0][0],axes[0][1],axes[0][2]);
    }else if(ya==true){
        glRotated(theta, axes[1][0],axes[1][1],axes[1][2]);
    }else if(za==true){
        glRotated(theta, axes[2][0],axes[2][1],axes[2][2]);
    }
    else{
        
        glPushMatrix();
        glRotated(theta,1,1,1);
        glLightfv(GL_LIGHT0,GL_POSITION,pos);
        
        
        glPopMatrix();
    }
    
    
    glPushMatrix();//Fuselage
    glColor3ub(255,69,0);
    glScalef(0.3, 0.3, 0.5);
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();
    
    
    
    
    
    //Tail Cone
    glPushMatrix();
    glColor3ub(255,140,0);
    glRotated(-170, 1, 0, 0);
    glutSolidCone(0.08, 0.4, 50, 50);
    glPopMatrix();
    
    
    //Wing//Main rotor system
    glPushMatrix();
    glTranslatef(0,0.08,0);
    glRotated(w,0,1,0);
    Wing();
    glPopMatrix();
    
    
    
    if(t%2==0){
        //Tail Wing//Tail rotor system
        glPushMatrix();
        glTranslatef(0,0.06,-0.4);
        glRotatef(90,0,1,0);
        glScaled(0.25, 0.25, 0.3);
        glRotatef(w,0,1,0);
        Wing();
        glPopMatrix();
        
    }else{
        //tail round wing
        glPushMatrix();
        glTranslatef(0,0.08,-0.4);
        glRotatef(90,0,1,0);
        glutSolidTorus(0.008, 0.02, 50, 50);
        glPopMatrix();
    }
    
    if(i%2==0){
        //Cone shape Transmission
        glPushMatrix();
        glColor3ub(255,140,0);
        glTranslatef(0, 0.18, 0);
        glRotated(90, 1, 0, 0);
        glScalef(0.1,0.1,0.1);
        glutSolidCone(0.5, 0.4, 50, 50);
        glPopMatrix();
    }else{
        //Sphere shape transmission
        glPushMatrix();
        glColor3ub(255,140,0);
        glTranslatef(0, 0.18, 0);
        glScalef(0.1,0.1,0.1);
        glutSolidSphere(0.3, 50, 50);
        glPopMatrix();
    }
    
    if(k%2==0){
        
        //Left LandingGear
        glPushMatrix();
        glColor3ub(255,69,0);
        glTranslatef(0.05, -0.2, 0);
        glScalef(0.2, 0.1, 1.8);
        glutSolidSphere(0.1, 20, 20);
        glPopMatrix();
        
        //Right LandingGear
        glPushMatrix();
        glColor3ub(255,69,0);
        glTranslatef(-0.05, -0.2, 0);
        glScalef(0.2, 0.1, 1.8);
        glutSolidSphere(0.1, 20, 20);
        glPopMatrix();
        
        
        //LandingGear Connecter
        glColor3ub(255,140,0);
        glPushMatrix();
        glTranslatef(0.05, -0.16, 0);
        glScalef(0.1, 0.5, 0.1);
        glutSolidSphere(0.1, 20, 20);
        glPopMatrix();
        
        
        glPushMatrix();
        glTranslatef(-0.05, -0.16, 0);
        glScalef(0.1, 0.5, 0.1);
        glutSolidSphere(0.1, 20, 20);
        glPopMatrix();
        
    }
    
    
    //strip
    glPushMatrix();
    glColor3ub(255,140,0);
    glRotated(0, 1, 0, 0);
    glTranslatef(0, 0, 0.1);
    glScalef(0.28, 0.28, 0.1);
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();
    
    
    glPushMatrix();
    glColor3ub(255,140,0);
    glRotated(90, 1, 0, 0);
    glTranslatef(0, -0.01, 0.04);
    glScalef(0.3, 0.45, 0.062);
    glutSolidSphere(0.5, 50, 50);
    glPopMatrix();
    
    
    
    
    glPopMatrix();
    
    
    glutSwapBuffers();
    
    
}

void idle(void){
    
    if(theta>=360)axis=(axis+1)%4;
    theta=(theta<360)?theta+dt:dt;
    w=w+j;
    
    glutPostRedisplay();
    
    
}



void keys(unsigned char key, int x, int y){
    switch(key){
        case 'r': theta=0;break;//reset
        case 'x': xa=true;ya=false;za=false;cout<<"x-axis rotated on"<<endl;break;//x-axis
        case 'y': ya=true;xa=false;za=false;cout<<"y-axis rotated on"<<endl;break;//y-axis
        case 'z': za=true;xa=false;ya=false;cout<<"z-axis rotated on"<<endl;break;//z-axis
        case 't': t++;cout<<"you press t, Tail Wing has been change."<<endl;break;//change tip of wing
        case 'f': i++;cout<<"you press f, Transmission has been change."<<endl;break;
        case 'w': j++;cout<<"increase speed of Wing"<<endl;break;//increase speed of wing
        case 'd': j--;cout<<"decrease speed of Wing"<<endl;break;//decrease speed of wing
        case 'c': ColorOfWing++;cout<<"change color of the Wing"<<endl;break;
        case 'k':
            k++;
            if(k%2==1){
                cout<<"Landing Gear close up! "<<endl;
            }else{
                cout<<"Landing Gear open!"<<endl;
            }break;
        case 'e': cout<<" Exit!!!  ThankYou."<<endl;exit(0);break;
        default:cout<<"  "<<endl;
            break;
    }
    glutPostRedisplay();
}







int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(800,100);
    glutCreateWindow("Helicopter");
    glClearColor(0,0.74,0.99 ,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25,((width/height)+0.25),1,12);//glOrtho(-2,2,-2,2,2,8);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, back_amb_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,spe);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,90);
    glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0,0,-5);
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable( GL_COLOR_MATERIAL);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keys);
    cout << "Helicopter -Chaoxin Tang"<<endl;
    cout << " Press key 'r' to reset helicopter position." << endl;
    cout << " Press key 'z' to roated at z-axis." << endl;
    cout << " Press key 'x' to roated at x-axis." << endl;
    cout << " Press key 'y' to roated at y-axis." << endl;
    cout << " Press key 'w' to speed wings at counterclockwise direction." << endl;
    cout << " Press key 'd' to speed wings at clockwise direction." << endl;
    cout << " Press key 't' to change style or type of the tail wing." << endl;
    cout << " Press key 'c' to change color of the wing"<<endl;
    cout << " Press key 'f' to change style or type of the transmission."<<endl;
    cout << " Press key 'k' to either close up landing gear, or open it."<<endl;
    cout << " Press key 'e' to exit." << endl;
    glutMainLoop();
    return 0;
    
}




