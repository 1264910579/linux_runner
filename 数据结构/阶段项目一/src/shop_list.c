#include <stdio.h>
#include "list.h"
#include "com_shop_list.h"


//创建一个购物车头结点
node_shop *new_shop_head()
{
	node_shop *new=calloc(1,sizeof(node_shop));
	if(new==NULL)
	{
		perror(RE"商品信息节点申请失败"N);
	}
	else
	{
		bzero(new->data_shop.shop_name,sizeof(new->data_shop.shop_name)); 
		new->data_shop.number=0;            
		INIT_LIST_HEAD(&new->list_shop);
	}
	return new;
}

//新建购物车信息节点的函数(并判断商品里是否有该商品)
node_shop *new_shop(node_commodity *head_commodity)
{
	node_shop *new=calloc(1,sizeof(node_shop));
	if(new==NULL)
	{
		perror("商品信息节点申请失败");
	}
	else
	{
		bzero(new->data_shop.shop_name,sizeof(new->data_shop.shop_name));
        printf(Y"输入加入购物车商品名称："N);
		while (1)
		{
			scanf("%s",new->data_shop.shop_name);
			while (getchar()!='\n');
			node_commodity *pos=find_commodity(head_commodity,new->data_shop.shop_name);
			if(pos!=NULL)
			{
				printf(Y"请输入加入购物车的数量："N);
				while (1)
				{
					scanf("%d",&new->data_shop.number);
					while (getchar()!='\n');
					if(new->data_shop.number>pos->data_commodity.stock)
					{
						printf(RE"余量剩余%d\n",pos->data_commodity.stock);
						printf("您输入的数量超过商品余量，请重新输入购买数量："N);
					}
					else
					break;						
				}
				new->data_shop.sum_price=(new->data_shop.number)*(pos->data_commodity.price);//价格乘数量等于金额             
				INIT_LIST_HEAD(&new->list_shop);
				break;
			}
			else
			{
				printf(RE"商店中没有该商品，请重新输入："N);
			}
		}
	}
	return new;
}

//把购物节点加到购物车链表中
void init_shop_head(node_shop *head_shop,node_commodity *head_commodity)
{
	node_shop *new = new_shop(head_commodity);
	printf(Y"是否确认加入购物车，确认请按【y】 否【n】\n"N);
	while (1)
	{
		char key4=my_getch();
		if(key4=='y')
		{
			list_add(&new->list_shop ,&head_shop->list_shop);
			printf(Y"已成功加入！\n"N);
			return;
		}
		if(key4=='n')
		{
			printf(Y"已取消当前操作！\n"N);
			free(new);
			new=NULL;
			sleep(1);
			return;
		}
		else
			printf(RE"您输入有误，请重新输入："N);
	}
}

//把购物车链表显示出来,表为空则返回假，不为空返回真
bool display_shop_list(node_shop *head)
{
	//如果表为空表，则打印
	if(list_empty(&head->list_shop))
	{
		printf(RE"您的购物车为空！\n"N);
		return false;
	}
	node_shop *pos;
    list_for_each_entry(pos, &head->list_shop , list_shop)
    {
        printf(G"商品名字：%s, 数量：%d, 总金额：%f\n"N, 
        pos->data_shop.shop_name,pos->data_shop.number,pos->data_shop.sum_price);
    }
	return true;
}
//确认购买时,销毁购物车链表(链表头不销毁,同时商品链表的库存和写进历史链表里面)
void destroy_link_list(node_commodity *head_commodity,node_shop * head_shop,node_history *head_history)
{	
	
	node_history *new=new_history_node();
	node_shop *pos, *n;
	list_for_each_entry_safe(pos, n, &head_shop->list_shop, list_shop)
	{
		//把该节点数据放进购买历史链表里面
		node_history *new=new_history_node();
		strcpy(new->data_history.shop_name,pos->data_shop.shop_name);
		new->data_history.count=pos->data_shop.number;
		//在商品链表中更改库存数量
		node_commodity *pos_;
		list_for_each_entry(pos_, &head_commodity->list_commodity , list_commodity)
		{
			if(strcmp(pos_->data_commodity.shop_name,pos->data_shop.shop_name)==0)
			{
				pos_->data_commodity.stock -= pos->data_shop.number;
				printf(Y"还剩余%d\n"N,pos_->data_commodity.stock);
				//将金额赋值给历史链表里的单价
				new->data_history.price=pos_->data_commodity.price;
			} 
		}
		//计算金额，放到总金额里面
		new->data_history.total=(new->data_history.count)*(new->data_history.price);
		//将赋值好的节点加到head的后面
		list_add(&new->list_history,&head_history->list_history);
		//最后删除购物车里面的节点
		list_del_init(&pos->list_shop);
		free(pos);
	}
}           

//修改购物车信息
void change_shop_list(node_commodity *head_commodity,node_shop * head_shop)
{
	char shop_name[40]={0};
	printf(Y"请输入您想修改的商品：\n"N);
	scanf("%s",shop_name);
	while (getchar()!='\n');
	node_commodity *pos_;//用于找到对应的商品，方便后面输入数量防止超出余量
	list_for_each_entry(pos_,&head_commodity->list_commodity,list_commodity)
	{
		if(!strcmp(shop_name,pos_->data_commodity.shop_name))
		break;
	}
	node_shop * pos,* n;//修改购物车链表里的数量
	list_for_each_entry_safe(pos, n, &head_shop->list_shop, list_shop)
	{
		//找到了就更改
		if(!strcmp(shop_name,pos->data_shop.shop_name))
		{
			printf(Y"修改购买数量按'1' , 删除按'2'"N);
			char key;
			scanf("%c",&key);
			while (getchar()!='\n');
			if(key=='1')//改购买数量
			{
				printf(Y"请输入数量："N);
				while (1)
				{
					scanf("%d",&pos->data_shop.number);
					while (getchar()!='\n');
					if(pos->data_shop.number>pos_->data_commodity.stock)
					{
						printf(RE"您输入的数量大于商品库存，请重新输入："N);
					}
					else
					break;
				}
				printf(Y"已修改！\n"N);
				sleep(2);
			}
			if(key=='2')//删除
			{
				list_del_init(&pos->list_shop);
				free(pos);
				pos=NULL;
				printf(Y"已删除！\n"N);
				sleep(2);
			}
			return;
		}
	}
	printf(RE"不好意思，购物车里没有此内容！\n"N);
	printf(Y"返回【任意键】\n"N);
	while (1)
	{
		if(my_getch()!=0)
		return ;
	} 
}


