#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"
#include"showchess.h"
int main()
{
	
	int winner;
	int x;
	int y;//��������
	int* data;
	int restart = 1;
	char stepBack='n';
	
	while (1)
	{
		if (restart){
			initialize();
			data = getData();
			chessboardShow(data);
			restart = 0;
		}
		if (stepBack == 'n')

		{
			printf("\n��������������\n");
			scanf("%d%d", &y, &x);
			go(y, x);
		}
		
		printf("�Ƿ���壬y/n?");
		scanf("%c",&stepBack);
		if (stepBack == 'y')
		{
			regret();
		}
		
		data = getData();
		chessboardShow(data);
		winner=creatLine(y, x);
		if (winner){
			showWinner(winner);
			restart = 1;
		}
	
		
	}
	
	
	system("pause");
	return 0;
}
