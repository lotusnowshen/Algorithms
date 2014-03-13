##ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkNode
{
	/* data */
	int data;
	struct LinkNode *next;
};

typedef struct LinkNode *Stack;

void init_stack(Stack *s);
void destroy_stack(Stack *s);

int is_empty(Stack s);
void push(Stack s, int data);
int pop(Stack s, int *data);

int top(Stack s, int *data);
void clear(Stack s);


#endif





