#include <GL/glut.h>

float tx = 0, ty = 0, grau = 0;

int init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);     //define a cor de fundo

    glMatrixMode(GL_PROJECTION);          //carrega a matriz de projeção
    gluOrtho2D(0.0,100.0,0.0,100.0);      //define projeção ortogonal 2D

}

void object(){
	glBegin(GL_POLYGON);                    
        glVertex2i(0,0);
        glVertex2i(0,10);
        glVertex2i(10,10);
        glVertex2i(10,0);
    glEnd();
}


void display(void){

    glClear(GL_COLOR_BUFFER_BIT);         //desenha o fundo (limpa a janela)
    glColor3f(1.0,0.0,0.0);               //altera o atributo de cor
    glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

    glTranslatef((tx+5),(ty+5),0);
	glRotatef(grau,0,0,1);
    glTranslatef(-(tx+5),-(ty+5),0);

	
    glTranslatef(tx,ty,0);
    
    object();

    glFlush();                            //desenha os comandos não executados
}

void specialTranslation(int key, int x, int y){
	switch (key){
		case GLUT_KEY_UP:
			ty = ty + 1;
			glutPostRedisplay();
		break;
		case GLUT_KEY_DOWN:
			ty = ty - 1;
			glutPostRedisplay();
		break;
		case GLUT_KEY_LEFT:
			tx = tx - 1;
			glutPostRedisplay();
		break;
		case GLUT_KEY_RIGHT:
			tx = tx + 1;
			glutPostRedisplay();
		break;
	}
}

void specialRotation(int key, int x, int y){
	switch (key){
		case GLUT_KEY_LEFT:
			grau = grau - 1;
			glutPostRedisplay();
		break;
		case GLUT_KEY_RIGHT:
			grau = grau + 1;
			glutPostRedisplay();
		break;
	}
}


void keyboardSimple(unsigned char key, int x, int y){
	switch (key){
		case 'q':
			exit(0);
		break;
		case 't':
			glutSpecialFunc(specialTranslation); 	//Ativa Traslação
		break;
		case 'r':
			glutSpecialFunc(specialRotation);		//Ativa Rotação
		break;
	}
}


int main(int argc, char** argv) {


    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowSize(500,500);                              //configura a largura e altura da janela de exibição
    glutInitWindowPosition(200,0);
    glutCreateWindow("Um programa OpenGL Exemplo");           //cria a janela de exibição

    init();                          //executa função de inicialização
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutKeyboardFunc(keyboardSimple);
   

    glutMainLoop();                  //mostre tudo e espere
    return 0;
}

