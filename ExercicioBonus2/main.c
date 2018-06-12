#include <GL/glut.h>
#include <GL/freeglut.h>

void animaTeaPot(){
    static int cont=0;
    if(cont == 360){
        cont = 0;
    }
    glRotatef(45, 1, 0, 0);
    glRotatef(cont, 0, 0, 1);
    glutWireTeapot(1.0f);
    cont++;
    glutPostRedisplay() ;
}

int init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glEnable(GL_DEPTH_TEST); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //VIEW PORT SUPERIOR ESQUERDO
    glViewport(0, 400, 400, 400);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 1.0, 0.0, //posicao câmera
              0.0, 0.0, 0.0, //onde camera aponta
              0.0, 0.0, 1.0); //vet

    glColor3f(1.0f, 0.0f, 0.0f); //altera o atributo de cor
    glutWireTeapot(1.0f); // desenha o pote


    //VIEW PORT SUPERIOR DIREITO
    glViewport(400, 400, 400, 400);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

    gluLookAt(1.0, 0.0, 0.0, 
              0.0, 0.0, 0.0, 
              0.0, 1.0, 0.0); 
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1.0f); 


    //VIEW PORT INFERIOR ESQUERDO
    glViewport(0, 0, 400, 400);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 1.0, 
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0); 
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1.0f);


    //VIEW PORT INFERIOR DIREITO
    glViewport(400, 0, 400, 400); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(70.0, 1.0, 1.0, 50.0); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 4.0, 
              0.0, 0.0, 0.0, 
              0.0, 1.0, 0.0); 
    glColor3f(1.0f, 0.0f, 0.0f);
    animaTeaPot(); //desenha o pote com animação


    glFlush(); 
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Exercicio Bonus II - Rafael Menezes");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    animaTeaPot();
    glutMainLoop();                                  //mostre tudo e espere
    return 0;

}
