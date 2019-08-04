
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



extern int* getData();

extern void initialize();

extern void go(int x, int y);
extern void regret();



extern int creatLine(int x,int y);

