# Transformacoes-Geometricas-Usando-OpenGL

Projeto de Computa��o Gr�fica, no qual consiste em, usando as bibliotecas OpenGL, transladar e rotacionar um quadrado vermelho na tela.

Ao iniciar o programa, estara no modo de transla��o. Ent�o usando as teclas direcionais do teclado � poss�vel transladar o quadrado. Por�m, ao clicar a tecla 'r', entrar� no modo de rota��o, onde usando as teclas direcionais para a esquerda e direita, � poss�vel rotacionar o quadrado.

O tamanho do quadrado � indicado por uma vari�vel inteira tamQuad.

 - Para compilar no Windows:
	gcc main.c -o main -lopengl32 -lglu32 -lfreeglut

 - Para compilar no Linux:
	 gcc main.c -o main -lGL -lglut -lGLU