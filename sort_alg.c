#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num) //Check if the bottom node is the biggest, but the top node is higher than the second node
	{
        sa(a);
    }
}

void sort_4(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *min = find_min_node(*a);
    on_top(a, min);
    pb(b, a);
    sort_three(a);
    pa(a, b);
}
//func returns closest bigger num to position correctly nodes
static t_stack_node *find_closest_bigger(t_stack_node *a, int target) {
    t_stack_node *closest = NULL;
    t_stack_node *min_node = find_min(a);

    // Traverse stack `a`
    while (a != NULL) 
    {
        // Check if the current element is bigger than the target
        if (a->num > target) 
        {
            // If `closest` is NULL or the current element is closer, update `closest`
            if (closest == NULL || a->num < closest->num) 
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

//function to define direction of rotation, 1 ra, 2 rra;
// int dir_rotate(t_stack_node *stack, t_stack_node *target_node)
// {
//     long i;
//     long mid;
//     int dir;

//     i = 0;
//     dir = 0;
//     mid = list_len(stack) / 2;
    
//     while (stack != NULL)
//     {
        
//         if (stack == target_node && i <= mid)
//             dir = 1;
//         else if (stack == target_node && i > mid)
//             dir = 2;
//         i++;    
//         stack = stack->next;
//     }
//     return (dir);
// }

void sort_5(t_stack_node **a, t_stack_node **b) {
    // Push the top two numbers from stack A to stack B
    int dir = 0;

    pb(b, a);
    pb(b, a);

    // Sort stack A in ascending order
    sort_three(a);

    // Sort stack B in descending order
    if ((*b)->num < (*b)->next->num)
        sb(b);
    // Pop the sorted numbers from stack B and push them back to stack A
    while (*b) 
    {
        // Find the correct position to push the number back to stack A
        t_stack_node *target = find_closest_bigger(*a, (*b)->num);
        
        // Rotate stack A to position the target at the top
        dir = dir_rotate(*a, target);
        while (*a != target) 
        {
            if (dir == 1)
                ra(a);
            if (dir == 2)
                rra(a); 
        }
        // Push the number back to stack A
        pa(a, b);
    }

    // Rotate stack A to bring the smallest number to the top
    t_stack_node *min = find_min_node(*a);
    dir = dir_rotate(*a, min);
    on_top(a, min);
    // while (!stack_sorted(*a)) 
    // {
    //     if (dir == 1)
    //         ra(a);
    //     else if (dir == 2)
    //         rra(a);
    // }
}

