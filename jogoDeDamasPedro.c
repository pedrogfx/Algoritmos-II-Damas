//Pedro Goulart Rodrigues
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAB 8
#define CASA_BRANCA -1
#define CASA_VAZIA 0
#define A 1 // PEÇA BRANCA
#define B 2 //PEÇA PRETA
//-1 linha +1 coluna
/*depois de definir a casa destino
esquerda E<0 and direita E>7
jog1 e jog2 <0 e >7
*/

int opcaoJogada();//método p/ realizar as jogadas
int movimentarPeca();//método p/ moimentar as peças
int vezJogador();//método p/ controlar vez de quem está jogando

int matriz[TAB][TAB];/* = {{-1, -1, -1, -1, -1, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1}};*/

char pecas[3] = { ' ', 'A', 'B' }; //variavel p/ colocar CHAR no tabuleiro
int menu = 0, i = 0, j = 0;
int fimJogo = 0, movimentoInvalido, linhaDestino = 0, colunaDestino = 0, linhaOrigem = 0, colunaOrigem = 0, movimento = 0, jogador = 0; //variaveis das peças

int inicioGame() {
	system("cls");
	printf("   0 1 2 3 4 5 6 7\n");
	
	for (i = 0; i < TAB; i++)
	{
		printf("%d  ", i);
		for (j = 0; j < TAB; j++)
		{
			if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1)))
			{
				if (i < 3) matriz[i][j] = A; //brancas
				else if (i > 4) matriz[i][j] = B; //pretas
				else matriz[i][j] = CASA_VAZIA;//vazio
			} 
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					printf("%c ", pecas[matriz[i][j]]);
				}else{
					printf("%c ", pecas[matriz[i][j]]);					
				}				
			}else{
				if (j % 2 == 0) {
					printf("%c ", pecas[matriz[i][j]]);
				}else{
					printf("%c ", pecas[matriz[i][j]]);
				}
			}
		}
		printf("\n");
	}
	opcaoJogada();
}

int main() {
	setlocale(LC_ALL, "portuguese");
	do
	{
		printf("\n\t Bem vindo ao jogo de Damas!");
		printf("\n\t 1 - Iniciar jogo.");
		printf("\n\t 2 - Informações do jogo.");
		printf("\n\t 3 - Sair do jogo.");
		printf("\n\n\t Selecione uma opção => ");
		scanf_s("%d", &menu);

		switch (menu)
		{
		case 1: //COMEÇAR O JOGO (FUNÇÃO JOGO)
			inicioGame();

			break;

		case 2: // INFORMAÇÕES DO JOGO
			break;

		case 3: //SAIR DO JOGO
			system("cls");
			printf("\n\tVOCÊ SAIU DO JOGO!");
			break;

		default:
			system("cls");
			printf("\n\tOPÇÃO INVÁLIDA, TENTE NOVAMENTE!");	
		}
	} while (menu != 3);
	return 0;
}

int opcaoJogada() {
	printf("\n\tDIGITE A PEÇA QUE DESEJA MOVIMENTAR!");//escolher peça
	printf("\n\n\t\t\tLINHA => ");
	scanf_s("\n%d", &linhaOrigem);
	printf("\n\n\t\t\tCOLUNA => ");
	scanf_s("\n%d", &colunaOrigem);
	printf("\n\tQUAL MOVIMENTO DESEJA FAZER?");//ocupar peça
	printf("\n\t 1 = ESQUERDA \n\t 2 = DIREITA");
	printf("\n\n\t\t\tJOGADA => ");
	scanf_s("\n\t%d", &movimento);
	
	movimentarPeca();
}

