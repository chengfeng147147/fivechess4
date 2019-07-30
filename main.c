#include<stdio.h>
#include<stdlib.h>

#define Length 19
#define Width  19
#define EMPTY 0
#define BLACK 1
#define WHITE -1
int judgeLine(int* line, int length);
struct Data {
	int chess[Width][Length];

	struct Step {
		int x;
		int y;
	}Rstep;
	int steps;
} Fivechess;

void Initialize()
{
	for (int i = 0; i < 19; i++)
	{

		for (int j = 0; j < 19; j++)
		{
			Fivechess.chess[i][j] = 0;

		}
	}
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


/*int Rule(){
int savechess = 0;
int currentchess;
int count = 0;

for (int i = 0; i < Width; i++)//横扫描
{
for (int j = 0; j < Length; j++)
{
currentchess = Fivechess.chess[i][j];
if (currentchess == 0){
count = 0;
savechess = EMPTY;

}
else  if (currentchess == savechess)
{
count++;
//savechess = currentchess;
}
else //if (currentchess != savechess)
{
count = 1;
savechess = currentchess;
}

if (count == 5)
{
return currentchess;
}
}
}
for (int i = 0; i < Length; i++)//竖扫描
{
for (int j = 0; j < Width; j++)
{
currentchess = Fivechess.chess[j][i];
if (currentchess == 0){
count = 0;
savechess = EMPTY;

}
else  if (currentchess == savechess)
{
count++;
savechess = currentchess;
}
else if (currentchess != savechess)
{
count = 1;
savechess = currentchess;
}
if (count == 5)
{
return currentchess;
}
}
}
for (int j = 0; j < Length-4; j++) //左上到右下扫描,上半部分
{
for (int i = 0; i < Width-j; i++)
{
currentchess = Fivechess.chess[i ][i+j];
if (currentchess == 0){
count = 0;
savechess = EMPTY;

}
else  if (currentchess == savechess)
{
count++;
//savechess = currentchess;
}
else //if (currentchess != savechess)
{
count = 1;
savechess = currentchess;
}
if (count == 5)
{
return currentchess;
}
}
}
for (int j = 0; j < Length - 4; j++) //左上到右下扫描,下半部分
{
for (int i = 0; i < Length - j; i++)
{
currentchess = Fivechess.chess[i +j][i];
if (currentchess == 0){
count = 0;
savechess = EMPTY;

}
else  if (currentchess == savechess)
{
count++;
//savechess = currentchess;
}
else //if (currentchess != savechess)
{
count = 1;
savechess = currentchess;
}
if (count == 5)
{
return currentchess;
}
}
}
for (int j = 0; j < Length -4; j++) //右上到左下扫描,上半部分
{
for (int i = 18; i > j ; i--)
{
currentchess = Fivechess.chess[18-i][i-j];
if (currentchess == 0){
count = 0;
savechess = EMPTY;

}
else  if (currentchess == savechess)
{
count++;
//savechess = currentchess;
}
else //if (currentchess != savechess)
{
count = 1;
savechess = currentchess;
}
if (count == 5)
{
return currentchess;
}
}
}
for (int j = 0; j < Width; j++) //右上到左下扫描,下半部分
{
for (int i = 18; i < j; i--)
{
currentchess = Fivechess.chess[18-i+j][i];
if (currentchess == 0){
count = 0;
savechess = EMPTY;

}
else  if (currentchess == savechess)
{
count++;
//savechess = currentchess;
}
else //if (currentchess != savechess)
{
count = 1;
savechess = currentchess;
}
if (count == 5)
{
return currentchess;
}
}
}
return 0;
}*/
int creatLine()
{
	int savechess;
	int Line[Length];
	for (int i = 0; i < Length; i++)//行判断
	{
		judgeLine(Fivechess.chess[i], 19);
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
		int  k = 0, j = 0, x;
		for (x = i; x >= 0; x--)
		{
			Line[k] = Fivechess.chess[x][j];
			j++;
			k++;
		}

		savechess = judgeLine(Line, k );
		if (savechess != EMPTY){ return savechess; }
	}
	for (int i = 0; i >= 14; i--)
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
int main()
{
	Fivechess.steps = 1;
	int r = 0;
	Initialize();
	Go(1, 7);Go(0, 0);
	Go(4, 8);Go(0, 1);
	Go(8, 9);Go(0, 2);
	Go(0, 10);Go(0, 3);
	Go(11, 11); Go(0, 4);

	for (int i = 0; i < 19; i++){
		printf("\n");
		for (int j = 0; j < 19; j++){
			printf("%d", Fivechess.chess[i][j]);
		}

	}
	printf("\n");
	creatLine();
	r = creatLine();

	printf("%d\n", r);


	if (r == BLACK)
	{
		printf("黑棋胜");
	}
	if (r == WHITE)
	{
		printf("白棋胜");
	}
	system("pause");
	return 0;
}