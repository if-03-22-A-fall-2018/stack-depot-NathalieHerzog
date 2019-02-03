#include "stack.h"

struct StackImplementation
{
    struct Node *head;
    int length;
};

struct Node
{
    struct Node *next;
    void *data;
};

Stack create_stack()
{
    Stack stack = (Stack)smalloc(sizeof(StackImplementation));
    stack->head = 0;
    stack->length = 0;
    return stack;
}

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack)
{
    Node *current = stack->head;

    while (current != 0)
    {
        Node *temp = current;
        current = current->next;

        sfree(temp);
    }

    sfree(stack);
}

/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void *data)
{
    Node *node = (Node *)smalloc(sizeof(Node));
    node->data = data;
    node->next = 0;

    if (stack->head == 0)
    {
        stack->head = node;
        stack->length++;
        return;
    }

    Node *curr = stack->head;

    stack->head = node;
    stack->head->next = curr;

    stack->length++;
}

/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack)
{
    return stack->length;
}

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void *pop_stack(Stack stack)
{
    if (stack->head == 0)
    {
        return 0;
    }

    Node* toDelete = stack->head;
    stack->head = stack->head->next;
    void* temp = toDelete->data;
    sfree(toDelete);
    stack->length--;
    
    return temp;
}

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
*/
void *peek_stack(Stack stack)
{
    if (stack->head == 0)
    {
        return 0;
    }

    return stack->head->data;
}