#include "showchess.h"
#include "fivechesslogic.h"
#include<stdio.h>

void chessboard_show(int* data)
{
	/**/
	for (int i = 0; i < LENGTH; i++){
		printf("\n");
		for (int j = 0; j < WIDTH; j++){
			if (*data == -1)
			{
				printf(" O");
				
			}
			else if (*data == 1)
			{
				printf(" X");
				
			}
			else
			{
				printf(" .");

			}
			data++;
		}

	}
	
}
void show_winner(int savechess)
{
	if (savechess == -1)
	{
		printf("�����ʤ");
		
	}
	if (savechess == 1)
	{
		printf("�����ʤ");
	}
}