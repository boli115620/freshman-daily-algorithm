/*
    文件说明：
    作者：Boris
    主函数-调试line.h中的其他函数
*/

#include<stdio.h>
#include"line.h"
#include"link.h"

//常量区

//其他变量

int main(void)
{
    //线性表的初始化
    LineList *mylist = InitLineList(mylist);
    printf("线性表初始化成功=%d \n",!!mylist);
    printf("插入是否成功=%d \n",!!InsertList(mylist,1,10));
    for(int i=2;i<=10;i++)
    {
        InsertList(mylist,i,i*10);
    }
    PrintList(mylist);
    //链表的初始化
    LinkList mylink = InitLinkList(mylink);
    printf("链表初始化成功=%d \n",!!mylink);
    for(int i=1;i<=10;i++)
    {
        InsertLinkList(mylink,i,i*10);
    }
    PrintLinkList(mylink);
    for(int i=1;i<=10;i++)
    {
        SetLinkElemByPosition(mylink,i,i*100);
    }
    PrintLinkList(mylink);
    LinkdestroyLinkList(mylink);
    DestroyList(mylist);
    printf("线性表销毁成功=%d \n",!!mylist);
    printf("链表销毁成功=%d \n",!!mylink);
}