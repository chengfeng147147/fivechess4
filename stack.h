
#define MAXCOUNT 361
typedef struct step{

	int x;
	int y;
	int colour;
}Step;
void firstpointer_init();
void stack_init();
int stack_push(Step* step);
int stack_pop(Step* step);
int stack_firstpop(Step* step);
