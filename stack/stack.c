#include "stack.h"

void init_stack(Stack *s)
{
	*s = (struct LinkNode*)malloc(sizeof(struct LinkNode))
	(*s) -> next = NULL;
}
void destroy_stack(Stack *s)
{
	clear(*s);
	free(*s);
	*s = NULL;
}

int is_empty(Stack s)
{
	return s->next == NULL;
}
void push(Stack s, int data)
{
	struct LinkNode *new_node = 
		(struct LinkNode*)malloc(
			sizeof(struct LinkNode));
		new_node -> data = data;
		new_node->next = s->next;
		s->next = new_node;
}
int pop(Stack s, int *data)
{
	struct LinkNode* tmp = s->next;
	if(is_empty)
	{
		printf("error\n");
		return -1;
	}
	*data = s->next->data;
	s->next = s->next->next;
	free(tmp);
	tmp = NULL;
	return 0;
}

int top(Stack s, int *data)
{
	if(is_empty)
	{
		printf("error\n");
		return -1;
	}
	*data = s->next->data;
	return 0;
}
void clear(Stack s)
{
	struct LinkNode *tmp = s->next;
	struct LinkNode *del;
	while(tmp)
	{	
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	s->next = NULL;
}

