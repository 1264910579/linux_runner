#include <stdio.h>
#include "list.h"
#include "com_shop_list.h"
//新建商品信息节点的函数
node_commodity *new_commodity()
{
	node_commodity *new=calloc(1,sizeof(node_commodity));
	if(new==NULL)
	{
		perror(RE"商品信息节点申请失败"N);
	}
	else
	{
		INIT_LIST_HEAD(&new->list_commodity);
	}
	return new;
}

//把commodity.txt里面的内容全部放到商品链表当中
void init_commodity(node_commodity *head , char *flic_name)
{
	bool bigan=false;
    FILE *fp=fopen(flic_name,"r");
	char *buffer, *pos;
    node_commodity *new_commodity_node;
    void *ret_point;//通配型指针类型
    if(fp == NULL)
    {
        perror(RE"打开订单文件失败"N);
    }
    buffer = malloc(1024);
    if(buffer == NULL)
    {
        perror(RE"申请内存出错"N);
    }

    while(1)
    {   
		bzero(buffer,1024);
        ret_point = fgets(buffer, 1024, fp);//获取一行数据

        if(ret_point == NULL)
            break;
        //buffer有一行数据
        new_commodity_node =new_commodity();        
        pos = strstr(buffer, "商品名字:");//搜索到指定字符串,并且返回该字符串的地址
        sscanf(pos+strlen("商品名字:"), "%s", new_commodity_node->data_commodity.shop_name);
        pos = strstr(buffer, "价格:");//搜索到指定字符串,并且返回该字符串的地址
        sscanf(pos+strlen("价格:"), "%f", &new_commodity_node->data_commodity.price);
        pos = strstr(buffer, "剩余:");//搜索到指定字符串,并且返回该字符串的地址
        sscanf(pos+strlen("剩余:"), "%d", &(new_commodity_node->data_commodity.stock));
        //按照价格大小顺序插入到链表
		node_commodity *pos,*n;
		if (list_empty(&head->list_commodity))//空表插在头后面
		{
			list_add(&new_commodity_node->list_commodity,&head->list_commodity);  
		}
		else
		{
			list_for_each_entry_safe(pos, n, &head->list_commodity, list_commodity)
			{
				if(pos->data_commodity.price<new_commodity_node->data_commodity.price)//找到小的插到后面
				{
					list_add(&new_commodity_node->list_commodity ,&pos->list_commodity);
					bigan=true; 
					break;
				}			
			}
			if(!bigan)//没找到就插到头后面
			{
				list_add(&new_commodity_node->list_commodity,&head->list_commodity); 
				break;
			}
		}
    }
    free(buffer);
    fclose(fp);
}

//把商品链表显示出来
void display_commodity_list(node_commodity *head)
{
	node_commodity *pos;
    list_for_each_entry(pos, &head->list_commodity , list_commodity)
    {
        printf(G"商品名字：%s, 价格：%f, 剩余：%d\n"N, 
        pos->data_commodity.shop_name, pos->data_commodity.price ,pos->data_commodity.stock);
    }
}

//查看商品是否存在,存在返回真
node_commodity * find_commodity(node_commodity *head,char *shop_name)
{
    node_commodity *pos;
    list_for_each_entry(pos, &head->list_commodity , list_commodity)
    {
        
        if(strcmp(shop_name,pos->data_commodity.shop_name)==0)
        {
            return pos;
        }
    }
    return NULL;
}

//更改commodity.txt数据
void write_commodity_txt(node_commodity *head_commodity,char *flic_name)
{
    FILE *fp=fopen(flic_name,"w");
	node_commodity *pos;
    list_for_each_entry(pos, &head_commodity->list_commodity , list_commodity)
    {
        fprintf(fp,"%s%s %s%f %s%d","商品名字:",pos->data_commodity.shop_name,"价格:",pos->data_commodity.price ,"剩余:", pos->data_commodity.stock);
        fputs("\n",fp);
    }
    fclose(fp);
}
//管理员录入商品,先更新链表，再写进txt
void write_txt(node_commodity *head_commodity,char *flic_name)
{
    char shop_name[40]={0};
    float price;
    int stock;
	printf(Y"请输入商品的名字："N);
	scanf("%s",shop_name);
	while (getchar()!='\n');
	//判断商品是否已经有
	node_commodity *pos,*n;
    list_for_each_entry(pos, &head_commodity->list_commodity , list_commodity)
    {
		if(!strcmp(shop_name,pos->data_commodity.shop_name))
		{
			printf(RE"该商品已有，试试添加其他商品吧！"N);
			return;
		}
    }
	printf(Y"请输入该商品的价格："N);
	scanf("%f",&price);
	while (getchar()!='\n');
	printf(Y"请输入该商品的库存："N);
	scanf("%d",&stock);
	while (getchar()!='\n');
	//按照价格大小顺序插入到链表
	// node_commodity *pos,*n;
	node_commodity *new_commodity_node=new_commodity();
	strcpy(new_commodity_node->data_commodity.shop_name,shop_name);
	new_commodity_node->data_commodity.price=price;
	new_commodity_node->data_commodity.stock=stock;
	list_for_each_entry_safe(pos, n, &head_commodity->list_commodity, list_commodity)
	{
		if(pos->data_commodity.price<new_commodity_node->data_commodity.price)
		{
			__list_add(&new_commodity_node->list_commodity ,pos->list_commodity.prev,&pos->list_commodity);    
			break;
		}
	}
	//把最后的链表更新到txt中
	write_commodity_txt(head_commodity,flic_name);
	printf(Y"录入商品完成！\n"N);
	sleep(2);
}
//管理员搜索已有商品,并且更改信息
void change_commodity(node_commodity *head_commodity,char *flic_name)
{
	bool bigan=false;
    char shop_name[40]={0};
    float price;
    int stock;
	printf(Y"请输入商品的名字："N);
	scanf("%s",shop_name);
	while (getchar()!='\n');
	//判断商品是否已经有
	node_commodity *pos ,*n;
    list_for_each_entry_safe(pos, n,&head_commodity->list_commodity , list_commodity)
    {
		if(!strcmp(shop_name,pos->data_commodity.shop_name))
		{
			//先把原有的删掉
			list_del_init(&pos->list_commodity);
			free(pos);
			bigan=true;
		}
	}
	if(!bigan)
	{
		printf(RE"对不起，暂无此商品！\n"N);
		return;
	}
	//重新建一个新节点
	node_commodity *new_commodity_node=new_commodity();
	printf(Y"请输入该商品的价格："N);
	scanf("%f",&price);
	while (getchar()!='\n');
	printf(Y"请输入该商品的库存："N);
	scanf("%d",&stock);
	while (getchar()!='\n');
	//按照价格大小顺序插入到链表
 	node_commodity *pos_,*n_;
	strcpy(new_commodity_node->data_commodity.shop_name,shop_name);
	new_commodity_node->data_commodity.price=price;
	new_commodity_node->data_commodity.stock=stock;
	list_for_each_entry_safe(pos_, n_, &head_commodity->list_commodity, list_commodity)
	{
		if(pos_->data_commodity.price<new_commodity_node->data_commodity.price)
		{
			__list_add(&new_commodity_node->list_commodity ,pos_->list_commodity.prev,&pos_->list_commodity);    
			break;
		}
	}
	display_commodity_list(head_commodity);
	//把最后的链表更新到txt中
	write_commodity_txt(head_commodity,flic_name);
	printf(Y"商品信息更改完成！\n"N);
	sleep(2);
	return;
}
