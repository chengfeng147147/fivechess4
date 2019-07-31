
#include "fivechesslogic.h"
int judgeLine(int* line, int length);
int* Topright(int x, int y);
_fivechess Fivechess;
int* getData(){
	return (int*) Fivechess.chess;
}

void Initialize()
{
	for (int i = 0; i < 19; i++)
	{

		for (int j = 0; j < 19; j++)
		{
			Fivechess.chess[i][j] = 0;

		}
	}
	Fivechess.steps = 1;
}
void Go(int a, int b)
{

	
	if (Fivechess.chess[a][b] == 0)
	{
		Fivechess.chess[a][b] = Fivechess.steps % 2 == 0 ? 1 : -1;
		Fivechess.Rstep.x = a;
		Fivechess.Rstep.y = b;
		Fivechess.steps++;
	}
	

}
void Regret()
{
	Fivechess.chess[Fivechess.Rstep.x][Fivechess.Rstep.y] = 0;
	Fivechess.steps--;
}



int creatLine(int y,int x)
{
	int savex = x, savey = y;
	int savechess,count=0,cutcount;
	int Line[Length];
	
	savechess = judgeLine(Fivechess.chess[y],Length);//判断行
	if (savechess != EMPTY){ return savechess; }
	for (int i = 0; i < Length; i++)//判断列
	{
		Line[count] = Fivechess.chess[i][x];
		count++;
	}
	savechess = judgeLine(Line, Length);
	if (savechess != EMPTY){ return savechess; }
	
	y += x;//左下右上，找到该点所在斜线的第一个点
	x = 0;
	if (y <= 18)
	{
		count = y + 1;
	}
	else
	{
		cutcount = y - 18;
		count = 19 - cutcount;
		y -= cutcount;
		x = cutcount;
	}
	for (int i = 0; i < count; i++)
	{
		Line[i] = Fivechess.chess[y][x];
		y--; x++;
	}
	savechess = judgeLine(Line, count);
	if (savechess != EMPTY){
		return savechess;
	}
	x = savex;
	y = savey;
	x -= y;
	y = 0;
	if (x >= 0)
	{
		count = Length - x;
		
	}
	else
	{
		cutcount = -x;
		count = Length - cutcount;
		y += cutcount;
		x += cutcount;
	}
	for (int i = 0; i < count;i++)
	{
		Line[i] = Fivechess.chess[y][x];
		y++;
		x++;
	}
	savechess = judgeLine(Line, count);
	if (savechess != EMPTY){
		return savechess;
	}
	return EMPTY;
}

int judgeLine(int* line, int length){
	int saveChess = EMPTY;
	int count = 0;
	int currentChess = EMPTY;

	for (int i = length; i > 0; i--){
		currentChess = *line;
		line++;
		if (currentChess == EMPTY){
			saveChess = EMPTY;
			count = 0;
		}
		else if (currentChess == saveChess){
			count++;
		}
		else {
			count = 1;
			saveChess = currentChess;
		}

		if (count == 5) {
			return currentChess;
		}
	}
	return EMPTY;
}

