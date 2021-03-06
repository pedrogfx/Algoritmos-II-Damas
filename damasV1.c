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

int matriz[TAB][TAB];
char pecas[3] = { ' ', 'A', 'B' }; 
int menu = 0, i = 0, j = 0; 
int fimJogo = 0, coluna = 0, iLinha =0, iColuna=0, movimentoInvalido, linhaDestino = 0,
colunaDestino = 0, linhaOrigem = 0, colunaOrigem = 0, movimento = 0, jogador = 1, brancaComida = 0, pretaComida = 0; //variaveis das peças

int main() {
	
	setlocale(LC_ALL, "portuguese");
	do
	{
		printf("\n\t Bem vindo ao jogo de Damas!");
		printf("\n\t 1 - Iniciar jogo.");
		printf("\n\t 2 - Informações do jogo.");
		printf("\n\t 3 - Sair do jogo.");
		printf("\n\n\t Selecione uma opção => ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1: //COMEÇAR O JOGO (FUNÇÃO JOGO)
			inicioGame();
			movimentarPeca();
			
			
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

void inicioGame(){
	for(iLinha = 0 ; iLinha < 8; iLinha++)//percorer linhas
	{
		for(iColuna = 0 ; iColuna < 8; iColuna++)//colunas
		{
			matriz[iLinha][iColuna] = 0;//zerar tudo
		}
	}
			for(iColuna = coluna; iColuna < 8; iColuna+=2)//atribuir e somar casas em branco
			{
				matriz[iLinha][iColuna] = CASA_BRANCA;
			}
		for(iLinha = 0 ; iLinha < 8; iLinha++)
		{
			for(iColuna = 0 ; iColuna < 8; iColuna++)
			{
				if (((iLinha % 2 == 0) && (iColuna % 2 == 0)) || ((iLinha % 2 == 1) && (iColuna % 2 == 1)))//teste p colocar as peças
				{
				if (iLinha < 3) matriz[iLinha][iColuna] = A; //brancas
				else if (iLinha > 4) matriz[iLinha][iColuna] = B; //pretas
				else matriz[iLinha][iColuna] = 0;//vazio
				}
			}
		}
	}
	
void imprimirTabuleiro(){
	system("cls");
    printf("\t     TABULEIRO");
    printf("\n----------------------------------\n");
    for(iColuna = 0 ; iColuna < 8 ; iColuna++){ //mostrar nº na parte superior dos indices
		printf("   %d",iColuna);
	}
	for(iLinha = 0; iLinha < 8; iLinha++)
	{
		printf("\n%d ",iLinha); //mostrar coluna
		for(iColuna = 0; iColuna < 8; iColuna++)
		{
			if(matriz[iLinha][iColuna] == A)//printar casas brancas
			{
				printf(" A  ");
			}else{
				if(matriz[iLinha][iColuna] == B)//printar casas pretas
				{
					printf(" B  ");
				}else{
					if(matriz[iLinha][iColuna] == CASA_BRANCA)//printar casas em branco
					{
						printf(" .  ");
					}else{
						printf(" .  ");
					}
				}
			}
		}
		printf("\n");
	}
}
  

void movimentarPeca(){
	
	while(brancaComida <= 11 || pretaComida <= 11){
	imprimirTabuleiro();
	vezJogador();
	
	printf("\n\tDIGITE A PEÇA QUE DESEJA MOVIMENTAR!");//escolher peça
	printf("\n\n\t\t\tLINHA => ");
	scanf_s("\n%d", &linhaOrigem);
	printf("\n\n\t\t\tCOLUNA => ");
	scanf_s("\n%d", &colunaOrigem);
	printf("\n\tQUAL MOVIMENTO DESEJA FAZER?");//ocupar peça
	printf("\n\t 1 = ESQUERDA \n\t 2 = DIREITA");
	printf("\n\n\t\t\tJOGADA => ");
	scanf("\n\t%d", &movimento);

	if(jogador == 1){//jogada p/ peça preta      
		if(movimento == 1 && matriz[linhaOrigem][colunaOrigem] == B && linhaOrigem -1 >= 0 && colunaOrigem -1 >= 0)//teste do movimento e limitação
		{
			if(matriz[linhaOrigem-1][colunaOrigem-1] == 0){ //se o movimento for p/ as peças pretas, -1 casa p/ subir
				matriz[linhaOrigem][colunaOrigem] = 0; //resetar ela p/ olocar p/ peças pretas
				matriz[linhaOrigem-1][colunaOrigem-1] = B; //colocar a peça preta
				jogador = 0; //trocar a vez do jogador				
			}else{
				if(matriz[linhaOrigem-1][colunaOrigem-1] == A && matriz[linhaOrigem-2][colunaOrigem-2] == 0 && linhaOrigem -2 >= 0 && colunaOrigem -2 >= 0)//se houver uma peça branca no caminho faz o movimento -2
				{
					matriz[linhaOrigem][colunaOrigem] = 0; //reset
					matriz[linhaOrigem-1][colunaOrigem-1] = 0; //-1 p deixar em branco a peça que passou por cima
					matriz[linhaOrigem-2][colunaOrigem-2] = B; //colocar a peça preta
					jogador = 0; //trocar a vez do jogador
					brancaComida++;
				}else{
					movimentoInvalido = 1; //caso movimento não seja validado pelo restante "=1" p mostrar erro
				}								
			}
										
		}else{//jogada p/ direita
			if(movimento == 2 && matriz[linhaOrigem][colunaOrigem] == B && linhaOrigem -1 >= 0 && colunaOrigem +1 < 8)//se escolhido for igual a B faz o movimento / não ultrapassar o limite do tabuleiro
			{
				if(matriz[linhaOrigem-1][colunaOrigem+1] == 0){ //caso não tenha peça inimiga na diagonal
					matriz[linhaOrigem][colunaOrigem] = 0; //same above
					matriz[linhaOrigem-1][colunaOrigem+1] = B; //same above
					movimentoInvalido = 0; //movimento errado zerado
					jogador = 0; //trocar a vez do jogador
				}else{
					if(matriz[linhaOrigem-1][colunaOrigem+1] == A && matriz[linhaOrigem-2][colunaOrigem+2] == 0 && linhaOrigem -1 >= 0 && colunaOrigem +2 < 8)
					{
						matriz[linhaOrigem][colunaOrigem] = 0;
						matriz[linhaOrigem-1][colunaOrigem+1] = 0;
						matriz[linhaOrigem-2][colunaOrigem+2] = B;
						jogador = 0;
						brancaComida++;
					}
				}				
			}else{
				movimentoInvalido = 1;
			}		
		}
	}else{
		if(jogador == 0){//jogada peça branca
		if(movimento == 1 && matriz[linhaOrigem][colunaOrigem] == A && linhaOrigem+1 >= 0 && colunaOrigem-1 <=0)//moimento p/ direita
		{
			if(matriz[linhaOrigem+1][colunaOrigem-1] == 0)//se o movimento não tiver peça inimiga
			{
				matriz[linhaOrigem][colunaOrigem] = 0; //zerar posição inicial dela
				matriz[linhaOrigem+1][colunaOrigem-1] = A;
				movimentoInvalido = 0;
				jogador = 1;	
			}else{
				if(matriz[linhaOrigem+1][colunaOrigem-1] == B && matriz[linhaOrigem+2][colunaOrigem-2] == 0 && linhaOrigem+2 >= 0 && colunaOrigem-2 <= 0)//se houver uma peça inimiga e a proxima estiver vazia executa o movimento
				{
					matriz[linhaOrigem][colunaOrigem] = 0;
					matriz[linhaOrigem+1][colunaOrigem-1] = 0;
					matriz[linhaOrigem+2][colunaOrigem-2] = A;
					jogador = 1;
					pretaComida++;
				}else{
					movimentoInvalido = 1;//se não tiver espaço p alocar peça 
				}					
			}		
		}else{
		if(movimento == 2 && matriz[linhaOrigem][colunaOrigem] == A && linhaOrigem +1 < 8  && colunaOrigem +1 < 8 ){
			if(matriz[linhaOrigem+1][colunaOrigem+1] == 0){
				matriz[linhaOrigem][colunaOrigem] = 0;
				matriz[linhaOrigem+1][colunaOrigem+1] = A;
				jogador = 1;	
					}else{
						if(matriz[linhaOrigem+1][colunaOrigem+1] == B && matriz[linhaOrigem+2][colunaOrigem+2] == 0 && linhaOrigem +2 < 8  && colunaOrigem +2 < 8){
							matriz[linhaOrigem][colunaOrigem] = 0;
							matriz[linhaOrigem+1][colunaOrigem+1] = 0;
							matriz[linhaOrigem+2][colunaOrigem+2] = A;
							jogador = 1;
							pretaComida++;
						}	
					}
				}else{
					movimentoInvalido = 1;
				}		
			}
		}
	}
	
	if(movimentoInvalido == 1){
		printf("\n\t MOVIMENTO INVÁLIDO!");
		movimentoInvalido = 0;
	}
	
	}
}

void vezJogador(){
	
	if(jogador == 0){
		printf("\n\n\tPEÇAS %d - BRANCAS JOGANDO!!!", A);
	}else{
		printf("\n\n\tPEÇAS %d - PRETAS JOGANDO!!!", B);
	}
}   
