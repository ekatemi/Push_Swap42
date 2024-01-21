#include "push_swap.h"

void sort_three(t_stack_node **stack)
{
    t_stack_node *biggest;
    
    biggest = find_biggest(*stack);
    if (stack_sorted(*stack))
        return ;
    
    if (biggest == *stack)
        ra(stack, 1, 'a');
    else if (biggest == (*stack)->next)
        rra(stack, 1, 'a');
    else if (biggest == (*stack)->next->next) //maybe change
        sa(stack, 1, 'a');
}

void smallest_ontop(t_stack_node **a)
{
    t_stack_node *smallest = find_smallest(*a);
    if (!&stack_sorted)
    {
    if (smallest->above_median == 1)
        repeat_ra(a, 'a', smallest->push_cost);
    else if (smallest->above_median == 0)
        repeat_rra(a, 'a', smallest->push_cost);
    }
}

//use only if stack a 
void push_swap(t_stack_node **a, t_stack_node **b)
{
        long len_a;

        len_a = list_len(*a);
        if (len_a-- > 3 && !stack_sorted(*a))
            push_ab(b, a, 'b');
        if (len_a-- > 3 && !stack_sorted(*a))
            push_ab(b, a, 'b');
        
        while (len_a > 3 && !stack_sorted(*a))
            {
                //push_ab(b, a, 'b');
                refresh_stack_a(*a, *b);
                sort_b(a, b);
                len_a = list_len(*a);
            }
        //sort_three(a);
       /* while(*b)
        {
            refresh_stack_a(*a, *b);
            sort_a(a, b);
        }
        set_index_and_above_med(*a);
        smallest_ontop(a);*/
}

void opt_above_median(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    int rep = 0;
    if (cheapest_node->push_cost < cheapest_node->target_node->push_cost)
    {
        rep = cheapest_node->target_node->push_cost - cheapest_node->push_cost;
        repeat_rr(a, b, cheapest_node->push_cost);
        repeat_ra(a, 'b', rep);
    }
    else
    {
        rep = cheapest_node->push_cost - cheapest_node->target_node->push_cost;
        repeat_rr(a, b, cheapest_node->target_node->push_cost);
        repeat_ra(a, 'a', rep);
    }
}

void opt_below_median(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    int rep = 0;
    if (cheapest_node->push_cost < cheapest_node->target_node->push_cost)
    {
        rep = cheapest_node->target_node->push_cost - cheapest_node->push_cost;
        repeat_rrr(a, b, cheapest_node->push_cost);
        repeat_rra(a, 'a', rep);
    }
    else
    {
        rep = cheapest_node->push_cost - cheapest_node->target_node->push_cost;
        repeat_rrr(a, b, cheapest_node->target_node->push_cost);
        repeat_rra(a, 'a', rep);
    }
}

void sort_b(t_stack_node **a, t_stack_node **b)
{


    t_stack_node *cheapest_node = find_cheapest(*a);

    if (!*a || !*b || !cheapest_node)
        return ;

    if (cheapest_node->index == 0 && cheapest_node->target_node->index == 0)
        push_ab(b, a, 'b');
    else if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
        opt_above_median(a, b, cheapest_node);
    else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
        opt_below_median(a, b, cheapest_node);
    else if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 0)
    {
        repeat_ra(a, 'a', cheapest_node->push_cost);
        repeat_rra(b, 'b', cheapest_node->target_node->push_cost);
    }
    else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 1)
    {
        repeat_rra(a, 'a', cheapest_node->push_cost);
        repeat_ra(b, 'b', cheapest_node->target_node->push_cost);
    }
    refresh_stack_a(*a, *b);
}

void sort_a(t_stack_node **a, t_stack_node **b)
{
    //refresh_stacks(*a, *b);
    while (*b != NULL)///???
    {
        t_stack_node *cheapest_node = find_cheapest(*b);

        if (cheapest_node->index == 0 && cheapest_node->target_node->index == 0)
            push_ab(a, b, 'a');//this condition is dodgy
        else if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
            opt_above_median(a, b, cheapest_node);
        else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
            opt_below_median(a, b, cheapest_node);
        else if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 0)
        {
            repeat_ra(b, 'b', cheapest_node->push_cost);
            repeat_rra(a, 'a', cheapest_node->target_node->push_cost);
        }
        else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 1)
        {
            repeat_rra(b, 'b', cheapest_node->push_cost);
            repeat_ra(a, 'a', cheapest_node->target_node->push_cost);
        }
        refresh_stack_a(*a, *b);
    }
}