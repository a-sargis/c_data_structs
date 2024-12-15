#include <assert.h>
#include "stack.h"

int
main(void)
{
    Stack* stack = Stack_new(11);

    stack->push(stack, 22);
    stack->push(stack, 33);
    stack->push(stack, 44);

    assert("peek passed" && 44 == stack->peek(stack));

    stack->print(stack);

    assert("size passed" && 4 == stack->size(stack));

    stack->pop(stack);

    assert("pop passed" && 3 == stack->size(stack));

    Stack_destroy(stack);

    return 0;
}
