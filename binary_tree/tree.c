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
#include <stdexcept>
#include <string>

struct TreeNode
{
	char data;
	TreeNode *left;
	TreeNode *right;
};

typedef TreeNode* Tree;

Tree rebuild_tree(const std::string &pre_order, std::size_t pre_start, std::size_t pre_end, 
	const std::string &mid_order, std::size_t mid_start, std::size_t mid_end)
{
	std::cout << "**************" << std::endl;

	std::cout << pre_order << std::endl;
	std::cout << pre_start << std::endl;
	std::cout << pre_end << std::endl;

	std::cout << pre_order[pre_start] << std::endl;
	std::cout << pre_order.substr(pre_start, pre_end - pre_start+1) << std::endl;

	std::cout << mid_order << std::endl;
	std::cout << mid_start << std::endl;
	std::cout << mid_end << std::endl;
	std::cout << mid_order.substr(mid_start, mid_end - mid_start +1) << std::endl;

	std::cout << "**************" << std::endl;


	if(pre_start > pre_end)
		return NULL;

	char root_value = pre_order[pre_start];
	Tree root = new TreeNode;
	root->data = root_value;
	root->left = NULL;
	root->right = NULL;

	/*if(pre_start == pre_end || mid_start == mid_end)
		return root;*/

	if(pre_start == pre_end)
	{
		if(mid_start == mid_end && 
			pre_order[pre_start] == mid_order[mid_start])
		{
			return root;
		}
		else
		{
			throw std::runtime_error("mark001");
		}
	}


	std::size_t pos = std::string::npos;
	for(std::size_t ix = mid_start; ix <= mid_end; ++ix)
	{
		if (mid_order[ix] == root_value)
		{
			pos = ix;
			break;
		}
	}
	if(pos == std::string::npos)
		throw std::runtime_error("mark002");

	std::size_t left_length = pos - mid_start;
	std::size_t right_length = mid_end - pos;

	root->left = rebuild_tree(pre_order, pre_start+1, pre_start+left_length,
			mid_order, mid_start, pos-1);
	root->right = rebuild_tree(pre_order, pre_start+left_length+1, pre_end,
			mid_order, pos+1, mid_end);
	return root;
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


int main(int argc, char const *argv[])
{
	std::string pre;
	std::string mid;
	std::cin >> pre >> mid;
	Tree T = rebuild_tree(pre, 0, pre.length()-1,
			mid, 0, mid.length()-1);
	aft_order_cur(T);
	return 0;
}