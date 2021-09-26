#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct tree_node{
	int data;
	int height;//节点的高度
	struct tree_node *lchild;//左子树
	struct tree_node *rchild;//右子树
}node_t;


#define MAX(a, b)	((a)>(b)?(a):(b))
//申请一个节点
node_t *request_tree_node(int data)
{
	node_t *node;
	
	node = malloc(sizeof(node_t));
	if(node == NULL)
	{
		perror("申请新节点异常");
		return NULL;
	}

	node->data = data;
	node->height = 1;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}


//获取树的高度
int get_tree_height(node_t *root)
{
	if(root == NULL)
		return 0;
		
	return MAX(get_tree_height(root->lchild), get_tree_height(root->rchild))+1;
}

//右旋转,为了直接解决左左不平衡
node_t *tree_right_rotate(node_t *root)
{
	node_t *tmp;
	
	tmp = root->lchild;
	
	root->lchild = tmp->rchild;
	
	tmp->rchild = root;

	root->height = get_tree_height(root);
	tmp->height = get_tree_height(tmp);

	return tmp;
}

//左旋转，为了解决右右不平衡
node_t *tree_left_rotate(node_t *root)
{
	node_t *tmp;
	
	tmp = root->rchild;
	
	root->rchild = tmp->lchild;
	
	tmp->lchild = root;

	root->height = get_tree_height(root);
	tmp->height = get_tree_height(tmp);

	return tmp;
}

//先左后右旋转，为了解决左右不平衡
node_t *tree_left_right_rotate(node_t *root)
{
	root->lchild = tree_left_rotate(root->lchild);

	return tree_right_rotate(root);
}

//先右后左旋转，为了解决右左不平衡
node_t *tree_right_left_rotate(node_t *root)
{
	root->rchild = tree_right_rotate(root->rchild);

	return tree_left_rotate(root);
}




//将节点插入到树中
node_t *insert_node_to_tree(node_t *root, node_t *node)
{
	if(root == NULL)//如果这是一颗空树，那这个node新节点就是树头啦
		return node;
		
	if(node->data > root->data)
	{
		//插入到你的右树
		root->rchild = insert_node_to_tree(root->rchild, node);
	}
	else
	{
		//插入到你的左树
		root->lchild = insert_node_to_tree(root->lchild, node);
	}
	
	if(get_tree_height(root->lchild) - get_tree_height(root->rchild) == 2)//左不平衡
	{
		if(root->lchild->lchild != NULL)//左左不平衡
		{
			root = tree_right_rotate(root);//右转
		}
		else//左右不平衡
		{
			root = tree_left_right_rotate(root);//先左后右转
		}
	}
	else if(get_tree_height(root->rchild) - get_tree_height(root->lchild) == 2)//右不平衡
	{
		if(root->rchild->rchild != NULL)//右右不平衡
		{
			root = tree_left_rotate(root);//左转
		}
		else//右左不平衡
		{
			root = tree_right_left_rotate(root);//先右后左转
		}
	}
	
	root->height = get_tree_height(root);
	
	return root;
}


//遍历树
void display_tree_node(node_t *root)
{
	if(root == NULL)
		return;

	display_tree_node(root->lchild);
	
	printf("%d:高度为%d\n", root->data, root->height);
	
	display_tree_node(root->rchild);
}

//删除一个指定的节点
node_t *remove_tree_node(node_t *root, int data)
{
	node_t *pos;

	if(root == NULL)
		return NULL;

	if(root->data == data)
	{
		if(root->lchild == NULL && root->rchild == NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->lchild != NULL)//要删除的节点左树不为NULL
		{
			//找到这个左树当中的最右边的节点
			for(pos=root->lchild; pos->rchild != NULL; pos=pos->rchild);
			
			//将最右边的节点的数据覆盖到我们这个节点里面
			root->data = pos->data;
			
			//进入到左子树当中将里面的最右边的节点删除掉
			root->lchild = remove_tree_node(root->lchild, pos->data);
		}
		else//要出的节点的右树不为NULL
		{
			//找到这个右树当中的最左边的节点
			for(pos=root->rchild; pos->lchild != NULL; pos=pos->lchild);
			
			//将最左边的节点的数据覆盖到我们这个节点里面
			root->data = pos->data;
			
			//进入到右子树当中将里面的最左边的节点删除掉
			root->rchild = remove_tree_node(root->rchild, pos->data);
		}
	
	}
	else if(data < root->data)//往左树里面去寻找节点删除
	{
		root->lchild = remove_tree_node(root->lchild, data);
	
	}
	else//往右树里面去删除
	{
		root->rchild = remove_tree_node(root->rchild, data);
	}

	if(get_tree_height(root->lchild) - get_tree_height(root->rchild) == 2)//左不平衡
	{
		if(root->lchild->lchild != NULL)//左左不平衡
		{
			root = tree_right_rotate(root);//右转
		}
		else//左右不平衡
		{
			root = tree_left_right_rotate(root);//先左后右转
		}
	}
	else if(get_tree_height(root->rchild) - get_tree_height(root->lchild) == 2)//右不平衡
	{
		if(root->rchild->rchild != NULL)//右右不平衡
		{
			root = tree_left_rotate(root);//左转
		}
		else//右左不平衡
		{
			root = tree_right_left_rotate(root);//先右后左转
		}
	}
	
	root->height = get_tree_height(root);

	return root;
}

//随堂小练习
//查找指定节点
/*
	函数功能：
		寻找二叉树当中的指定节点
	参数：
		root：传入树的根
		find_data：寻找的节点数据值
	返回值：
		找到返回该节点的地址，找不到则返回NULL
*/
node_t *find_tree_node(node_t *root, int find_data)
{
	if(root == NULL)
		return NULL;
		
	if(root->data == find_data)
	{
		return root;
	}
	else if(find_data > root->data)
	{
		return find_tree_node(root->rchild, find_data);
	}
	else
	{
		return find_tree_node(root->lchild, find_data);
	}
	
	return NULL;
}

//销毁整个树
void destroy_tree(node_t *root)
{
	if(root == NULL)
		return;

	destroy_tree(root->lchild);
		
	destroy_tree(root->rchild);

	printf("free %d\n", root->data);
	
	free(root);	
}

int main(void)
{
	int input_data;
	node_t *root = NULL;
	node_t *new_node, *find_node;
	
	while(1)
	{
		scanf("%d", &input_data);
	
		if(input_data > 0)
		{
			new_node = request_tree_node(input_data);
			//将数据插入到树当中
			
			root = insert_node_to_tree(root, new_node);
		}
		else if(input_data < 0)
		{
			//删除树当中某个指定的节点
			root = remove_tree_node(root, -input_data);
			
			//find_node = find_tree_node(root, -input_data);
			//if(find_node != NULL)
				//printf("找到这个节点啦：%d\n", find_node->data);
			//else
				//printf("这个树里面找不到这个宝贝\n");
		}
		else
			break;
			
		printf("树里面有元素：\n");	
		display_tree_node(root);
		printf("\n");
	
	}

	//销毁掉一整棵树
	destroy_tree(root);

	return 0;
}
