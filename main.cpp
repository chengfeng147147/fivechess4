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
	char recover = 'n';
	char recover2 = 'n';
	while (1)
	{
		if (restart){
			initialize();
			stack_initi();
			data = get_data();
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
		
		data = get_data();
		chessboardShow(data);
		winner=creat_line(y, x);
		if (winner){
			showWinner(winner);
			printf("�Ƿ�ʼ���̣�y/n");
			scanf("%c", &recover);
			if (recover == 'y'){
				initialize();
			}
			while (recover == 'y')
			{
				printf("�Ƿ�������̣�y/n");
				scanf("%c", &recover2);
				if (recover2 == 'y')
				{
					recover_chess();
					data = get_data();
					chessboardShow(data);

				}
			}
			restart = 1;
		}
	
		
	}
	
	
	system("pause");
	return 0;
}
