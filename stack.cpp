#include"stack.h"


struct stepStack{
		Step step[MAXCOUNT];
		int stack_lastpointer;
		int stack_firstpointer;
}step_stack;

void stack_init(){
	step_stack.stack_lastpointer = 0;
	step_stack.stack_firstpointer=0;
}
void stack_push(Step* step){
	step_stack.step[step_stack.stack_lastpointer].x = step->x;
	step_stack.step[step_stack.stack_lastpointer].y = step->y;
	step_stack.step[step_stack.stack_lastpointer].colour = step->colour;
	step_stack.stack_lastpointer++;
}

void stack_pop(Step* step){
	step->x = step_stack.step[step_stack.stack_lastpointer-1].x;
	step->y = step_stack.step[step_stack.stack_lastpointer-1].y;
	step->colour = step_stack.step[step_stack.stack_lastpointer-1].colour;
	step_stack.stack_lastpointer--;
}
void stack_firstpop(Step* step){
	step->x = step_stack.step[step_stack.stack_firstpointer].x;
	step->y = step_stack.step[step_stack.stack_firstpointer].y;
	step->colour = step_stack.step[step_stack.stack_firstpointer].colour;
	step_stack.stack_firstpointer++;
}


