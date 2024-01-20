#include "push_swap.h"

//before use it check if the stack has 3 nodes
void sort_three(t_stack_node **head)
{
    t_stack_node *biggest = find_biggest(*head);
    
    if (biggest == *head)
        ra(head, 1, 'a');
    else if (biggest == (*head)->next)
        rra(head, 1, 'a');
    else if (biggest == (*head)->next->next)
        sa(head, 1, 'a');
}

void sort_five(t_stack_node **a,t_stack_node **b)
{
    push_ab(b, a, 'b');
    push_ab(b, a, 'b');
    sort_three(a);
    sort_a(a, b);
    smallest_ontop(a);
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
void push_swap(t_stack_node *a, t_stack_node *b)
{
    long int len = list_len(a);
    if (len == 4)
    {
        push_ab(&b, &a, 'b');
        sort_three(&a);
        sort_a(&a, &b);
        smallest_ontop(&a);
    }
    else if (len >= 5)
    {
        push_ab(&b, &a, 'b');
        push_ab(&b, &a, 'b');
        sort_b(&a, &b);
        sort_three(&a);
        sort_a(&a, &b);
        smallest_ontop(&a);
    }
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
    while (list_len(*a) > 3)
    {
        t_stack_node *cheapest_node = find_cheapest(*a);

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
        refresh_stacks(*a, *b);
    }
}

void sort_a(t_stack_node **a, t_stack_node **b)
{
    while (list_len(*b))///???
    {
        t_stack_node *cheapest_node = find_cheapest(*b);

        if (cheapest_node->index == 0 && cheapest_node->target_node->index == 0)
            push_ab(a, b, 'a');
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
        refresh_stacks(*a, *b);
    }
}