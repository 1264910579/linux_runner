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
typedef struct student_info  
{
    char name[16];
    short age;
    float height;
}info;
info *a[10]={0};//专门用来存结构体指针
int sum=0;

info * Init_list(void)
{
    info *p=calloc(1,sizeof(info));
    if(p==NULL)
    {
        perror("申请空间失败");
        return NULL;
    }
    else
    {
        bzero(p->name,sizeof(p->name));
        p->age=0;
        p->height=0;
        return p;
    }
}
//增加学生信息
void add_student(void)
{
    a[sum]=Init_list();
    //插入数据
    printf("请输入学生的姓名：");
    scanf("%s",a[sum]->name);
    printf("请输入学生的年龄：");
    scanf("%d",&a[sum]->age);
    printf("请输入学生的身高：");
    scanf("%f",&a[sum]->height);
    sum++;

}
//搜索数据，找到就说已找到，对应的数组下标为，没找到就显示不好意思
void find()
{
    printf("请输入您要查找的人名");
    char name[16]={0};
    scanf("%s",name);
    bool bigan=false;
    for(int i=0;i<sum;i++)
    {
        if(!(strcmp(a[i]->name,name)))
        {
            printf("学生的姓名：");
            printf("%s\n",a[i]->name);
            printf("学生的年龄：");
            printf("%d\n",a[i]->age);
            printf("学生的身高：");
            printf("%f\n",a[i]->height);
            bigan=true;
        }
    }
    if(!bigan)
    {
        printf("很抱歉，查无此人");
    }
}    
void display()
{
    for(int i=0;i<sum;i++)
    {
        printf("学生的姓名：");
        printf("%s\n",a[i]->name);
        printf("学生的年龄：");
        printf("%d\n",a[i]->age);
        printf("学生的身高：");
        printf("%f\n",a[i]->height);
    }
}
//删除指定的数据
void Remove()
{
    bool bigan=false;
    printf("请您输入想删除的学生 姓名：\n");
    char name[60]={0};
    scanf("%s",name);
    for(int i=0;i<sum;i++)
    {
        if(!(strcmp(a[i]->name,name)))
        {
            for(int j=i;j<sum-i;j++)
            {
                a[j]=a[j+1];
            }

            printf("已经删除完毕\n");
            bigan=true;
        }
    }
    if(!bigan)
    printf("此人不存在，无法删除！");
    sum--;

}
int show(void)
{
    printf("请选择一下功能：\n");
    printf("1、插入数据\n");
    printf("2、搜索数据\n");
    printf("3、删除指定数据\n");
    printf("4、显示所有数据\n");
    int a;
MM:
    scanf("%d",&a);
    if (a==1||a==2||a==3||a==4)
    {
        return a;
    }
    else
    {
        printf("请重新输入");
        goto MM;
    }
}

int main(int j,char *c[])
{

    while (1)
    {
    switch (show())
    {
    case 1: system("clear"); add_student();break;
    case 2: system("clear");find(); break;
    case 3: system("clear");Remove();break;
    case 4: system("clear");display();break;
    default:break;
    }
    }

	return 0;
}
