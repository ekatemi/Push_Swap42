#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->index > (*a)->next->index) //Check if the bottom node is the biggest, but the top node is higher than the second node
	{
        sa(a);
    }
}

void sort_4(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *min = find_min_node(*a);
    on_top_a(a, min);
    pb(b, a);
    sort_three(a);
    pa(a, b);
}
//func returns closest bigger num to position correctly nodes
static t_stack_node *find_closest_bigger(t_stack_node *a, int target) {
    t_stack_node *closest = NULL;
    t_stack_node *min_node = find_min_node(a);

    // Traverse stack `a`
    while (a != NULL) 
    {
        // Check if the current element is bigger than the target
        if (a->index > target) 
        {
            // If `closest` is NULL or the current element is closer, update `closest`
            if (closest == NULL || a->index < closest->index) 
            {
                closest = a;
            }
        }
        // Move to the next element in stack `a`
        a = a->next;
    }
    if (closest == NULL)
        closest = min_node;
    // Return the node which contains closest bigger number found
    return closest;
}

void sort_5(t_stack_node **a, t_stack_node **b) 
{
    // Push the top two numbers from stack A to stack B
    //int dir = 0;
    //t_stack_node *target_a = NULL;

    pb(b, a);
    pb(b, a);

    // Sort stack A in ascending order
    sort_three(a);

    // Sort stack B in descending order
    if ((*b)->index < (*b)->next->index)
        sb(b);
    
    // Pop the sorted numbers from stack B and push them back to stack A
    while (*b) 
    {
        // Find the correct position to push the number back to stack A
        t_stack_node *target = find_closest_bigger(*a, (*b)->index);
        
        // Rotate stack A to position the target at the top
        on_top_a(a, target);
        //dir = dir_rotate(*a, target);
        // while (*a != target) 
        // {
        //     if (dir == 1)
        //         ra(a);
        //     if (dir == 2)
        //         rra(a); 
        // }
        // Push the number back to stack A
        pa(a, b);
    }

    //Rotate stack A to bring the smallest number to the top
    t_stack_node *min = find_min_node(*a);
    //dir = dir_rotate(*a, min);
    on_top_a(a, min);
}

