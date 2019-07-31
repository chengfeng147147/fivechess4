#include "showchess.h"
#include "fivechesslogic.h"
#include<stdio.h>

void chessboardShow()
{
	int* data;
	data = getData();
	for (int i = 0; i < 19; i++){
		printf("\n");
		for (int j = 0; j < 19; j++){
			if (*data == -1)
			{
				printf("o");
				data++;
			}
			else if (*data == 1)
			{
				printf("x");
				data++;
			}
			else
			{
				printf("*");
			}
		}

	}
	
}
int* getchess()
{
	int p[2];
	printf("\nÇëÊäÈëÆå×Ó×ø±ê\n");
	
	scanf("%d%d",p,p+1);
	return p;
}
void judge(int savechess)
{
	if (savechess == -1)
	{
		printf("°×Æå»ñÊ¤");
		
		Initialize();
		chessboardShow();
	}
	if (savechess == 1)
	{
		printf("ºÚÆå»ñÊ¤");
		Initialize();
		chessboardShow();
	}
}