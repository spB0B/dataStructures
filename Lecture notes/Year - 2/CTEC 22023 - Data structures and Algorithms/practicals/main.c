#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } boolean;

typedef int StackEntry;

typedef struct node {
    StackEntry entry;
    struct node *next;
}Node;

typedef struct {
    int no_element;
    boolean full;
    Node *top;
}Stack;

void createStack(Stack *stack) {
    stack->top = NULL;
    stack->no_element = 0;
    stack->full = FALSE;
}

void pushStack(StackEntry item, Stack *stack) {
    Node *np;
    np = (Node *)malloc(sizeof(Node));
    if (np == NULL) {
        printf("not enough memory");
        stack->full = TRUE;
    }else {
        np->entry = item;
        np->next = stack->top;
        stack->top = np;
        stack->no_element++;
    }
}

void popStack(StackEntry *item, Stack *stack) {
    Node *np;
    *item = stack->top->entry;
    np = stack->top;
    stack->top = stack->top->next;
    stack->no_element--;
    free(np);
}

boolean isStackEmpty(const Stack *stack) {
    return(stack->top == NULL);
}

boolean isStackFull(const Stack *stack) {
    return(stack->full);
}

void printStack(Stack *stack) {
    Node *np;
    np = stack->top;
    while(np != NULL) {
        printf("%d, ",np->entry);
        np = np->next;
    }
}

int main(void)
{
    Stack myStack;
    createStack(&myStack);

    pushStack(10, &myStack);
    pushStack(20, &myStack);
    pushStack(30, &myStack);
    pushStack(40, &myStack);
    pushStack(50, &myStack);
    printStack(&myStack);
    StackEntry item;
    while (1) {
        popStack(&item, &myStack);
        if (isStackEmpty(&myStack)) {
            printf("\nstack is empty\n");
            exit(1);
        }else {
            printf("\nstack is not empty\n");
            printStack(&myStack);
        }

    }
    return 0;
}
