#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "studentManage.h"

// 搞一个空的链表，装学生信息
#define DATATYPE struct student
#include "dlinklist.h"

void showStudentInfo(struct student someone)
{
    printf("姓名: %s\t", someone.name);
    printf("年龄: %d\t", someone.age);
    printf("分数: %f\n", someone.score);
}

bool cmp(struct student a, struct student b)
{
    return strcmp(a.name, b.name) == 0;
}

int main(int argc, char const *argv[])
{
    node *head = initList();

    struct student Jack = {.age = 22, .name="Jack", .score=90.0};
    struct student Rose = {.age = 23, .name="Rose", .score=50.0};
    struct student Bill = {.age = 21, .name="Bill", .score=63.0};

    listAddTail(head, Jack);
    listAddTail(head, Rose);
    listAddTail(head, Bill);

    listForEach(head, showStudentInfo);

    node *p = findNode(head, Rose, cmp);
    listRemove(p);
    free(p);

    listForEach(head, showStudentInfo);

    return 0;
}
