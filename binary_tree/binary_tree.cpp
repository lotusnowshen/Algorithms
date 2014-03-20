//============================================================================
// Name        : binary_tree.cpp
// Author      : Chunyang Guo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <assert.h>

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

typedef TreeNode* Tree;

bool delete_node(Tree &p);
    
bool insertOrder(Tree &T, int data)
{
	if (T == NULL)
	{
		T = new TreeNode;
		T->data = data;
		T->left = T->right = NULL;
		return true;
	}
	else if (data < T->data)
	{
		return insertOrder(T->left, data);
	}
	else if (data > T->data)
	{
		return insertOrder(T->right, data);
	}
	else
		return false;
}


bool delete_tree(Tree &T, int key)
{
    if(T == NULL)
    {
        return false;
    }
    if(T->data == key)
    {
        return delete_node(T);    
    }else if (key < T->data)
    {
        return delete_tree(T->left, key);
    }else
    {
        return delete_tree(T->right, key);
    }
    

}


bool delete_node(Tree &p)
{
    assert(p);
    Tree tmp, s;
    if(p->left == NULL)    //左子树为空
    {
        tmp = p;
        p = p->right;
        free(tmp);
    }else if(p->right == NULL)    //右子树为空
    {
        tmp = p;
        p = p->left;
        free(tmp);
    }else                       //左右均不为空
    {
        tmp = p;
        s = p->right;
        while(s->left)              //找到直接后继
        {
            tmp = s;
            s = s->left;
        }
        p->data = s->data;     
        if(p == tmp)                //s没有左移
        {
            tmp->right = s->right;
        }else
        {
            tmp->left = s->right;
        }
        free(s);
    }

    return true;
}

void pre_order_cur(Tree T)
{
	if (T)
	{

		std::cout << T->data << " ";
		pre_order_cur(T->left);

		pre_order_cur(T->right);
	}
}
void mid_order_cur(Tree T)
{
	if (T)
	{

		mid_order_cur(T->left);
		std::cout << T->data << " ";
		mid_order_cur(T->right);
	}
}
void aft_order_cur(Tree T)
{
	if (T)
	{

		aft_order_cur(T->left);

		aft_order_cur(T->right);

		std::cout << T->data << " ";
	}
}

void pre_order(Tree T)
{
	std::stack<Tree> st;
	Tree p = T;
	while (p || !st.empty())
	{
		while (p)
		{
			std::cout << p->data << " ";
			st.push(p);
			p = p->left;
		}
		if (!st.empty())
		{
			p = st.top();
			st.pop();
			p = p->right;
		}
	}
}

void mid_order(Tree T)
{
	std::stack<Tree> st;
	Tree p = T;
	while (p || !st.empty())
	{
		while (p)
		{

			st.push(p);
			p = p->left;
		}
		if (!st.empty())
		{
			p = st.top();
			std::cout << p->data << " ";
			st.pop();
			p = p->right;
		}
	}
}

void aft_order(Tree T)
{
	std::stack<Tree> st;
	Tree current = NULL;
	Tree previous = NULL;
	st.push(T);
	while (!st.empty())
	{
		current = st.top();
		if ((current->left == NULL && current->right == NULL)
				|| (previous
						&& (previous == current->left
								|| previous == current->right)))
		{
			std::cout << current->data << " ";
			st.pop();
			previous = current;
		}
		else
		{
			if (current->right)
				st.push(current->right);
			if (current->left)
				st.push(current->left);
		}
	}
}

void destroy_tree(Tree &T)
{
	if(T == NULL)
		return;
	destroy_tree(T->left);
	destroy_tree(T->right);
	std::cout << T->data << " ";
	delete T;
	T = NULL;
}

int main()
{
	Tree T = NULL;
	for (int i = 0; i < 10; i++)
	{
		insertOrder(T, i);
	}

	std::cout << std::endl;

    mid_order(T);
	std::cout << std::endl;


    delete_tree(T, 5);


    mid_order(T);
	std::cout << std::endl;

	return 0;
}
