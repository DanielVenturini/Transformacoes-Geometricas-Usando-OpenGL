#include <GL/glut.h>
#include <stdio.h>

int tx = 0;
int ty = 0;

int tamQuad = 10;       // quadrado 10x10

int theta = 0;

int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);     // define a cor de fundo

    glMatrixMode(GL_PROJECTION);          // carrega a matriz de projeção
    gluOrtho2D(0.0,100.0,0.0,100.0);      // define projeção ortogonal 2D
}

void transladar(int key, int x, int y){
    switch(key){
    	case GLUT_KEY_RIGHT:
            tx += 1;
            glutPostRedisplay();
    		break;
        case GLUT_KEY_LEFT:
    		tx -= 1;
    		glutPostRedisplay();
    		break;
        case GLUT_KEY_UP:
    		ty += 1;
    		glutPostRedisplay();
    		break;
        case GLUT_KEY_DOWN:
    		ty -= 1;
    		glutPostRedisplay();
    		break;
	}
}

void rotacionar(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            theta -= 10;
            break;
        case GLUT_KEY_LEFT:
            theta += 10;
            break;
    }

    glutPostRedisplay();
}

void opcao(int key, int x, int y){
    switch(key){
        case 't':
            glutSpecialFunc(transladar);        // captura as teclas especiais
            break;
        case 'r':
            glutSpecialFunc(rotacionar);        // captura as teclas especiais
            break;
    }
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);           // desenha o fundo (limpa a janela)

    glColor3f(1.0,0.0,0.0);                 // altera o atributo de cor
    glMatrixMode(GL_MODELVIEW);             // carrega a matriz de modelo
    glLoadIdentity();                       // carrega a matriz identidade

    glTranslatef(tx+(tamQuad/2), ty+(tamQuad/2), 0);
    glRotatef(theta, 0, 0, 1);
    glTranslatef(-tx-(tamQuad/2), -ty-(tamQuad/2), 0);

    glBegin(GL_POLYGON);                    // desenha uma linha
        glVertex2i(tx, ty);
        glVertex2i(tx, ty + tamQuad);
        glVertex2i(tx + tamQuad, ty + tamQuad);
        glVertex2i(tx + tamQuad, ty);
    glEnd();


    glFlush();                            // desenha os comandos não executados
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowSize(500,500);                              //configura a largura e altura da janela de exibição
    glutInitWindowPosition(200,200);
    glutCreateWindow("Um programa OpenGL Exemplo");           //cria a janela de exibição

    init();                             // executa função de inicialização

    glutSpecialFunc(transladar);        // captura as teclas especiais
    glutKeyboardFunc(opcao);            // captura as teclas 'R' e 'T'

    glutDisplayFunc(display);           // estabelece a função "display" como a função callback de exibição.
    glutMainLoop();                     // mostre tudo e espere
    return 0;
}

