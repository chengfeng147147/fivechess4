#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"

int main()
{
	int r = 0;
	int* data;
	char re = 'n';
	char er = 'n';
	initialize();
	stack_initi();
	go(1, 7);
	regret(); go(2, 7);
	
	
	go(0, 0);//行
	go(4, 8);go(0, 1);
	go(8, 9);go(0, 2);
	go(0, 10);go(0, 3);
	go(11, 11);go(0, 4);

	data = getData();
	
	for (int i = 0; i < 19; i++){
		printf("\n");
		for (int j = 0; j < 19; j++){
			printf("%d", /*Fivechess.chess[i][j]*/*data);
			data++;
		}
	}
	printf("\n");
	
	r = creatLine(0,4);
	if (r == BLACK)
	{
		printf("正常\n");
	}
	else{
		printf("失败\n");
	}
	initialize();
	printf("是否开始复盘?y/n");
	scanf("%c",&re);
	while (re=='y')
	{
		printf("是继续复盘?y/n");
		scanf("%c", &er);
		if (er=='y')
		{
			recover_chess();
			data = getData();
			for (int i = 0; i < 19; i++){
				printf("\n");
				for (int j = 0; j < 19; j++){
					printf("%d", /*Fivechess.chess[i][j]*/*data);
					data++;
				}
			}
		}
	}
			system("pause");

			return 0;
		}
	