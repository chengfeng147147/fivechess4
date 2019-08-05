
#define LENGTH 19
#define WIDTH  19
#define EMPTY 0
#define BLACK 1
#define WHITE -1

typedef struct Data {
	int chess[WIDTH][LENGTH];

	struct Step {
		int x;
		int y;
	}step;
	int steps;
}_fivechess;



extern int* get_data();

extern void initialize();
extern void stack_initi();
extern void go(int x, int y);
extern void regret();

extern void recover_chess();

extern int creat_line(int x,int y);

