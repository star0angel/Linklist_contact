#include "conlist.h"
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告

Linklist InitList(Linklist L)
{
	Listlen = 0;
	Linklist p = malloc(sizeof(Conlist));
	if (p==NULL)//申请空间失败报错
	{
		perror("错误");
		return NULL;
	}
	L = p;
	L->next = NULL;
	return L;

}

void AddList(Linklist L)
{
	Linklist p = malloc(sizeof(Conlist));
	if (p == NULL)//申请空间失败报错
	{
		perror("错误");
		return ;
	}
	printf("请输入名字：>");
	scanf("%s", p->data.c_name);
	printf("请输入年龄：>");
	scanf("%d", &p->data.age);
	p->next = NULL;
	
	while (L->next)
	{
		L = L->next;
	}
	L->next= p;
	++Listlen;//表长加1
}

void DelList(Linklist L)
{
	int n;
	printf("请输入你想删除第几个元素：>");
	scanf("%d", &n);
	if (n>Listlen||n<1)//判断输入位置是否合法
	{
		perror("位置非法");
		return;
	}
	
	int num = n;
	Linklist p=NULL;
	while (n)//找到要删除的位置 并保留n-1的位置
	{
		n--;
		p = L;
		L = L->next;
	}
	if (num == Listlen)//删除末尾的节点  n-1的位置要置空
	{
		
		free(L);
		L = NULL;
		p->next = NULL;

	}
	else//非尾节点  n-1指向n+1  再释放n区域的内存空间
	{
		p->next = L->next;
		free(L);
		L = NULL;
	}
	--Listlen;
}

void InsertList(Linklist L)
{
	int n;
	printf("请输入你想插入再第几个：>");
	scanf("%d", &n);
	if (n > Listlen+1 || n < 1)//判断输入位置是否合法
	{
		perror("位置非法");
		return;
	}
	Linklist p = malloc(sizeof(Conlist));
	if (p == NULL)//申请空间失败报错
	{
		perror("错误");
		return;
	}
	printf("请输入名字：>");
	scanf("%s", p->data.c_name);
	printf("请输入年龄：>");
	scanf("%d", &p->data.age);
	Linklist tmp=NULL;
	if (n==1)//插在首节点
	{
		tmp = L->next;
		L->next = p;
		p->next = tmp;
	}
	else if (n==Listlen+1)//插在尾节点
	{
		while (L->next)
			L=L->next;
		L->next = p;
		p->next = NULL;
	} 
	else//插在中间节点
	{
		
		while (n)//找到要删除的位置 并保留n-1的位置
		{
			n--;
			tmp = L;
			L = L->next;
		}
		tmp->next = p;
		p->next = L;
	}
	++Listlen;
}

void ShowList(Linklist L)
{
	if (Listlen==0)
	{
		perror("无成员。");
		return;
	}
	//Linklist p;
	printf("%-20s\t%-4s\t\n", "姓名", "年龄");
	for (;L->next;L=L->next)
	{
		//p = L->next;
		printf("%-20s\t%-4d\t\n", L->next->data.c_name, L->next->data.age);
		
	}
}

int SerchList(Linklist L)
{
	if (Listlen == 0)
	{
		perror("无成员。");
		return -1;
	}
	int i = 1;
	char name[MAX_NAME] = { 0 };
	printf("输入你想找到人名字：>");
	scanf("%s", name);
	for (;L->next;L=L->next,i++)
	{
		if (0 == strcmp(name, L->next->data.c_name))
			return i;
	}
	return 0;//表示没有这个元素
}

void ModifyList(Linklist L)
{
	if (Listlen == 0)
	{
		perror("无成员。");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入你想修改人的姓名：>");
	scanf("%s",name);
	for (;L->next;L=L->next)//遍历链表找到成员
	{
		if (strcmp(L->next->data.c_name,name)==0)
		{
			printf("请输入名字：>");
			scanf("%s", L->next->data.c_name);
			printf("请输入年龄：>");
			scanf("%d", &L->next->data.age);
			printf("修改成功。\n");
			return;
		}
	}
	printf("查无此人。\n");//找遍链表未找到
}

void ClearList(Linklist L)
{
	Linklist p = L->next;
	L->next = NULL;
	while (p)
	{
		Linklist q = p;
		p = p->next;
		free(q);
		q = NULL;
	}
	Listlen = 0;
}

void DestroyList(Linklist L)
{
	while (L != NULL)
	{
		Linklist p = L;
		L = L->next;
		free(p);
		p = NULL;
	}
	Listlen = 0;
}
