#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
typedef struct link_list_node
{
    char *a;
    struct link_list_node *next;
}node;
int j=0;//记录txt里面有多少行
//新建一个节点的函数
node *new_node(char *a)
{
    node *new =calloc(1,sizeof(node));
    if(new!=NULL)
    {
        new->a=a;
        new->next=NULL;
    }
    return new;
}
    //入队（即尾插法）
void insert_node(node *head,node *new)
{
    node *p;
    for(p=head;p->next!=NULL;p=p->next);
    new->next=p->next;
    p->next=new;
}

    //出队(头出)返回出队的指针
node *out_node(node *head1)
{
    node *p;
    p=head1->next;
    head1->next=head1->next->next;
    return p;
    
}

    //显示链表1
void  display_list1(node *head)
{
    for(int i=0;i<j;i++)
    {
        node *p;
        p=out_node(head);
        printf("%s\n",p->a);
        sleep(2);
    }
}

//     //销毁所有链表
// void des_list(node *head1)
// {
//     node *p;
//     node *k;
//     for(p=head1,k=p->next;p!=NULL;p=k,k=k->next)
//     {
//         printf("free %s",p->a);
//         free(p);
//         if(k==NULL)
//         break;
//     }
     

// }

int main(int argc, char const *argv[])
{   
    //新建yi条单链表
    node *head1=new_node(NULL);
    FILE *fp=fopen(argv[1],"r");
    char a[12][40]={0};
int i=0;
while (1)
{
        
        char *p=fgets(a[i],40,fp);
        node *new=new_node(a[i]);
        insert_node(head1,new);//按顺序插入
        i++;
        j++;
        if(p==NULL)
        break;
}    
    display_list1(head1);
    fclose(fp);
    return 0;
}
