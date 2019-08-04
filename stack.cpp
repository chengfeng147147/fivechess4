#include"stack.h"


struct stepStack{
		Step step[MAXCOUNT];
		int stack_pointer;
}step_stack;

void stack_init(){
	step_stack.stack_pointer = 0;
}
void stack_push(Step* step){
	step_stack.step[step_stack.stack_pointer].x = step->x;
	step_stack.step[step_stack.stack_pointer].y = step->y;
	step_stack.step[step_stack.stack_pointer].colour = step->colour;
	step_stack.stack_pointer++;
}

void stack_pop(Step* step){
	step->x = step_stack.step[step_stack.stack_pointer-1].x;
	step->y = step_stack.step[step_stack.stack_pointer-1].y;
	step->colour = step_stack.step[step_stack.stack_pointer-1].colour;
	step_stack.stack_pointer--;
}


