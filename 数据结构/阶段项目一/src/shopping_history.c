#include <stdio.h>
#include "list.h"
#include "com_shop_list.h"
//新建一个历史链表结点
node_history *new_history_node()
{
	node_history *new=calloc(1,sizeof(node_history));
	if(new==NULL)
	{
		perror("商品信息节点申请失败");
	}
	else
	{          
		INIT_LIST_HEAD(&new->list_history);
	}
	return new;
}

//把head_history文件数据全部给history链表,并把所有的内容显示出来
void display_history_list(node_history *head_history,char *flis_name)
{   
    //把txt内容全部放到链表
    FILE *fp=fopen(flis_name,"r");
    char *buffer;
    if(fp == NULL)
    {
        perror("打开历史文件失败");
    }
    buffer = malloc(1024);
    if(buffer == NULL)
    {
        perror("申请内存出错");
    }
    while(fgets(buffer, 1024, fp))
    {   
        //获取一行数据
        //buffer有一行数据
        node_history *new=new_history_node();
        strncpy(new->data_history.display_history_info,buffer,99);
        //插入到链表
        list_add_tail(&new->list_history,&head_history->list_history);
    }
    free(buffer);
    fclose(fp);
    if(list_empty(&head_history->list_history))
    {
        printf(RE"暂无历史！\n"N);
        return;
    }
    //显示链表内容
	node_history *pos;
    list_for_each_entry(pos, &head_history->list_history , list_history)
    {
        printf(G"%s\n"N,pos->data_history.display_history_info);
    }
}

//head_history把链表的内容写到txt,同时销毁history链表
void write_history(node_history *head_history,char *flis_name)
{
    //把内容写到txt
    FILE *fp1=fopen(flis_name,"a+");
    node_history *pos,*n;
    time_t t;
    int i=1;
    time(&t);
    fprintf(fp1,"     购买时间:%s",ctime(&t));
    list_for_each_entry(pos, &head_history->list_history ,list_history)
    {
        fprintf(fp1,"序号:%d 商品名字:%s 单价:%f 数量:%d 总金额:%f",i,pos->data_history.shop_name,pos->data_history.price,pos->data_history.count ,pos->data_history.total);
        fputs("\n",fp1);
        i++;
    }
    fclose(fp1);
    //销毁链表
	list_for_each_entry_safe(pos, n, &head_history->list_history, list_history)
	{
		//最后删除购物车里面的节点
		list_del_init(&pos->list_history);
		free(pos);
	}
}
