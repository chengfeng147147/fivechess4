#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include"fivechesslogic.h"
#include"showchess.h"
#include"imageshow.h"
#include<synchapi.h>
#include"stack.h"

#define PLAY 1
#define REPLAY 2
int main()
{
	
	int winner;
	int x,y,px,py,rx,ry;//Æå×Ó×ø±ê
	int restart = 1;
	int judgego ;
	char player1[10], player2[10];
	char userblack[10], userwhite[10];
	int steps=1;
	int colour;
	int rcolour;
	int timep[6];
	int time[6];
	int judge;
	Link *link;
	rLink *rlink;
	int data[361];
	int find=1;
	int status = PLAY;
	int end = FALSE;
	
	while (1)
	{
		if (restart)
		{
			//end = FALSE;
			initialize();
			stack_initi();
			game_background();
			restart = 0;
			steps = 1;
			get_username(player1, player2);
			get_time(timep);
		}
		
		judge =get_mouse(&px, &py);
		switch(judge){
		case 1:
			if (status == PLAY&&!end){
				change_x_px(&x, &y, &px, &py);
				judgego = go(x, y);
				if (judgego){
					colour = steps % 2 == 0 ? 1 : -1;
					steps++;
					set_chess_pieces(x, y, colour);
				}
			}
			break;
		case 2:
			if (status == PLAY&&!end){
				int regretx, regrety, regretcolour;
				regret(&regretx, &regrety, &regretcolour);
				regret_imageshow(regretx, regrety);
				steps--;
			}
			break;
		case 4:
			if (status == REPLAY){
				end = get_rlinkfirst(rlink, &rx, &ry, &rcolour);
				if (end){
					set_chess_pieces(rx, ry, rcolour);
				}
				else{
					restart = 1;
					status = PLAY;
				}
				end = !end;
			}
			else{
				game_background();
				link = link_init();
				read_file(link);
				get_username(userblack, userwhite);
				get_timeshow(time);
				rlink = rlink_init();
				rlink = find_chessmanual(link, userblack, userwhite, timep);
				status = REPLAY;
			}
		default:
			break;

		}
		if (status == PLAY&&judge==1){
			winner = get_winner(x, y);
			if (winner)
			{
				show_winner(winner);
				write_file(timep, player1, player2);
				Sleep(3000);
				restart = 1;
				end = TRUE;
			}
		}
		/*
		if (status == PLAY){
			if (judge == 1)
			{
				change_x_px(&x, &y, &px, &py);
				judgego = go(x, y);
				if (judgego){
					colour = steps % 2 == 0 ? 1 : -1;
					steps++;
					set_chess_pieces(x, y, colour);
				}
			}
			else if (judge == 2)
			{
				int regretx, regrety, regretcolour;
				regret(&regretx, &regrety, &regretcolour);
				regret_imageshow(regretx, regrety);
			}
			else if(end) {
				game_background();
				link = link_init();
				read_file(link);
				get_username(userblack, userwhite);
				get_timeshow(time);
				rlink = rlink_init();
				rlink = find_chessmanual(link, userblack, userwhite, timep);
				status = REPLAY;
			}
			end = FALSE;
			if (status == PLAY){
				winner = get_winner(x, y);
				if (winner)
				{
					show_winner(winner);
					write_file(timep, player1, player2);
					Sleep(3000);
					restart = 1;
					end = TRUE;
				}
			}
		}
		else 
		{
			if (judge == 4){
				get_rlinkfirst(rlink, &rx, &ry, &rcolour);
				set_chess_pieces(rx, ry, rcolour);
			}
		}*/
		
	}
		
		
		
		
	
	system("pause");
	return 0;
}
