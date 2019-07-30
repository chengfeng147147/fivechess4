
#define Length 19
#define Width  19
#define EMPTY 0
#define BLACK 1
#define WHITE -1

typedef struct Data {
	int chess[Width][Length];

	struct Step {
		int x;
		int y;
	}Rstep;
	int steps;
}_fivechess;

extern int* getData();

extern void Initialize();

extern void Go(int a, int b);
extern void Regret();



extern int creatLine();

