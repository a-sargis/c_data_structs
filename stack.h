//
// Created by sargis on 16.12.2024.
//

#pragma once

#include <stdlib.h>
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

struct Stack
{
    int    data;
    Stack* prev;

    void (*push)  (Stack* self, int data);
    void (*pop)   (Stack* self);
    int  (*peek)  (Stack* self);
    void (*print) (Stack* self);
    int  (*size)  (Stack* self);
};

void
push(Stack* self, int data)
{
    Stack* prevElem = (Stack*)malloc(sizeof(Stack));

    *prevElem = *self;
    self->data = data;
    self->prev = prevElem;
}

void
pop(Stack* self)
{
    *self = *self->prev;
}

int
peek(Stack* self)
{
    return self->data;
}

void
print(Stack* self)
{
    Stack* temp = self;

    while (temp != nullptr)
    {
        printf("%d\n", temp->data);
        temp = temp->prev;
    }
}

int
size(Stack* self)
{
    Stack* temp = self;
    int size = 0;

    while (temp != nullptr)
    {
        size += 1;
        temp = temp->prev;
    }

    return size;
}

Stack*
Stack_new(int data)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->data = data;
    stack->prev = nullptr;

    stack->push     = push;
    stack->peek     = peek;
    stack->pop      = pop;
    stack->print    = print;
    stack->size     = size;

    return stack;
}

void Stack_destroy(Stack* stack)
{
    Stack* temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->prev;
        free(temp);
    }

}

#endif //STACK_H
