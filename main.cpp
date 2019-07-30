#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"

int main()
{
	int r = 0;
	int* data;
	Initialize();
	Go(1, 7);Go(0, 0);
	Go(4, 8);Go(0, 1);
	Go(8, 9);Go(0, 2);
	Go(0, 10);Go(0, 3);
	Go(11, 11); Go(0, 4);

	data = getData();
	
	for (int i = 0; i < 19; i++){
		printf("\n");
		for (int j = 0; j < 19; j++){
			printf("%d", /*Fivechess.chess[i][j]*/*data);
			data++;
		}

	}
	printf("\n");
	//creatLine();
	r = creatLine();

	printf("%d\n", r);


	if (r == BLACK)
	{
		printf("ºÚÆåÊ¤");
	}
	if (r == WHITE)
	{
		printf("°×ÆåÊ¤");
	}
	system("pause");
	return 0;
}
