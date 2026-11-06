#include <stdio.h>
#include <stdlib.h>

void tabuleiro(char quadro[3][3])
{
	int i, j, linhaCentro[3] = {1, 6, 10}, colunaCentro[3] = {3, 10, 17};
	
	printf("     0       1       2\n");
	for (i = 0; i < 13; i++) 
	{
		if (i == 1) 
			printf("0 ");
        else if (i == 6) 
			printf("1 ");
        else if (i == 10) 
			printf("2 ");
        else 
			printf("  ");
        
        for ( j = 0; j < 21; j++) 
		{
			int l, c, desenhou = 0;
			
			for (l = 0; l < 3; l++)
			{
                for (c = 0; c < 3; c++)
                {
                    if (i == linhaCentro[l] && j == colunaCentro[c] && quadro[l][c] != 'L')
                    {
                        printf("%c", quadro[l][c]);
                        desenhou = 1;
                    }
                }
			}
			
			if (desenhou)
			{
				continue;
			}
			
            if (i == 4 || i == 8)
                printf("\xdc");
            else if (j == 7 || j == 14)
                printf("\xdb");
            else
                printf(" ");
        }
        printf("\n");
	}
	
}

int main()
{
	int linha, coluna, jogadas = 0, vitoria = 0, i;
	char quadro[3][3]= {
        {'L', 'L', 'L'},
        {'L', 'L', 'L'},
        {'L', 'L', 'L'}
    };
	char jogador = 'X';
	
	tabuleiro(quadro);
	
	while (jogadas < 9 && vitoria == 0)
	{
		printf("\n\nJOGADOR %c \n", jogador);
		printf("Digite o numero da linha e da coluna respectivamente: ");
		scanf("%d %d", &linha, &coluna);
		
		if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2)
		{
			printf("Numero invalido! Tente novamente");
			continue;
		}
		
		if (quadro[linha][coluna] != 'L')
		{
			printf("Este espaco ja esta ocupado! Tente novamente");
			continue;
		}
		
		quadro[linha][coluna] = jogador;
		jogadas++;
		
		
		system("cls");
		tabuleiro(quadro);
		
		for (i = 0; i < 3; i++) 
		{
            if (quadro[i][0] == jogador &&
                quadro[i][1] == jogador &&
                quadro[i][2] == jogador) 
			{
                vitoria = 1;
            }

            if (quadro[0][i] == jogador &&
                quadro[1][i] == jogador &&
                quadro[2][i] == jogador) 
			{
                vitoria = 1;
            }
        }

        if (quadro[0][0] == jogador &&
            quadro[1][1] == jogador &&
            quadro[2][2] == jogador) 
		{
            vitoria = 1;
        }

        if (quadro[0][2] == jogador &&
            quadro[1][1] == jogador &&
            quadro[2][0] == jogador) 
		{
            vitoria = 1;
        }

        if (vitoria == 1) 
		{
            printf("\nJogador %c venceu!\a\n", jogador);
        } 
		
		else if (jogadas == 9) 
		{
            printf("\nVELHA!!\a\n");
        } 
		
		else 
		{
            jogador = (jogador == 'X') ? 'O' : 'X';
        }

	}
	
	return 0;
}
