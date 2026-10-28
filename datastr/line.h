#pragma once
/*
    文件说明：是数据结构的代码文档
    作者：Boris
*/
#include<stdio.h>
#include<stdlib.h>

//常量区 - 结构体 - 头文件
//#define MAXSIZE 100 //线性表的最大长度
const int MAXSIZE = 100; //线性表的最大长度
//全局变量

//函数定义和声明
/*
1.线性表：      -规定数据类型是int（ElemType）
    初始化、销毁、清空、判空、求长度、插入、删除、按位查找、按值查找、按位修改、按值修改
    增：向线性表中第i（1<=i<=maxsize）插入x
    删：删除线性表中第i（1<=i<=maxsize）个元素
    删：删除线性表中值为x的元素
    查：查找值为x的元素在表中的位置
    查：查找第i（1<=i<=maxsize）个元素的值
    改：修改第i（1<=i<=maxsize）个元素的值为x
    改：修改值为x的元素为y
*/
//需要一个维护的结构体
typedef struct
 {//线性表的结构体
    int num; //线性表中元素的个数
    int *arr; //线性表的存储空间
} LineList;
//1.线性表的初始化
LineList* InitLineList(LineList *list)
{
    list = (LineList*)malloc(sizeof(LineList));//为线性表分配存储空间
    if (list == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    list->num = 0;
    list->arr = (int*)malloc(MAXSIZE * sizeof(int));//为线性表元素分配存储空间
    if (list->arr == NULL) {
        printf("内存分配失败！\n");
        free(list);
        return NULL;
    }
    return list;
}
//2.线性表的插入
//找到第i个元素的位置，将其后面的元素向后移动一位，然后将x插入到第i个位置
LineList *InsertList(LineList *list,int i,int x)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return NULL;
    }
    //判断插入位置是否合法
    if(i<1||i>list->num+1)
    {
        printf("插入位置不合法！\n");
        return NULL;
    }
    //判断线性表是否已满
    if(list->num>=MAXSIZE)
    {
        printf("线性表已满，无法插入！\n");
        return NULL;
    }
    //找到第i个元素的位置，将其后面的元素向后移动一位
    for(int j=list->num;j>=i;j--)
    {
        list->arr[j]=list->arr[j-1];
    }
    //将x插入到第i个位置
    list->arr[i-1]=x;
    list->num++;//线性表元素个数加1
    return list;
}
//3.线性表的删除
//删除线性表中第i（1<=i<=maxsize）个元素
LineList *DeleteList(LineList *list,int i)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return NULL;
    }
    //判断删除位置是否合法
    if(i<1||i>list->num)
    {
        printf("删除位置不合法！\n");
        return NULL;
    }
    //找到第i个元素的位置，将其后面的元素向前移动一位
    for(int j=i;j<list->num;j++)
    {
        list->arr[j-1]=list->arr[j];
    }
    list->num--;//线性表元素个数减1
    return list;
}
//3.2 删除线性表中值为x的元素
LineList *DeleteListByValue(LineList *list,int x)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return NULL;
    }
    //查找值为x的元素在表中的位置
    int i=0;
    for(i=0;i<list->num;i++)
    {
        if(list->arr[i]==x)
        {
            break;
        }
    }
    //判断是否找到值为x的元素
    if(i==list->num)
    {
        printf("值为%d的元素不存在！\n",x);
        return NULL;
    }
    //找到第i个元素的位置，将其后面的元素向前移动一位
    for(int j=i+1;j<list->num;j++)
    {
        list->arr[j-1]=list->arr[j];
    }
    list->num--;//线性表元素个数减1
    return list;
}
//4.线性表的按值查找
//查找值为x的元素在表中的位置
int LocateElem(LineList *list,int x)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return -1;
    }
    //查找值为x的元素在表中的位置
    for(int i=0;i<list->num;i++)
    {
        if(list->arr[i]==x)
        {
            return i+1;//返回第i个元素的位置
        }
    }
    printf("值为%d的元素不存在！\n",x);
    return -1;
}
//5.线性表的按位查找
//查找第i（1<=i<=maxsize）个元素的值
int GetElem(LineList *list,int i)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return -1;
    }
    //判断查找位置是否合法
    if(i<1||i>list->num)
    {
        printf("查找位置不合法！\n");
        return -1;
    }
    return list->arr[i-1];//返回第i个元素的值
}
//6.线性表的按位修改
//修改第i（1<=i<=maxsize）个元素的值为x
LineList *SetElem(LineList *list,int i,int x)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return NULL;
    }
    //判断修改位置是否合法
    if(i<1||i>list->num)
    {
        printf("修改位置不合法！\n");
        return NULL;
    }
    list->arr[i-1]=x;//修改第i个元素的值为x
    return list;
}
//7.线性表的按值修改
//修改值为x的元素为y
LineList *SetElemByValue(LineList *list,int x,int y)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return NULL;
    }
    //查找值为x的元素在表中的位置
    int i=0;
    for(i=0;i<list->num;i++)
    {
        if(list->arr[i]==x)
        {
            break;
        }
    }
    //判断是否找到值为x的元素
    if(i==list->num)
    {
        printf("值为%d的元素不存在！\n",x);
        return NULL;
    }
    list->arr[i]=y;//修改值为x的元素为y
    return list;
}
//8.线性表的销毁
void DestroyList(LineList *list)
{
    //判断线性表是否存在
    if(list ==NULL)
    {
        printf("线性表不存在！\n");
        return;
    }
    free(list->arr);//释放线性表元素的存储空间
    free(list);//释放线性表的存储空间
    list=NULL;//将指针置为空
}