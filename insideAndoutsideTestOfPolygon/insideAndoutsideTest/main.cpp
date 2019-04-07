#include<glut/glut.h>
#include<iostream>
#include<math.h>
using namespace std;


GLint vert[100][2];

GLint vert2[100][2];

GLint edge[100][2];

int width=400,height=600,n=0,type = GL_LINE_STRIP, v, type2=GL_POINTS;
#define pi 3.14159265359
int j=0,k=0;
int CountDifferentSign=0;
bool rubberbanding=false, antialiasing=false;

bool connected=false;
int magnitudeAB ,dotAB=0;
int direction=0;
int now=0;


void display(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    
    if(n==1&&(type==GL_LINE_STRIP||type==GL_LINE_LOOP)){
        
        glBegin(GL_POINTS);
        glColor3f(1,1,0);
        glVertex2iv(vert[0]);
        
        glEnd();
        
    }
    
    
    
    glBegin(type);
    glColor3f(1,1,0);
    for(int i=0; i<n;i++)glVertex2iv(vert[i]);
    
    glEnd();
    
    
    for(int x=0; x<j;x++){//check point
        
        
        for(int i=0; i<n; i++){//side point
            
            
            
            edge[i][0]=vert2[x][0]-vert[i][0];//point a.x
            edge[i][1]=vert2[x][1]-vert[i][1];//point a.y
            
        }
        
        for(int i=0; i<n; i++){
            
            
            if(i==n-1){//i=n-1
                
                
                //ae-bd
                direction=((vert[0][0]-vert[i][0])*edge[i][1])-((vert[0][1]-vert[i][1])*(edge[i][0]));
                
            }else{
                
                
                direction=((vert[i+1][0]-vert[i][0])*edge[i][1])-((vert[i+1][1]-vert[i][1])*(edge[i][0]));
                
            }
            
            
            
            if(i==0&&direction<0){
                now=-1;
            }else if(i==0&&direction>0){
                now=1;
            }
            if(i>0&&direction*now<0){
                CountDifferentSign++;
            }else{
                CountDifferentSign+=0;
            }
            
            
            
            
        }
        
        if(CountDifferentSign==0){
            glColor3f(0,1,0);
            glBegin(type2);
            glVertex2iv(vert2[x]);
            glEnd();
        }else{
            glColor3f(1,0,0);
            glBegin(type2);
            glVertex2iv(vert2[x]);
            glEnd();
        }
        
        
        
        CountDifferentSign=0;
        
        
        
        
        
        
    }
    
    glutSwapBuffers();
    
}















void keyboard(unsigned char key, int x, int y){
    
    switch(key){
            
        case 'a':antialiasing !=antialiasing;
            
            if(antialiasing){
                
                glEnable(GL_LINE_SMOOTH);
                
                glEnable(GL_LINE_SMOOTH);
                
            }else{
                
                glDisable(GL_BLEND);
                
                glDisable(GL_LINE_SMOOTH);
                
            }
            
            break;
            
        case'r': n=0;j=0;connected=false;break;
            
        case'l': type=GL_LINE_STRIP;break;
            
        case'c': type=GL_LINE_LOOP;connected=true;break;
            
        case'v': type=GL_POINTS;break;
            
    }
    
    glutPostRedisplay();
    
}



int findVertex(int x, int y){
    
    int dx, dy;
    
    for(int i=0; i<n; i++){
        
        dx=vert[i][0]-x;
        
        dy=vert[i][1]-y;
        
        if(dx*dy+dy*dx<16)return i;
        
    }
    
    return -1;
    
}



void mouse(int button, int state, int x, int y){
    
    switch(button){
            
            
            
            
            
        case GLUT_LEFT_BUTTON:
            
            if(state==GLUT_DOWN&&connected==false){
                
                v=n++;
                
                vert[v][0]=x;
                
                vert[v][1]=height-1-y;
                
                rubberbanding=true;
                
            }else if(state==GLUT_DOWN&&connected==true){
                
                k=j++;
                
                vert2[k][0]=x;
                
                vert2[k][1]=height-1-y;
                
            }
            
            else rubberbanding=false;
            
            glutPostRedisplay();
            
            break;
            
            
            
            
            
        case GLUT_RIGHT_BUTTON:
            
            if(state==GLUT_DOWN && (v-findVertex(x,height-1-y))!=-1){
                
                if(glutGetModifiers()==GLUT_ACTIVE_CTRL){
                    
                    for(int i=v; i<n-1; i++){
                        
                        vert[i][0]=vert[i+1][0];
                        
                        vert[i][1]=vert[i+1][1];
                        
                    }
                    
                    n--;
                    
                }else{
                    
                    vert[v][0]=x;
                    
                    vert[v][1]=height-1-y;
                    
                    rubberbanding=true;
                    
                }
                
                glutPostRedisplay();
                
            }
            
            else rubberbanding=false;
            
            break;
            
    }
    
    
    
    
    
}





void motion(int x, int y){
    
    if(rubberbanding){
        
        vert[v][0]=x;
        
        vert[v][1]=height-1-y;
        
        glutPostRedisplay();
        
    }
    
}











int main(int argc, char** argv) {
    
    
    
    
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    
    glutInitWindowSize(width, height);//1000£¨500
    
    glutInitWindowPosition(850, 100);
    
    glutCreateWindow("Project3");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    gluOrtho2D(0,width,0,height);
    
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
    glutDisplayFunc(display);
    
    glutKeyboardFunc(keyboard);
    
    glutMouseFunc(mouse);
    
    glutMotionFunc(motion);
    
    glutMainLoop();
    
    system("pause");
    
    return 0;
    
}


