#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告


#define  MAX_NAME 20
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int Listlen;
typedef struct Peoinfo  //信息
{
	char c_name[MAX_NAME];
	int age;
}Peoinfo;

typedef struct Conlist
{
	Peoinfo data;
	struct Conlist* next;//后驱指针
}Conlist,*Linklist;


Linklist InitList(Linklist L);//初始化链表
void AddList(Linklist L);//插入链表成员
void DelList(Linklist L);//删除链表成员
void InsertList(Linklist L);//插入链表成员
void ShowList(Linklist L);//显示链表成员
int SerchList(Linklist L);//查找链表成员
void ModifyList(Linklist L);//修改链表成员
void ClearList(Linklist L);//清空链表成员
void DestroyList(Linklist L);//销毁链表
//Linklist InitList(Linklist L);
//Linklist InitList(Linklist L);
//Linklist InitList(Linklist L);
//
//Linklist InitList(Linklist L); 