int movimentarPeca(){
	inicioGame();
	
	if(jogador == 1){//jogada p/ peça preta
		if(movimento == 1 && matriz[linhaOrigem][colunaOrigem] == B )
		{	
			if(matriz[linhaOrigem-1][colunaOrigem-1] == 0){ //se o movimento for p/ as peças pretas, -1 casa p/ subir
				matriz[linhaOrigem][colunaOrigem] = 0; //resetar ela p/ olocar p/ peças pretas
				matriz[linhaOrigem-1][colunaOrigem-1] = B; //colocar a peça preta
				movimentoInvalido = 0; //movimento errado zerado
				jogador = 0; //trocar a vez do jogador				
			}else{
				if(matriz[linhaOrigem-1][colunaOrigem-1] == A && matriz[linhaOrigem-2][colunaOrigem == 0])//se houver uma peça branca no caminho faz o movimento -2
				{
					matriz[linhaOrigem][colunaOrigem] = 0; //reset
					matriz[linhaOrigem-1][colunaOrigem-1] = 0; //-1 p deixar em branco a peça que passou por cima
					matriz[linhaOrigem-2][colunaOrigem-2] = B; //colocar a peça preta
					movimentoInvalido = 0; //movimento errado zerado
					jogador = 0; //trocar a vez do jogador
				}else{
					movimentoInvalido = 1; //caso movimento não seja validado pelo restante "=1" p mostrar erro
				}								
			}
			
				
		}else{//jogada p/ direita
			if(movimento == 2 && matriz[linhaOrigem][colunaOrigem] == B)
			{
				if(matriz[linhaOrigem-1][colunaOrigem+1] == 0){ //caso não tenha peça inimiga na diagonal
					matriz[linhaOrigem-1][colunaOrigem+1] = 0; //same above
					matriz[linhaOrigem-1][colunaOrigem+1] = B; //same above
					movimentoInvalido = 0; //movimento errado zerado
					jogador = 0; //trocar a vez do jogador
				}
				
			}else{//caso tenha peça inimiga
				if(matriz[linhaOrigem-1][colunaOrigem+1] == A && matriz[linhaOrigem-2][colunaOrigem+2] == 0);
				
			} 
		}
	}if(jogador ==0){//jogada peça branca
				if(movimento == 1 && matriz[linhaOrigem][colunaOrigem] == A)//moimento p/ direita
		{
			if(matriz[linhaOrigem+1][colunaOrigem-1] == 0)
			{ //se o movimento não tiver peça inimiga
				matriz[linhaOrigem][colunaOrigem] = 0; //zerar posição inicial dela
				matriz[linhaOrigem+1][colunaOrigem-1] == A;
				movimentoInvalido = 0;
				jogador = 1;	
			}else{
				if(matriz[linhaOrigem+1][colunaOrigem-1] = B && matriz[linhaOrigem+2][colunaOrigem-2] == 0)//se houver uma peça inimiga e a proxima estiver vazia executa o movimento
				{
					matriz[linhaOrigem][colunaOrigem] = 0;
					matriz[linhaOrigem+1][colunaOrigem-1] = 0;
					matriz[linhaOrigem+2][colunaOrigem-2] = A;
					movimentoInvalido = 0;
					jogador = 1;
				}else{
					movimentoInvalido = 1;//se não tiver espaço p alocar peça 
				}						
			}			
		}			
	}else{
		if(movimento == 2 && matriz[linhaOrigem][colunaOrigem == A]){
			if(matriz[linhaOrigem+1][colunaOrigem+1] == 0){
			matriz[linhaOrigem][colunaOrigem] = 0;
			matriz[linhaOrigem+1][colunaOrigem+1] = A;
			movimentoInvalido = 0;
			jogador = 1;	
				}else{
					if(matriz[linhaOrigem+1][colunaOrigem+1] == B && matriz[linhaOrigem+2][colunaOrigem+2] == 0){
						matriz[linhaOrigem][colunaOrigem] = 0;
						matriz[linhaOrigem+1][colunaOrigem+1] = 0;
						matriz[linhaOrigem+2][colunaOrigem+2] = A;
						movimentoInvalido = 0;
						jogador = 1;
				}else{
						movimentoInvalido = 1;
				}
			}
		}		
	}
}

int vezJogador(){
	
	if(jogador == 1){
		printf("\n\tPEÇAS BRANCAS JOGANDO!!!");
	}else{
		printf("\n\tPEÇAS PRETAS JOGANDO!!!");
	}
	return 0;
}
