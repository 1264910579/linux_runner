#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct student_data  
{
    char name[16];
    short age;
    float height;
}student_data;
typedef student_data DATA;
typedef struct link_list_node
{
    DATA data;
    struct link_list_node *next;
}node;

//新建一个头节点函数
node * Init_list_head(void)
{
    node *p=calloc(1,sizeof(node));
    if(p==NULL)
    {
        perror("申请空间失败");
        return NULL;
    }
    else
    {
        p->next=NULL;
        return p;
    }
}
//新建一个学生信息节点的函数
node *new_node()
{
    node *new =calloc(1,sizeof(node));
    if(new!=NULL)
    {
        bzero(new->data.name,sizeof(new->data.name));
        printf("学生姓名：");
        scanf("%s",new->data.name);
        printf("\n学生年龄：");
        scanf("%d",&new->data.age);
        printf("\n学生身高：");        
        scanf("%f",&new->data.height);
        new->next=NULL;
    }
    return new;
}

    //插入节点在头的后面
void insert_node(node *head,node *new)
{
    new->next=head->next;
    head->next=new;
}



    //寻找指定节点,返回该指定节点的上一节点的指针(按名字寻找)
node *find_node(node *head)
{
    char name[16]={0};
    printf("请输入您想找的学生的名字：");
    scanf("%s",name);
    bool bigan=false;
    int i=0;
    node *k;//p的跟屁虫，为了返回p节点的上一个节点的指针
    node *p;
    for(p=head->next,k=head;p!=NULL;p=p->next,k=k->next)
    {
        if(!(strcmp(p->data.name,name)))
        {
            printf("学生的姓名：%s\t",p->data.name);
            printf("学生的年龄：%d\t",p->data.age);
            printf("学生的身高：%f\t",p->data.height);
            bigan=true;
            return k;
        }
    }
    if(!bigan)
    {
    printf("没有此人\n");
    return NULL;
    }

}    
    //删除指点节点
node *remove_student(node *head)
{
    node *p=find_node(head);
    if (p==NULL)
    return NULL;
    else
    {
    node *k=p->next;
    p->next=p->next->next;
    free(k);
    k=NULL;
    printf("已删除该学生\n");
    }
}
    //遍历链表

    //显示链表
void  display_list(node *head)
{
    for(node *p=head->next;p!=NULL;p=p->next)
    {
        printf("学生的姓名：%s\t",p->data.name);
        printf("学生的年龄：%d\t",p->data.age);
        printf("学生的身高：%f\t",p->data.height);
    }
}
    //销毁链表
void des_list(node *head)
{
    node *p;
    node *k;
   for(p=head,k=p->next;p!=NULL;p=k,k=k->next)
   {
       printf("free %s",p->data.name);
       free(p);
       if(k==NULL)
        break;
   } 

}

int show(void)
{
    printf("请选择一下功能：\n");
    printf("1、新增学生\n");
    printf("2、搜索学生\n");
    printf("3、删除找到的学生数据\n");
    printf("4、显示所有学生信息\n");
    printf("5、销毁链表\n");
    int a;
MM:
    scanf("%d",&a);
    if (a==1||a==2||a==3||a==4||a==5)
    {
        return a;
    }
    else
    {
        printf("请重新输入");
        goto MM;
    }
}

int main(int argc, char const *argv[])
{
    //新建一个头节点
    node *head=Init_list_head();
    while (1)
    {
        switch (show())
        {
        case 1:{ system("clear"); node *new=new_node();insert_node(head,new);break;}
        case 2: system("clear");find_node(head); break;
        case 3: system("clear");remove_student(head);break;
        case 4: system("clear");display_list(head);break;
        case 5: system("clear");des_list(head);break;
        default:break;
        }
    }
    return 0;
}
