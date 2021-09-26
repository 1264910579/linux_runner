#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define	SQL_NUMB	10

struct student_info{
	char name[4096];
	short age;
	float height;
};

typedef struct sequance_list{

	struct student_info array[SQL_NUMB];//这个是用来放数据的
	int last;//这个是用来记录上面的数组用到第几个元素
}sql_t;

/*
	函数功能:
		申请一个顺序表的内存
	参数:无
	返回值:
		成功返回申请的内存,失败返回NULL
*/
sql_t *request_sequence_list(void)
{
	sql_t *new_sql;

	new_sql = malloc(sizeof(sql_t));//申请顺序表的结构体内存
	if(new_sql == NULL)//如果返回值为NULL,这代表申请失败
	{
		perror("申请内存失败");
		return NULL;
	}

	new_sql->last = -1;//登记一下这个顺序表现在还没引用里面的内存(-1)

	return new_sql;//返回申请的内存
}

/*
	函数功能:
		释放顺序表的内存
	参数:顺序表的内存地址
	返回值:无
*/
void destroy_sequence_list(sql_t *list)
{
	free(list);
}

/*
	函数功能:
		判断顺序表是否满了
*/
bool is_full(sql_t *list)
{
	return list->last == SQL_NUMB-1;//判断依据是看看引用的下标是否到最大值
}

/*
	函数功能:
		把一个数据insert_data插入到表格中的最后位置
	参数:
		list:顺序表的内存地址
		insert_data:需要插入的数据
	返回值:
		成功返回0,失败返回-1
*/
int insert_data_to_sequence_list(sql_t *list, const struct student_info *insert_data)
{
	if(is_full(list))
	{
		printf("不好依稀呀，表郭满咯\n");
		return -1;
	}

	list->array[list->last+1] = *insert_data;//将数据插入到最后的位置中
	list->last++;//将顺序表的引用下标+1
	
	return 0;
}

/*
	函数功能:
		打印顺序表当中的所有数据
	参数:
		list:顺序表的内存地址
	返回值:
		无
*/
void display_sequence_list_value(const sql_t *list)
{
	int i;

	printf("表格已有数据：\n");
	for(i=0; i<=list->last; i++)//在list->last范围内循环的遍历(list->last代表这个表格已经存到了数组的第几个下标)
	{
		printf("学生信息:名字=%s, 年龄=%hd, 身高=%.2f\n", list->array[i].name, list->array[i].age, list->array[i].height);
	}

	printf("___________________________\n");
}

/*
	函数功能:
		判断表格是否已经空了
	参数:
		list:顺序表的内存地址
	参数:
		返回真或假
*/
bool is_empty(sql_t *list)
{
	return list->last == -1;//表格空的话last的值就为-1
}

/*
	函数功能:
		寻找顺序表当中指定的数据,并且返回寻找到的数据的数组下标
	参数:
		list:顺序表
		find_value:你要寻找的数据值为多少
	返回值:
		成功返回寻找到的数据的数组下标,失败返回-1
*/
int find_sequence_list_data(sql_t *list, const char *find_name)
{
	int i;

	for(i=0; i<=list->last; i++)
	{
		if(strcmp(list->array[i].name, find_name) == 0)
		{
			return i;
		}
	}

	return -1;
}

/*
	函数功能:
		删除表格中rm_value这个数据
	参数:
		list:顺序表的内存地址
		rm_value:要删除的数据
	返回值:
		成功返回0,失败返回-1
*/
int remove_sequence_list_data(sql_t *list, const char  *rm_name)
{
	if(is_empty(list))//判断表格是否为空
	{
		printf("不好依稀呀，表郭已经公啦\n");
		return -1;
	}

	int find_lab;

	find_lab = find_sequence_list_data(list, rm_name);//寻找一下表格里面是否有要删除的这个数据
	if(find_lab != -1)//不等于-1这代表找到这个数据了,并且find_lab他的值为对应的数组下标
	{
		/*拷贝找到的这个数据后面的内存到前面来覆盖它*/
		memcpy(&list->array[find_lab], &list->array[find_lab+1], sizeof(list->array[0])*(list->last-find_lab));
		list->last--;
	}
	else
	{
		printf("您要删除的数据不在表格当中\n");
	}

	return 0;
}

int register_student_info(sql_t *list)
{
	struct student_info *input_info;

	input_info = malloc(sizeof(struct student_info));
	if(input_info == NULL)
	{
		perror("申请内存出错");
		return -1;
	}

	printf("开始注册学生信息:\n");

	printf("请输入学生名字:\n");
	scanf("%s", input_info->name);

	printf("请输入学生年龄:\n");
	scanf("%hd", &input_info->age);

	printf("请输入学生身高:\n");
	scanf("%f", &input_info->height);

	insert_data_to_sequence_list(list, input_info);

	free(input_info);

	return 0;
}


int main(void)
{
	int input_cmd;
	sql_t *list;
	

	list = request_sequence_list();
	if(list == NULL)
		goto request_mem_err;


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
					register_student_info(list);//录入学生信息
					break;
			case 2:
					display_sequence_list_value(list);//打印学生信息
					break;
			case 3:
					//find_student_info();//寻找学生信息
					break;
			case 4:
					//remove_student_info();//删除指定学生信息
					break;
			case 5:
					goto system_exit;
			default:
					break;

		}

	}


system_exit:
	destroy_sequence_list(list);

	return 0;

request_mem_err:
	return -1;

}
