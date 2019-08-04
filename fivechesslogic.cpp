#include"stack.h"
#include "fivechesslogic.h"

int judgeLine(int* line, int length);

_fivechess Fivechess;

int* getData(){
	return (int*) Fivechess.chess;
}


void initialize()
{
	for (int x = 0; x < LENGTH; x++)
	{

		for (int y = 0; y < LENGTH; y++)
		{
			Fivechess.chess[x][y] = 0;

		}
	}
	Fivechess.steps = 1;
	stack_init();
}
void go(int x, int y)
{
	Step step;
	
  if (Fivechess.chess[x][y] == 0)
	{
	  step.x = x;
	  step.y = y;
	  step.colour = Fivechess.steps%2==0?1:-1;
	  stack_push(&step);
	  Fivechess.chess[x][y] = step.colour;
	  Fivechess.steps++;
	
	}
}
void regret()
{
	Step step;

	stack_pop(&step);
	Fivechess.chess[step.x][step.y] = 0;
	Fivechess.steps--;
	
	
}



int creatLine(int y,int x)
{
	int savex = x, savey = y;
	int savechess,count=0,cutcount;
	int Line[LENGTH];
	
	savechess = judgeLine(Fivechess.chess[y], LENGTH);//判断行
	if (savechess != EMPTY){ return savechess; }
	for (int i = 0; i < LENGTH; i++)//判断列
	{
		Line[count] = Fivechess.chess[i][x];
		count++;
	}
	savechess = judgeLine(Line, LENGTH);
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
		count = LENGTH - x;
		
	}
	else
	{
		cutcount = -x;
		count = LENGTH - cutcount;
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

