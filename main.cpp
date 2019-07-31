#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"
#include"showchess.h"
int main()
{
	
	int savechess;
	int* x;
	int* y;//Æå×Ó×ø±ê
	Initialize();
	chessboardShow();
	while (1)
	{
		y = getchess();
		x = y + 1;
		Go(*x, *y);
		chessboardShow();
		savechess=creatLine(*y, *x);
		judge(savechess);
	}
	
	
	system("pause");
	return 0;
}
