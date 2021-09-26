#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define	SQL_NUMB	10

typedef struct sequance_list{

	int array[SQL_NUMB];//这个是用来放数据的
	int last;//这个是用来记录上面的数组用到第几个元素的
}sql_t;


sql_t *request_sequence_list(void)
{
	sql_t *new_sql;

	new_sql = malloc(sizeof(sql_t));
	if(new_sql == NULL)
	{
		perror("申请内存失败");
		return NULL;
	}

	new_sql->last = -1;

	return new_sql;
}

void destroy_sequence_list(sql_t *list)
{
	free(list);
}

bool is_full(sql_t *list)
{
	return list->last == SQL_NUMB-1;
}

int insert_data_to_sequence_list(sql_t *list, int insert_data)
{
	if(is_full(list))
	{
		printf("不好依稀呀，表郭满咯\n");
		return -1;
	}

	list->last++;//让记录数组引用的最大下标值+1
	
	list->array[list->last] = insert_data;

}

void display_sequence_list_value(sql_t *list)
{
	int i;

	printf("表格已有数据：");
	for(i=0; i<=list->last; i++)
	{
		printf("%d ", list->array[i]);
	}

	printf("\n");
}

bool is_empty(sql_t *list)
{
	return list->last == -1;
}

int remove_sequence_list_data(sql_t *list)
{
	if(is_empty(list))
	{
		printf("不好依稀呀，表郭已经公啦\n");
		return -1;
	}

	list->last--;

	return 0;
}

int main(void)
{
	int input_value;
	sql_t *list;
	

	list = request_sequence_list();
	if(list == NULL)
		goto request_mem_err;


	while(1)
	{
		scanf("%d", &input_value);

		if(input_value > 0)//插入数据到表格
		{
			insert_data_to_sequence_list(list, input_value);
			display_sequence_list_value(list);
		}
		else if(input_value < 0)//删除表格的数据
		{
			remove_sequence_list_data(list);
			display_sequence_list_value(list);
		}
		else
		{
			break;
		}
	}



	destroy_sequence_list(list);

	return 0;


request_mem_err:
	return -1;

}
