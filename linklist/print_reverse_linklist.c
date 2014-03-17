#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkNode
{
    int data;
    struct LinkNode *next;
};

typedef struct LinkNode *LinkList;

void print_reverse_linklist(LinkList L)
{
    if(L)
    {
        print_reverse_linklist(L->next);
        printf("%d ", L->data);
    }
}

int main(void)
{
    //
    //
    //
    //
    return 0;
}
