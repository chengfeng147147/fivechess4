#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"

int main()
{
	int r = 0;
	int* data;
	Initialize();
	Go(1, 7);Go(0, 0);//��
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
	
	r = creatLine();
	if (r == BLACK)
	{
		printf("����\n");
	}
	else{
		printf("ʧ��\n");
	}
	Initialize();//��
	Go(1, 7); Go(0, 0);
	Go(4, 8); Go(1, 0);
	Go(8, 9); Go(2, 0);
	Go(0, 10); Go(3,0);
	Go(11, 11); Go(4, 0);
	r = creatLine();
	if (r == BLACK)
	{
		printf("����\n");
	}
	else{
		printf("ʧ��\n");
	}
	Initialize();//���µ����� �ϰ벿��
	Go(4, 0); Go(0, 0);
	Go(3, 1); Go(5, 1);
	Go(2, 2); Go(0, 2);
	Go(1, 3); Go(5, 3);
	Go(0, 4); 
	r = creatLine();
	if (r == WHITE)
	{
		printf("����\n");
	}
	else{
		printf("ʧ��\n");
	}
	Initialize();//���µ����� �°벿��
	Go(18, 1); Go(0, 0);
	Go(17, 2); Go(0, 1);
	Go(16, 3); Go(0, 2);
	Go(15, 4); Go(0, 3);
	Go(14, 5); 
	r = creatLine();
	
	if (r == WHITE)
	{
		printf("����\n");
	}
	else{
		printf("ʧ��\n");
	}
	Initialize();//�������� �ϰ벿
	Go(0, 1); Go(0, 0);
	Go(1, 2); Go(3, 1);
	Go(2, 3); Go(0, 2);
	Go(3, 4); Go(0, 3);
	Go(4, 5); 
	r = creatLine();
	if (r == WHITE)
	{
		printf("����\n");
	}
	else{
		printf("ʧ��\n");
	}

	Initialize();//�������� �°벿
	Go(0, 1); Go(0, 0);
	Go(1, 2); Go(6, 1);
	Go(2, 3); Go(0, 2);
	Go(3, 4); Go(0, 3);
	Go(4, 5); 
	r = creatLine();
	if (r == WHITE)
	{
		printf("����\n");
	}
	else{
		printf("ʧ��\n");
	}
	system("pause");
	
	return 0;
}
