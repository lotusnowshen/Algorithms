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

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

typedef TreeNode* Tree;

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

int main()
{
	Tree T;
	std::srand(100);
	for (int i = 0; i < 10; i++)
	{
		int _tmp = std::rand() % 100;
		insertOrder(T, _tmp);
		std::cout << _tmp << " ";
	}

	std::cout << std::endl;

	aft_order_cur(T);
	std::cout << std::endl;

	std::cout << "------------" << std::endl;
	aft_order(T);
	std::cout << std::endl;

	return 0;
}
