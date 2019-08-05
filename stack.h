#define MAXCOUNT 361
typedef struct step{

	int x;
	int y;
	int colour;
}Step;
void stack_init();
void stack_push(Step* step);
void stack_pop(Step* step);
void stack_firstpop(Step* step);