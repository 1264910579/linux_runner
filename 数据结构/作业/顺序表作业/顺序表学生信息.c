#include<stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
typedef struct list  
{
    int data[20];
    int sum;
}list;

list * Init_list(void)
{
    list *p=calloc(1,sizeof(list));
    if(p==NULL)
    {
        perror("申请空间失败");
        return NULL;
    }
    else
    {
        bzero(p->data,sizeof(p->data));
        p->sum=0;
        return p;
    }
}

void add_data(list *p,int data,int index)
{

    //插入数据
        if(p->sum>=19)
        {
            printf("您输入的此数据过多，无法再输入，请删除一些再继续输入");
            return ;
        }

        for(int i=0;i<=p->sum-index;i++)
        {
            p->data[p->sum+1-i]=p->data[p->sum-i];
        }
        p->data[index]=data;
        p->sum++;
}

    //搜索数据，找到就说已找到，对应的数组下标为，没找到就显示不好意思
int find(list *p,int data)
{
    bool bigan=false;
    for(int i=1;i<=p->sum+1;i++)
    {
        if(p->data[i-1]>data)
        {
            bigan=true;
            return i-1;
        }
    }
    if(!bigan)
    {
      return p->sum;  
    }
}    
void display(list *p)
{
    for(int i=0;i<p->sum;i++)
    printf("%d\t",p->data[i]);
}
//删除指定的数据
void Remove(list *p,int data)
{

    for(int i=0;i<=p->sum;i++)
    {
        if((-data)==p->data[i])
        {
            for(int j=i;j<p->sum;j++)
            {p->data[j]=p->data[j+1];}
            p->sum--;
        }
    }

}

int main(int j,char *c[])
{
    //初始化一个顺序表
    list *p=Init_list();
    int data;
    while (1)
    {
        scanf("%d",&data);
    if(data>=0)
    {
        int index=find(p,data);

        add_data(p,data,index);
    } 
    else
    {    
        Remove(p,data);
    }
        display(p);
    }
	return 0;
}
