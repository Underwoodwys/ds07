#include<stdio.h>
#include<stdlib.h>

typedef struct BINODE{
	int data;
	struct BINODE *left,*right;
}BINODE,*BITREE;

void INSERT(BITREE &T,int k){
	BITREE s;
	if(!T){
		s=(BITREE)malloc(sizeof(BINODE));
		s->data=k;
		s->left=NULL;
		s->right=NULL;
		T=s;
	}
	else if(k<T->data)INSERT(T->left,k);
	else if(k>T->data)INSERT(T->right,k);
	else printf("重复元素。\n");
}

BITREE SEARCH(BITREE T,int k){
	if(!T)return NULL;
	else if(T->data==k)return T;
	else if(T->data>k)SEARCH(T->left,k);
	else SEARCH(T->right,k);
}

BITREE search(BITREE T,int k){
	BITREE p;
	if(!T)return NULL;
	p=T;
	while(p){
		if(p->data==k)return p;
		else if(p->data>k)p=p->left;
		else p=p->right;
	}
}

void CREAT(BITREE &T){
	int a;
	while(scanf("%d",&a)!=EOF){
		INSERT(T,a);
	}
}


int main(void){
	BITREE T;
	T=NULL;
//建立二叉排序树
//查找的递归与非递归

	


int data;
	printf("请输入待排序数列.\n");
	CREAT(T);
	printf("请输入待查找元素.\n");
	scanf("%d",&data);
	INSERT(T,data);
	if(search(T,data))
		printf("%d",search(T,data)->data);
	else printf("不存在此元素.\n");
	
	
	
	return 0;
}
