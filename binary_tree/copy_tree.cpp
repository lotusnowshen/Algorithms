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

Tree copy_tree(Tree T)
{
    Tree ret_tree = NULL;
    if(T)
    {
        ret_tree = new TreeNode;
        ret_tree->data = T->data;
        ret_tree->left = copy_tree(T->left);
        ret_tree->right = copy_tree(T->right);
    }
    return ret_tree;
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
	Tree T;
	std::srand(100);
	for (int i = 0; i < 10; i++)
	{
//		int _tmp = std::rand() % 100;
		insertOrder(T, i);
//		std::cout << _tmp << " ";
	}
    std::cout << std::endl;

    mid_order_cur(T);

    std::cout << std::endl;
    
    pre_order_cur(T);


    std::cout << std::endl;
    
    Tree T2 = copy_tree(T);

    mid_order_cur(T2);
    std::cout << std::endl;
	return 0;
}
