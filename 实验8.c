#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

#define Max 1000
#define N 8          /*权值*/
#define M 2*N-1      /*结点*/

typedef char elemtype;
typedef struct
{
	elemtype data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffnode;

typedef struct
{
	char cd[N];
	int start;
	char ch;
}huffcode;

huffnode ht[M+1];
huffcode hcd[N+1];
char zifu[N]={'\0'};

void creat()/*构造哈夫曼树*/
{
	int x,i,j,p1,p2,min1,min2;
	for(i=1;i<=M;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	printf("输入%d个字符的权值:\n",N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&x);
		ht[i].weight=x;
	}
	printf("输入%d个字符:\n",N);
	scanf("%s",zifu);
	for(i=N+1;i<=M;i++)
	{
		p1=1;p2=1;
		min1=Max;min2=Max;
		for(j=1;j<=i-1;j++)
		{
			if(ht[j].parent==0)
			{
				if(ht[j].weight<min1)
				{
					min2=min1;
					p2=p1;
					min1=ht[j].weight;
					p1=j;
				}
				else if(ht[j].weight<min2)
				{
					min2=ht[j].weight;
					p2=j;
				}
			}
		}
			ht[i].weight=ht[p1].weight+ht[p2].weight;
			ht[i].lchild=p1;
			ht[i].rchild=p2;
			ht[p1].parent=i;
			ht[p2].parent=i;
	}
}

int menu(void)              //菜单函数
{
	int menu;
    system("cls");
	printf("\n\t\t\t********主菜单********\n");
    printf("\n\t\t\t 1.构造哈夫曼树\n");
	printf("\t\t\t 2.求哈夫曼编码\n");
	printf("\t\t\t 3.输出哈夫曼编码\n");
	printf("\t\t\t 0.退出程序\n");
	printf("\n\t\t\t**********************\n");
	do
	{
		printf("\t\t\t请选择:");
		scanf("%d",&menu);
	}while(menu<0||menu>3);
	return(menu);
}

void huffman()
{
	int i,c,p;
	for(i=1;i<=N;i++)
	{
		hcd[i].start=N;
		c=i;
		p=ht[i].parent;
		while(p!=0)
		{
			hcd[i].start--;
			if(ht[p].lchild==c) hcd[i].cd[hcd[i].start]='0';
			else hcd[i].cd[hcd[i].start]='1';
			c=p;
			p=ht[p].parent;
		}
	}
	for(i=1;i<=N;i++)
		hcd[i].ch=zifu[i-1];
}

void print1()
{
	int z;
	for(z=1;z<=M;z++)
		printf("%c,%d,%d,%d,%d\n",ht[z].data,ht[z].weight,ht[z].parent,ht[z].lchild,ht[z].rchild);
	printf("\n\t按任意键继续");
	getch();
}

void print()
{
	int i,j;
	printf("各字符的哈夫曼编码为:\n");
	for(i=1;i<=N;i++)
	{
		printf("%c:",hcd[i].ch);
		for(j=hcd[i].start;j<N;j++)
			printf("%c",hcd[i].cd[j]);
		printf("\n");
	}
	printf("\n\t按任意键继续");
	getch();
}

void main()
{
	int select=0;
	do
		{
			select=menu();
			switch(select)
			{
                case 1:creat();break;
				case 2:huffman();break;
				case 3:print();break;
			}
		}while(select!=0);
}









