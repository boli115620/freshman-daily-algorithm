#pragma once

#include<stdio.h>
#include<stdlib.h>
//函数声明
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//1.链表的初始化
LinkList InitLinkList(LinkList list)
{
    list = (LinkList)malloc(sizeof(LNode));//为链表分配存储空间
    if (list == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    list->next = NULL;
    return list;
}
//2.链表的插入
LinkList InsertLinkList(LinkList list,int i,int x)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return NULL;
    }
    //判断插入位置是否合法
    if(i<1)
    {
        printf("插入位置不合法！\n");
        return NULL;
    }
    LNode *p = list;//指针p指向链表的头结点
    int j=0;//j为计数器，初始值为0
    while(p!=NULL&&j<i-1)//找到第i个元素的位置
    {
        p=p->next;
        j++;
    }
    if(p==NULL)//判断是否找到第i个元素的位置
    {
        printf("插入位置不合法！\n");
        return NULL;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));//为新节点分配存储空间
    if (s == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    s->data=x;//将x赋值给新节点的data域
    s->next=p->next;//将新节点的next域指向第i个元素的下一个节点
    p->next=s;//将第i个元素的next域指向新节点
    return list;
}
//3.链表的删除
LinkList DeleteLinkList(LinkList list,int i)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return NULL;
    }
    //判断删除位置是否合法
    if(i<1)
    {
        printf("删除位置不合法！\n");
        return NULL;
    }
    LNode *p = list;//指针p指向链表的头结点
    int j=0;//j为计数器，初始值为0
    while(p->next!=NULL&&j<i-1)//找到第i个元素的位置
    {
        p=p->next;
        j++;
    }
    if(p->next==NULL)//判断是否找到第i个元素的位置
    {
        printf("删除位置不合法！\n");
        return NULL;
    }
    LNode *q = p->next;//指针q指向第i个元素
    p->next=q->next;//将第i个元素的前一个节点的next域指向第i个元素的下一个节点
    free(q);//释放第i个元素的存储空间
    return list;
}
//4.链表的按值查找
int LocateLinkElem(LinkList list,int x)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return -1;
    }
    LNode *p = list->next;//指针p指向链表的第一个节点
    int i=1;//i为计数器，初始值为1
    while(p!=NULL)//遍历链表
    {
        if(p->data==x)//判断是否找到值为x的元素
        {
            return i;//返回第i个元素的位置
        }
        p=p->next;
        i++;
    }
    printf("值为%d的元素不存在！\n",x);
    return -1;
}
//5.链表的按位置修改
LinkList SetLinkElemByIndex(LinkList list,int i,int x)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return NULL;
    }
    //判断修改位置是否合法
    if(i<1)
    {
        printf("修改位置不合法！\n");
        return NULL;
    }
    LNode *p = list->next;//指针p指向链表的第一个节点
    int j=1;//j为计数器，初始值为1
    while(p!=NULL&&j<i)//找到第i个元素的位置
    {
        p=p->next;
        j++;
    }
    if(p==NULL)//判断是否找到第i个元素的位置
    {
        printf("修改位置不合法！\n");
        return NULL;
    }
    p->data=x;//修改第i个元素的值为x
    return list;
}
//6.链表的按值修改
LinkList SetLinkElemByValue(LinkList list,int x,int y)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return NULL;
    }
    LNode *p = list->next;//指针p指向链表的第一个节点
    while(p!=NULL)//遍历链表
    {
        if(p->data==x)//判断是否找到值为x的元素
        {
            p->data=y;//修改值为x的元素为y
            return list;
        }
        p=p->next;
    }
    printf("值为%d的元素不存在！\n",x);
    return NULL;
}
//7.链表的销毁
LinkList DestroyLinkList(LinkList list)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return NULL;
    }
    LNode *p = list;//指针p指向链表的头结点
    while(p!=NULL)//遍历链表
    {
        LNode *q = p;//指针q指向当前节点
        p=p->next;//指针p指向下一个节点
        free(q);//释放当前节点的存储空间
    }
    return NULL;
}
//8.链表的按位修改
LinkList SetLinkElemByPosition(LinkList list,int i,int x)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return NULL;
    }
    //判断修改位置是否合法
    if(i<1)
    {
        printf("修改位置不合法！\n");
        return NULL;
    }
    LNode *p = list->next;//指针p指向链表的第一个节点
    int j=1;//j为计数器，初始值为1
    while(p!=NULL&&j<i)//找到第i个元素的位置
    {
        p=p->next;
        j++;
    }
    if(p==NULL)//判断是否找到第i个元素的位置
    {
        printf("修改位置不合法！\n");
        return NULL;
    }
    p->data=x;//修改第i个元素的值为x
    return list;
}
//9.链表的打印
void PrintLinkList(LinkList list)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return;
    }
    LNode *p = list->next;//指针p指向链表的第一个节点
    while(p!=NULL)//遍历链表
    {
        printf("%d ",p->data);//打印当前节点的值
        p=p->next;//指针p指向下一个节点
    }
    printf("\n");
}
//10.链表的销毁
void LinkdestroyLinkList(LinkList list)
{
    //判断链表是否存在
    if(list ==NULL)
    {
        printf("链表不存在！\n");
        return;
    }
    LNode *p = list;//指针p指向链表的头结点
    while(p!=NULL)//遍历链表
    {
        LNode *q = p;//指针q指向当前节点
        p=p->next;//指针p指向下一个节点
        free(q);//释放当前节点的存储空间
    }
}