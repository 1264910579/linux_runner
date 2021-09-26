
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <list.h>

struct student_info{
	char name[4096];
	short age;
	float height;
};

typedef struct list_node{
    struct student_info data;
    struct list_head list;//导入内核链表小结构体
}node_t;//链表节点类型


node_t *request_link_list_node(void)
{
    node_t *new_node;

    new_node = malloc(sizeof(node_t));
    if(new_node == NULL)
    {
        perror("申请链表节点失败");
        return NULL;
    }

    INIT_LIST_HEAD(&new_node->list);

    return new_node;
}
/*
    函数功能:
        将insert_node这个节点插入到refer_node这个节点之后的位置
    参数:
        refer_node:是链表中的任意一个节点
        insert_node:需要插入的节点
    返回值:
        无
*/
static inline void insert_node_link_list(node_t *refer_node, node_t *insert_node)
{
	node_t *pos;

	list_for_each_entry(pos, &refer_node->list, list)
    {
        if(strcmp(pos->data.name, insert_node->data.name) > 0)//pos里面的字符比insert_node的字符要大
		{
			break;
		}

    }

    list_add_tail(&insert_node->list, &pos->list);
}


void display_link_node_data(node_t *list_head)
{
    node_t *pos;

    printf("链表现有数据:\n");

    //不安全的打个结构体遍历
    list_for_each_entry(pos, &list_head->list, list)
    {
        printf("学生信息:名字=%s, 年龄=%hd, 身高=%.2f\n", pos->data.name, pos->data.age, pos->data.height);
    }

    printf("____________________________\n");
}


/*
    函数功能:
        删除refer_node的下一个节点出链表
    参数:
        refer_node:链表当中的任意一个节点
*/
int remove_list_node(node_t *rm_node)
{
    
    list_del(&rm_node->list);//移除出原本所在的链表

    free(rm_node);//释放内存

    return 0;
}

void destroy_link_list(node_t *list_head)
{
    
    node_t *pos, *n;

    //安全的打个结构体遍历
    list_for_each_entry_safe(pos, n, &list_head->list, list)
    {
        printf("free %s\n", pos->data.name);
        free(pos);
    }

    free(list_head);
}


/*
    函数功能:
        寻找指定find_data这个数据值存放的节点
    参数:
        list_heasd:寻找的链表头节点
        find_data:寻找的数据值为多少
    返回值:
        成功返回找到的节点内存地址,失败返回NULL        
*/
node_t *find_link_node(node_t *list_head, const char *find_name)
{
    node_t *pos;


    list_for_each_entry(pos, &list_head->list, list)
    {
        if(strcmp(pos->data.name, find_name) == 0)
        {
            return pos;
        }
    }

    return NULL;
}

void change_student_info(node_t *node)
{
	if(node == NULL)
		return;
	
	printf("开始注册学生信息:\n");

	printf("请输入学生名字:\n");
	scanf("%s", node->data.name);

	printf("请输入学生年龄:\n");
	scanf("%hd", &node->data.age);

	printf("请输入学生身高:\n");
	scanf("%f", &node->data.height);

}


int register_student_info(node_t *list_head)
{
	node_t *new_node;

	new_node = request_link_list_node();
	if(new_node == NULL)
	{
		perror("申请内存出错");
		return -1;
	}

	change_student_info(new_node);

	insert_node_link_list(list_head, new_node);


	return 0;
}

node_t *find_student_info(node_t *list_head)
{
	char name[16];
	node_t *find_node;

	printf("请输入需要搜索的学生名字\n");

	scanf("%s", name);

	find_node = find_link_node(list_head, name);
	if(find_node != NULL)
	{
		printf("寻找到的学生信息:名字=%s, 年龄=%hd, 身高=%.2f\n", 
			find_node->data.name, find_node->data.age, find_node->data.height);
		
		change_student_info(find_node);
	}
	else
	{
		printf("找不到该学生信息\n");
	}

	

	return find_node;
}

int remove_student_info(node_t *list_head)
{
	char name[16];
	node_t *find_node;

	printf("请输入需要开除的学生名字\n");

	scanf("%s", name);

    find_node = find_link_node(list_head, name);
    if(find_node != NULL)
    {
        remove_list_node(find_node);
    }
    else
    {
        fprintf(stderr, "找不到你需要删除的学生信息\n");
        return -1;
    }

    return 0;
}



int main(void)
{
	int input_cmd;
	node_t *list_head;
	

	list_head = request_link_list_node();
	if(list_head == NULL)
		goto request_list_err;


	while(1)
	{
		printf("欢迎进入学生信息系统:\n");
		printf("输入1:录入学生信息\n");
		printf("输入2:打印学生信息:\n");
		printf("输入3:寻找指定学生信息\n");
		printf("输入4:开除指定学生\n");
		printf("输入5:退出整个系统\n");
		scanf("%d", &input_cmd);

		switch(input_cmd)
		{
			case 1:
					register_student_info(list_head);//录入学生信息
					break;
			case 2:
					display_link_node_data(list_head);//打印学生信息
					break;
			case 3:
					find_student_info(list_head);//寻找学生信息
					break;
			case 4:
					remove_student_info(list_head);//删除指定学生信息
					break;
			case 5:
					goto system_exit;
			default:
					break;

		}

	}


system_exit:
	destroy_link_list(list_head);

	return 0;

request_list_err:
	return -1;

}
