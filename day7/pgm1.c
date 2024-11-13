#include <stdio.h>
#include <stdlib.h>

int push(float *stk, int sp, int stackSize)
{
    if (stackSize == sp - 1)
    {
        puts("Stack is Full"); // Overflow
        return sp;
    }
    sp++;
    printf("Enter element to be pushed: ");
    scanf("%f", &stk[sp]);
    return sp;
}

int pop(float *stk, int sp)
{
    if (sp == -1)
    {
        puts("Stack is empty \n"); // undeflow
        return sp;
    }
    printf("Popped element is %.2f", stk[sp]);
    sp--;
    return sp;
}

float top(const float *stk, int sp)
{
    if (sp == -1)
        return -1.0f;
    return stk[sp];
}

int isFull(const int sp, int stackSize)
{
    if (sp == stackSize - 1)
    {
        puts("Stack is Full \n");
        return 1;
    }
    return 0;
}

void displayStack(const float *stk, int sp)
{
    if (sp == -1)
    {
        puts("Stack is empty \n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = sp; i >= 0; i--)
        printf("%-7.2f", stk[i]);
    putc('\n', stdout);
}

int isEmpty(int sp)
{
    if (sp == -1)
    {
        puts("Stack is empty");
        return 1;
    }
    return 0;
}

int main()
{
    int size = 0, choice = 0, sp = -1, numberOfOperations = 15;
    float *stack = NULL;
    float value = 0.0f;
    printf("Enter number of elements of the Stack: ");
    scanf("%d", &size);
    stack = (float *)malloc(sizeof(float) * size);
    printf("An empty stack of size %d is created \n", size);

    do
    {
        puts("\n1:Push 2:Pop 3:Display 4:Top 5:Exit. Your choice plz: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            sp = push(stack, sp, size);
            break;
        case 2:
            sp = pop(stack, sp);
            break;
        case 3:
            displayStack(stack, sp);
            break;
        case 4:
            value = top(stack, sp);
            if (value == -1.0f)
                puts("Stack is empty");
            else
                printf("Top element = %.2f \n", value);
            break;
        case 5:
            puts("End of program");
            numberOfOperations = 0;
            break;
        default:
            puts("Invalid choice enetered");
        }
        numberOfOperations--;
    } while (numberOfOperations >= 0);
    free(stack);
    stack = NULL; // we made the dangling pointer as null pointer
    return 0;
}