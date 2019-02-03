#include "depot.h"
#include "stack.h"

struct DepotImplementation
{
    Stack stack;
};

Depot create_depot()
{
    Depot depot = (Depot)smalloc(sizeof(struct DepotImplementation));
    depot->stack = create_stack();
    return depot;
}

void delete_depot(Depot depot)
{
    delete_stack(depot->stack);
    sfree(depot);
}

int get_count(Depot depot)
{
    int temp = get_count(depot->stack);
    int count = temp / STACK_SIZE_LIMIT;

    if (temp % STACK_SIZE_LIMIT > 0)
    {
        return count + 1;
    }
    else
    {
        return count;
    }
}

void push_depot(Depot depot, Product *product)
{
    push_stack(depot->stack, product);
}

Product *pop_depot(Depot depot)
{
    return (Product *)pop_stack(depot->stack);
}