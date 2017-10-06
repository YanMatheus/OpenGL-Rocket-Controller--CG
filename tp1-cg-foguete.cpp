//
// @Author: Yan Matheus Goncalves Fontao
// @Github: https://github.com/YanMatheus
//
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int velocidade = 20;

void bico(){
        glBegin(GL_TRIANGLES);

        glColor3f(1, 1, 1);
        glVertex3f(3.0, 6.0, 0);
        glVertex3f(4.0, 8.0, 0);
        glVertex3f(5.0, 6.0, 0);

        glEnd();
}

void corpo(){
        glBegin(GL_QUADS);

        glColor3f(0, 0,0);
        glVertex3f(3.0, 1.0, 0);
        glVertex3f(5.0, 1.0, 0);
        glVertex3f(5.0, 6.0, 0);
        glVertex3f(3.0, 6.0, 0);

        glEnd();
}

void asaEsquerda(){
        glBegin(GL_TRIANGLES);

        glColor3f(1, 1, 1);
        glVertex3f(1.5, 1.0, 0);
        glVertex3f(3.0, 1.0, 0);
        glVertex3f(3.0, 3.0, 0);
        glEnd();
}

void asaDireita(){
        glBegin(GL_TRIANGLES);

        glVertex3f(5.0, 1.0, 0);
        glVertex3f(6.5, 1.0, 0);
        glVertex3f(5.0, 3.0, 0);

        glEnd();
}

void Foguete(void){

        glClearColor(0.1,0.6,1,5);
        glColor3f(1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        bico();
        corpo();
        asaEsquerda();
        asaDireita();
        //glTranslatef(0,0.5f,0.0);

        glFlush();


}
void Teclado(unsigned char tecla, int x, int y){

        if (tecla == 119) { //cima
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glTranslatef(0,0.5f,0.0);

                glFlush();
        } else if(tecla == 97) {//esquerda
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glRotatef(5.0, 0.0, 0.0, 1.0);


                glFlush();
        }else if(tecla == 100) {//direita
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glRotatef(-5.0, 0.0, 0.0, 1.0);


                glFlush();
        }else if(tecla == 115) {//baixo
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glTranslatef(0,-0.5f,0.0);


                glFlush();
        }
        else if(tecla == 101) {//era pra ser diagonal direita
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glTranslatef(0,0.5f,0.0);
                glRotatef(-5.0, 0.0, 0.0, 1.0);

                glFlush();
        }
        else if(tecla == 113) {  //diagonal esquerda com volta
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glTranslatef(0,0.5f,0.0);
                glRotatef(5.0, 0.0, 0.0, 1.0);

                glFlush();
        }
        else if(tecla == 32) {     // gira ponta
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glTranslatef(0,0.5f,0.0);
                glRotatef(-8.0, 0.0, 0.0, 1.0);
        }
        else if(tecla == 87) {     // turbo shift + w
                glClearColor(0.1,0.6,1,5);
                glColor3f(1.0, 1.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);

                bico();
                corpo();
                asaEsquerda();
                asaDireita();
                glTranslatef(0,3.0f,0.0);
        }
}
void tempo(int x){
        glutPostRedisplay();
        glutTimerFunc(velocidade, tempo, 0);
}

int main(int argc, char *argv[]){


        glutInit(&argc, argv);


        glutInitWindowSize(900,900);

        glutInitWindowPosition(500,300);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutCreateWindow("Foguete: W = VOA, A=ESQUERDA, S = DESCE, D = DIREITA, Q = DIAGONAL E, E = DIAGONAL D,SHIFT+W = TURBO");
        glutDisplayFunc(Foguete);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-10.0, 70.0, -40.0, 20.0);
        glutKeyboardFunc (Teclado);

        glutTimerFunc(0, tempo, 1);
        glutMainLoop();

        return 0;
}
