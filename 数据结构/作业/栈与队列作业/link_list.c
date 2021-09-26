#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct link_list_node
{
    int data;
    struct link_list_node *next;
}node;

//新建一个节点的函数
node *new_node(int data)
{
    node *new =calloc(1,sizeof(node));
    if(new!=NULL)
    {
        new->data=data;
        new->next=NULL;
    }
    return new;
}

    //由大到小顺序插入
void insert_node(node *head,node *new)
{
    node *k;//定义一个跟屁虫
    node *p;
    for(k=head,p=head->next;p!=NULL;k=p,p=p->next)
    {
        if (p->data>new->data)
        {
            break;
        }
        
    }
    new->next=k->next;
    k->next=new;
}

//把链表1和链表2按数据的顺序合并到链表3
node * merge_list(node *head1, node *head2, node *head3)
{
    node *p,*p1;//p为记录末尾节点，p1是p的跟屁虫
    node *k,*k1;//k为记录末尾节点，k1是k的跟屁虫
    //比较链表1和链表2的末尾节点数据谁大，谁大谁就断开插进新表3
    while (1)
    {
        for(p1=head1,p=head1->next;p->next!=NULL;p1=p1->next,p=p->next);
        for(k1=head2,k=head2->next;k->next!=NULL;k1=k1->next,k=k->next);

        node *new;//记录谁大
        node *j;//记录谁大的前一个节点，用于使末节点指向NULL
        new = p->data > k->data ? p:k;
        j = p->data >= k->data ? p1:k1;

        new->next=head3->next;
        head3->next=new;
        j->next=NULL;
        if(head1->next->next==NULL && head2->next->next==NULL)
        break;
    }

}


    //寻找指定节点,返回该指定节点的上一节点的指针
node *find_node(node *head,int data)
{
    bool bigan=false;
    int i=0;
    node *k;//p的跟屁虫，为了返回p节点的上一个节点的指针
    node *p;
    for(p=head->next,k=head;p!=NULL;p=p->next,k=k->next)
    {
        
        if(p->data==data)
        {
            bigan=true;
            return k;
        }
    }
    if(!bigan)
    {
    printf("没有该数据\n");
    return NULL;
    }

}    
    //删除指点节点
node *remove_node(node *head,int data)
{
    node *p=find_node(head,-data);
    if (p==NULL)
    return NULL;
    else
    {
    node *k=p->next;
    p->next=p->next->next;
    free(k);
    k=NULL;
    }
}

    //显示链表1
void  display_list1(node *head1)
{
    for(node *p=head1->next;p!=NULL;p=p->next)
    {
        printf("%d\t",p->data);
    }
}
    //显示链表2
void  display_list2(node *head2)
{
    for(node *p=head2->next;p!=NULL;p=p->next)
    {
        printf("%d\t",p->data);
    }
}    

    //显示合并后的链表
void  display_list3(node *head3)
{
    for(node *p=head3->next;p!=NULL;p=p->next)
    {
        printf("%d\t",p->data);
    }
    printf("\n");
}
    //销毁所有链表
void des_list(node *head1, node *head2, node *head3)
{
    node *p;
    node *k;
    node *a[3]={head1,head2,head3};
    for(int i=0;i<3;i++)
    {
        for(p=a[i],k=p->next;p!=NULL;p=k,k=k->next)
        {
            printf("free %d",p->data);
            free(p);
            if(k==NULL)
            break;
        }
    } 

}

int show(void)
{
    printf("请选择一下功能：\n");
    printf("1、插入单链表1的数据\n");
    printf("2、插入单链表2的数据\n");
    printf("3、合并两条链表并从小到大显示\n");
    printf("4、销毁所有链表\n");
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
    int data;
    //新建三条单链表
    node *head1=new_node(0);
    node *head2=new_node(0); 
    node *head3=new_node(0);
        while (1)
    {
        switch (show())
        {

        case 1:
        {
            printf("按'-1'退出\n");
            while (1)
            {
                scanf("%d",&data);
                node *new=new_node(data);
                insert_node(head1,new);//按顺序插入
                display_list1(head1);
                if(data==-1)
                break;
            }
            break;
        }

        case 2:
        {
            printf("按'-1'退出\n");
            while (1)
            {             
            scanf("%d",&data);
            node *new=new_node(data);
            insert_node(head2,new);//按顺序插入
            display_list2(head2);
            if(data==-1)
            break;
            }
            break;
        }

        case 3: 
        {
            system("clear");
            merge_list(head1, head2, head3);//两个链表按顺序合并
            display_list3(head3);
            break;
        }
        case 4: 
        {
            system("clear");
            des_list(head1,head2,head3);
            break;
        }

        default:break;
        }
    }
    return 0;
}
