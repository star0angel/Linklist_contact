#include "conlist.h"

//使用链表简单实现通讯录

void menu()
{
	printf("\n1. 增加成员 2. 删除成员 3. 插入成员\n4. 查找成员 5. 显示成员 6. 修改成员\n 7.清空链表 0. 退出系统");
}

void print(int m)
{
	if (m==0)
	{
		printf("查无此人。");
	} 
	else if (m!=-1)
	{
		printf("此人在第%d个位置。\n",m);
	}
	
}

int main()
{
	Linklist L=NULL;//初始指针指向表头
	 L=  InitList(L);//初始化链表
	 //Listlen = 0;
	 int input;
	 int check;
	 Linklist LL=L;
	 do 
	 {
		 menu();
		 printf("\n     当前链表长度： %d   \n",Listlen);
		 printf("\n\n\n请输入你的选择：>");
		 scanf("%d", &input);
		 switch (input)
		 {
		 case 1://插入链表
			
			 AddList(L);
			 break;
		 case 2://删除链表

			 DelList(L);
			 break;
		 case 3:
			 InsertList(L);
			 break;
		 case 4:
			 check=SerchList(L);
			 print(check);
			 break;
		 case 5:
			 ShowList(L);
			 break;
		 case 6:
			 ModifyList(L);
		 case 7:
			 ClearList(L);
			 break;
		 case 0:
			 DestroyList(L);
			 break;
		 default:
			 printf("选择错误。");
			 break;
		 }

	 } while (input);
	





	//while (L!=NULL)
	//{
	//	Linklist p = L;
	//	L = L->next;
	//	free(p);
	//	p = NULL;
	//}
	return 0;
}