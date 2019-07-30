
#include "fivechesslogic.h"
int judgeLine(int* line, int length);
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

	// 偶数下黑棋，奇数下白棋
	/*if(c % 2==0)
	{
	Fivechess.chess[a][b] = 1; //黑棋为1
	}
	else
	{
	Fivechess.chess[a][b] = -1; //白棋为-1
	}*/
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


int creatLine()
{
	int savechess;
	int Line[Length];
	for (int i = 0; i < Length; i++)//行判断
	{
		//judgeLine(Fivechess.chess[i], 19);
		savechess = judgeLine(Fivechess.chess[i], Width);
		if (savechess != EMPTY){ return savechess; }
	}
	for (int i = 0; i < Length; i++)  //取列判断
	{
		int k = 0;
		for (int j = 0; j < Length; j++)
		{
			Line[k] = Fivechess.chess[j][i];
			k++;
			 }
		savechess = judgeLine(Line, Width);
		if (savechess != EMPTY){return savechess;}
	}
	for (int i = 4; i <19; i++)  //左下右上；
	{
		int count = 0, j = 0, x;
		for (x = i; x >= 0; x--)
		{
			Line[count] = Fivechess.chess[x][j];
			j++;
			count++;
		}

		savechess = judgeLine(Line, count );
		if (savechess != EMPTY){ return savechess; }
	}
	for (int i = 0; i <= 14; i++)
	{
		int m = 0, y, w = 18;
		for (y = i; y<Length - i; y++)
		{
			Line[m] = Fivechess.chess[w][y];
			w--;
			m++;
		}
		savechess = judgeLine(Line, m );
		if (savechess != EMPTY){ return savechess; }

	}

	for (int i = 14; i >= 0; i--)//左上右下
	{
		int z, n = 0, l = 0;
		for (z = i; z<Length - i; z++)
		{
			Line[n] = Fivechess.chess[z][l];
			n++;
			l++;
		}
		savechess = judgeLine(Line, n );
		if (savechess != EMPTY){ return savechess; }
	}

	for (int i = 0; i < 15; i++)
	{
		int o = 0, p = 0, q;
		for (q = i; q < Length - i; q++)
		{
			Line[o] = Fivechess.chess[p][q];
			o++;
			p++;
		}
		savechess = judgeLine(Line, o );
		if (savechess != EMPTY){ return savechess; }
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

