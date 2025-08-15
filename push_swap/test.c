#include "push_swap.h"

t_stack	*create_stack(char **argv)
{
	t_stack *a_stack;
	t_stack *temp_stack;

	while (argv)
	{
		
	}
	return (a_stack);
}

int main(void)
{
	t_stack	*a_stack;
	a_stack = create_stack(10);
	printf("%d\n", a_stack->num);
	free(a_stack);
	return(0);
}
