#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"
#include<string.h>
#include"link.h"
#include"showchess.h"
#include"imageshow.h"
#include<graphics.h>

int main()
{
	int x, y, pixel_x, pixel_y;

	int colour = 1;
	game_background();
	while (1)
	{

		get_chess_pieces(&x, &y, &pixel_x, &pixel_y);
		set_chess_pieces(x, y,colour);
		get_regret();
		regret_imageshow( x, y);
	}
	system("pause");
			return 0;
		}
	