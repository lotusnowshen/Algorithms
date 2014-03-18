#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode *Tree;

void pre_order(Tree T)
{
    if(T)
    {
        printf("%d ", T->data);
        pre_order(T->left);
        pre_order(T->right);
    }
}

void mid_order(Tree T);

void aft_order(Tree T);

void level_order(Tree T)
{
    //定义队列
    queue<Tree> Q;
    //root入队列
    Q.push(T);
    while(!Q.empty())   //非空
    {
        //出队列 打印
        Tree tmp = Q.front();
        Q.pop();
        printf("%d ", tmp->data);
        //left  入队列
        if(tmp->left)
        {
            Q.push(tmp->left);
        }
        //right 入队列
        if(tmp->right)
        {
            Q.push(tmp->right);
        }
    }

}

Tree find_tree(Tree T, int key)
{
    if(NULL == T) return NULL;
    if(key == T->data)
    {
        return T;
    }else if(key < T->data)
    {
        return  find_tree(T->left, key);
    }else
    {
        return find_tree(T->right, key);
    }

}

Tree insert_tree(Tree T, int key)
{
    if(NULL == T)
    {
        T = (Tree)malloc(sizeof(struct TreeNode));
        T->data = key;
        T->left = NULL;
        T->right = NULL;
        return T;
    }else if (key == T->data)
    {
        return T;
    }
    else if(key < T->data)
    {
        T->left = insert_tree(T->left, key);
    }else
    {
        T->right = insert_tree(T->right, key);
    }
    return T;
}

int insert_tree2(Tree *T, int key)
{
    if(NULL == *T)
    {
        *T = (Tree)malloc(sizeof(struct TreeNode));
        (*T)->data = key;
        (*T)->left = NULL;
        (*T)->right = NULL;
        return 1;
    }else if (key == (*T)->data)
    {
        return 0;
    }else if (key < (*T)->data)
    {
        return insert_tree2(&((*T)->left), key);
    }else 
    {
        return insert_tree2(&((*T)->right), key);
    }


}


int main(void)
{

    return 0;
}
