//@a.d.a.n_noa😇
#include <stdio.h>
#define MAX 5 //maximum stack size

int stack[MAX];
int top = -1; //top is -1 when stack is empty

void push(int x)
{
    if(top == MAX-1)
    {
        printf("Stack overlow!\n");
    }
    else 
    {
    stack[++top] = x;
    printf("%d pushed\n",x);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack underflow!\n");
    }
    else 
    {
        printf("%d popped\n",stack[top--]);
    }
}

void peek()
{
    if(top ==  -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for(int i = top; i >= 0; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();
    return 0;

}

//this code prints so many garbage values and i dont know why😂