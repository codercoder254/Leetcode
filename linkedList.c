//a.d.a.n_noa😇
#include <stdio.h>
#include <stdlib.h>

typedef struct l1
{
    long long x;
    struct l1 *next;
}l1;

typedef struct l2
{
    long long y;
    struct l2 *next;
}l2;


typedef struct answer
{
    long long z;
    struct answer *next;
}answer;

//function to get input from user and return as reversed linked list
struct l1* getInputL1()
{
    //code to get input for l1 linked list
    printf("Enter elements for l1 linked list\n");//example 123
    long long value;
    scanf("%lld", &value);
    while(getchar() != '\n');

    struct l1 *head = NULL;
    struct l1 *newNode = NULL;
    struct l1 *temp = NULL;

    //if user enters 0
    if(value == 0)
    {
        newNode = (struct l1*)malloc(sizeof(struct l1));
        newNode->x = 0;
        newNode->next = NULL;
        return newNode;
    }

    while(value > 0)
    {
        int digit = value % 10;//get last digit
        value /= 10;//remove last digit by integer division

        newNode = (struct l1*)malloc(sizeof(struct l1));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }

        newNode->x = digit;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }

        else 
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    return head;
}
    


struct l2* getInputL2()
{
    //code to get input for l2 linked list
    printf("Enter elements for l2 linked list\n");//example 456
    long long value;
    scanf("%lld", &value);
    while(getchar() != '\n');

    struct l2 *head = NULL;
    struct l2 *newNode = NULL;
    struct l2 *temp = NULL;

    //if user enters 0
    if(value == 0)
    {
        newNode = (struct l2*)malloc(sizeof(struct l2));
        newNode->y = 0;
        newNode->next = NULL;
        return newNode;
    }

    while(value > 0)
    {
        int digit = value % 10;//get last digit
        value /= 10;//remove last digit by integer division

        newNode = (struct l2*)malloc(sizeof(struct l2));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }

        newNode->y = digit;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }

        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    return head;
}

//function to add two linked lists and return the answer
struct answer* addLinkedLists(struct l1 *l1Head, struct l2 *l2head)
{
    struct answer *head = NULL;
    struct answer *newNode = NULL;
    struct answer *tail = NULL;
    struct l1 *p1 = l1Head;
    struct l2 *p2 = l2head;
    int carry = 0;

    while(p1 != NULL || p2 != NULL || carry != 0)
    {
        int sum = carry;
        if(p1 != NULL)
        {
            sum += p1->x;
            p1 = p1->next;
        }
        if(p2 != NULL)
        {
            sum += p2->y;
            p2 = p2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        newNode = (struct answer*)malloc(sizeof(struct answer));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }

        newNode->z = digit;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;


}

long long linkedListToNumber(struct answer *head)
{
    long long number = 0;
    long long place = 1;
    struct answer *temp = head;

    while(temp != NULL)
    {
        number += temp->z * place;
        place *= 10;
        temp = temp->next;
    }

    return number;
}




int main()
{

    struct l1 *l1Head = getInputL1();
    struct l2 *l2Head = getInputL2();

    struct answer *answerHead = addLinkedLists(l1Head, l2Head);

    long long result = linkedListToNumber(answerHead);

    printf("The sum of the two linked lists is: %lld\n", result);

    return 0;


}