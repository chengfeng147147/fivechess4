#include "showchess.h"
#include "fivechesslogic.h"
#include<stdio.h>

void chessboardShow(int* data)
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
void showWinner(int savechess)
{
	if (savechess == -1)
	{
		printf("°×Æå»ñÊ¤");
		
	}
	if (savechess == 1)
	{
		printf("ºÚÆå»ñÊ¤");
	}
}