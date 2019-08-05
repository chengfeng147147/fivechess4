#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"
#include"showchess.h"
int main()
{
	
	int winner;
	int x;
	int y;//棋子坐标
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
			chessboard_show(data);
			restart = 0;
		}
		if (stepBack == 'n')

		{
			printf("\n请输入棋子坐标\n");
			scanf("%d%d", &y, &x);
			go(y, x);
		}
		
		printf("是否悔棋，y/n?");
		scanf("%c",&stepBack);
		if (stepBack == 'y')
		{
			regret();
		}
		
		data = get_data();
		chessboard_show(data);
		winner=creat_line(y, x);
		if (winner){
			show_winner(winner);
			printf("是否开始复盘？y/n");
			scanf("%c", &recover);
			if (recover == 'y'){
				initialize();
			}
			while (recover == 'y')
			{
				printf("是否继续复盘？y/n");
				scanf("%c", &recover2);
				if (recover2 == 'y')
				{
					recover_chess();
					data = get_data();
					chessboard_show(data);

				}
			}
			restart = 1;
		}
	
		
	}
	
	
	system("pause");
	return 0;
}
