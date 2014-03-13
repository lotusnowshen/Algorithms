
#include "list.h"

void init_list(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(struct LinkNode));
	(*L)->data = 0;
	(*L)->next = NULL;
}

LinkList init_list_2(LinkList L)
{
	L = (LinkList)malloc(sizeof(struct LinkNode));
	L->data = 0;
	L->next = NULL;
	return L;
}


void destroy(LinkList* L)
{
	clear(*L);
	free(*L);
	*L = NULL;
}

void debug(LinkList L)
{
	LinkList p = L->next;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int get_length(LinkList L)
{
	LinkList p = L->next;
	int cnt = 0;
	while(p)
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}

int is_empty(LinkList L)
{
	return L->next == NULL;
}

int get_value(LinkList L, int pos, int *data)
{
	LinkList p = L->next;
	int ix = 0;
	while(p && ix < pos)
	{
		p = p->next;
		++ix;
	}
	if (p)
	{
		*data = p->data;
		return 0;
	}
	return -1;
}


void create_list_head(LinkList L, int *arr, int n)
{
	int ix = 0;
	LinkList tmp;
	for(ix = 0; ix < n; ix++)
	{
		tmp =(LinkList)malloc(sizeof(struct LinkNode));
		tmp ->data = arr[ix];
		tmp->next = L->next;
		L->next = tmp;
	}
}
void create_list_tail(LinkList L, int *arr, int n)
{
	LinkList tail = L;
	LinkList tmp;
	int ix;
	for(ix = 0; ix != n; ++ix)
	{
		tmp =(LinkList)malloc(sizeof(struct LinkNode));
		tmp ->data = arr[ix];
		tail->next = tmp;
		tail = tmp;
	}
	tail->next = NULL;
}

int insert_element(LinkList, int, int)
{

}


void clear(LinkList L)
{
	LinkList p = L->next;
	LinkList q;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}