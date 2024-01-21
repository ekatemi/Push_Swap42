#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i; //To store the index of the current node
	int	median; //To store the position of the median of the stack

	i = 0; //The first index is `0`
	if (!stack) //Check for am empty stack
		return ;
	median = stack_len(stack) / 2; //Calculate the median by dividing the length of a stack by 2
	while (stack) //Loop through all the nodes until the end of the stack is reached
	{
		stack->index = i; //Assign the current index value to the current node
		if (i <= median) //Check whether the current node is above or below the median
			stack->above_median = 1; //If above, set the above_median data of the node to true
		else
			stack->above_median = 0; //If below, set the above_median data of the node to false
		stack = stack->next; //Move to the next node for indexing
		++i; //Increment the index value to set the next node with
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)//Find `a` node's target in stack `b`
{
	t_stack_node	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack_node	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->num < a->num 
				&& current_b->num > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->num; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = find_max(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_stack_node *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	t_stack_node	*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->push_cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->push_cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = 1; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

static void	set_target_b(t_stack_node *a, t_stack_node *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	t_stack_node	*current_a; //To store the pointer to the current `a` node
	t_stack_node	*target_node; //To store the pointer of the target node for `b` node
	long			best_match_index; //To store the "closest bigger" number so far

	while (b)
	{
		best_match_index = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->num > b->num 
				&& current_a->num < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_a->num; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MAX) //If the best match value has not changed
			b->target_node = find_min(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}