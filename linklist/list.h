/*
 * list.h
 *
 *  Created on: Mar 10, 2014
 *      Author: haha
 */

#ifndef LIST_H_
#define LIST_H_


struct LinkNode
{
    int data;
    struct LinkNode *next;
};
typedef struct LinkNode* LinkList;
void init_list(LinkList*);
LinkList init_list_2(LinkList);
void create_list_head(LinkList, int *, int);
void create_list_tail(LinkList, int *, int);
int insert_element(LinkList, int, int);
int delete_element(LinkList, int);
int get_length(LinkList);
int is_empty(LinkList);
int get_value(LinkList, int, int*);
int set_value(LinkList, int, int);
void debug(LinkList);
void reverse_list(LinkList);
void clear(LinkList);
void destroy(LinkList*);



#endif /* LIST_H_ */
