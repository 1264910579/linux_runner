/*
 * @Author: your name
 * @Date: 2021-09-02 16:52:10
 * @LastEditTime: 2021-09-02 17:34:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Desktop\bst.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct tree_node{
    int data;
    struct tree_node *lchild;
    struct tree_node *rchild;
}node_t;

node_t *request_tree_node(void)
{
    node_t *new_node;

    new_node = malloc(sizeof(node_t));
    if(new_node == NULL)
    {
        perror("申请二叉树节点失败");
        return NULL;
    }

    new_node->lchild = NULL;
    new_node->rchild = NULL;

    return new_node;
}


/*
    函数功能:
        插入insert_node节点到root这棵树当中
    返回值:
        如果传入的root为NULL,这返回insert_node的地址,返回这返回root原本的值
*/
node_t *insert_node_to_tree(node_t *root, node_t *insert_node)
{
    if(root == NULL)
        return insert_node;

    if(insert_node->data < root->data)//如果掺入的节点的数据比root要小
    {
        //插入到你的左树
        root->lchild = insert_node_to_tree(root->lchild, insert_node);
    }
    else
    {
        //插入到你的右树
        root->rchild = insert_node_to_tree(root->rchild, insert_node);
    }

    return root;//传入的节点地址是什么就返回什么
}


void display_tree_node(node_t *root)
{
    if(root == NULL)
        return;

    display_tree_node(root->lchild);

    printf("%d ", root->data);

    display_tree_node(root->rchild);
}


int main(void)
{
    node_t *root = NULL;
    node_t *new_node;
    int input_value;

    while(1)
    {
        scanf("%d", &input_value);

        if(input_value > 0)
        {
            //新建节点
            new_node = request_tree_node();
            new_node->data = input_value;
            //插入到树当中

            root = insert_node_to_tree(root, new_node);
        }
        else
        {
            //删除指定的节点

        }

        printf("树的数据有:");
        //遍历一整棵树
        display_tree_node(root);
        printf("\n");
    }
    

    return 0;
}