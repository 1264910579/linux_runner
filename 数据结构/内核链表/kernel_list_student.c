#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
typedef struct student_data  
{
    char name[16];
    int score;
    short age;
    float height;
}student_data;

typedef student_data DATA;

typedef struct big_node
{
    DATA data;
    struct list_head list;
}node;
//新建一个管理节点的函数
node *add_new_head()
{
    node *new =calloc(1,sizeof(node));
    if(new!=NULL)
    {
        INIT_LIST_HEAD(&new->list);
        return new;
    }
    return new;
}
//新建一个学生信息节点的函数
node *add_new_node()
{
    node *new =calloc(1,sizeof(node));
    if(new!=NULL)
    {
        bzero(new->data.name,sizeof(new->data.name));
        printf("学生姓名：");   
        scanf("%s",new->data.name);
        printf("学生分数：");   
        scanf("%d",&new->data.score);        
        printf("学生年龄：");
        scanf("%hd",&new->data.age);
        printf("学生身高：");        
        scanf("%f",&new->data.height);
        INIT_LIST_HEAD(&new->list);
        return new;
    }
    return new;
}

void change_student(node *head)
{
    bool bigan=false;
    //更改指定学生信息
    char a[16]={0};
    printf("请输入想更改的学生：");
    scanf("%s",a);
    node *pos,*n;
    list_for_each_entry_safe(pos, n, &head->list, list)
    {
        if(!strcmp(a,pos->data.name))
        {   
            printf("已找到该学生，请更改信息：\n");
            printf("学生姓名：");   
            scanf("%s",pos->data.name);
            printf("学生分数：");   
            scanf("%d",&pos->data.score);        
            printf("学生年龄：");
            scanf("%hd",&pos->data.age);
            printf("学生身高：");        
            scanf("%f",&pos->data.height);
            printf("\n已修改完毕！");
            bigan=true;
        }
    }
    if(!bigan)
    {
        printf("查无此人\n");
    }
}

void display(node *head)
{
    node *pos;
    list_for_each_entry(pos, &head->list, list)
    {
        printf("寻找到的学生信息:名字=%s, 分数=%d, 年龄=%hd, 身高=%.2f\n", 
        pos->data.name, pos->data.score ,pos->data.age, pos->data.height);
    }
}

int main(int argc, char const *argv[])
{
    int input_cmd;
    //新增一个头节点
    node *head=add_new_head();
    while(1)
    {
        printf("欢迎进入学生信息系统:\n");
        printf("输入1:录入学生信息\n");
        printf("输入2:打印学生信息:\n");
        printf("输入3:寻找指定学生信息\n");
        printf("输入4:开除指定学生\n");
        printf("输入5:更改指定学生信息\n");
        scanf("%d", &input_cmd);

        switch(input_cmd)
        {
            case 1:
            {
                //录入学生信息
                node *new=add_new_node();
                //将学生插入到内核链表中
                node *pos,*n;
                if (list_empty(&head->list))
                {
                    list_add(&new->list,&head->list);  
                }
                else
                {
                    list_for_each_entry_safe(pos, n, &head->list, list)
                    {
                        if(pos->data.score<new->data.score)
                        {
                            __list_add(&new->list,pos->list.prev,&pos->list);    
                            break;
                        }
                    }
                }
                //list_add(&new->list,&head->list);
                break;
            }
            case 2:
            {
                //打印学生信息
                display(head);
                break;
            }
            case 3:
            {
                bool bigan=false;
                //寻找学生信息
                char a[16]={0};
                printf("请输入想查找的学生：");
                scanf("%s",a);
                node *pos,*n;
                list_for_each_entry_safe(pos, n, &head->list, list)
                {
                    if(!strcmp(a,pos->data.name))
                    {
                        printf("寻找到的学生信息:名字=%s, 分数=%d, 年龄=%hd, 身高=%.2f\n", 
                        pos->data.name, pos->data.score, pos->data.age, pos->data.height);
                        bigan=true;
                    }
                }
                if(!bigan)
                {
                    printf("查无此人\n");
                }
                break;
            }
            case 4:
            {   
                bool bigan=false;
                //删除指定学生信息
                char a[16]={0};
                printf("请输入想开除的学生：");
                scanf("%s",a);
                node *pos,*n;
                list_for_each_entry_safe(pos, n, &head->list, list)
                {
                    if(!strcmp(a,pos->data.name))
                    {
                        bigan=true;
                        list_del(&pos->list);
                        printf("已开除\n");
                    }
                }
                if(!bigan)
                {
                    printf("查无此人\n");
                }
                    break;
            }
            case 5:
            {
                //更改指定学生信息
                change_student(head);
                break;
            }
            default:
                    break;
        }
    }
    return 0;
}
