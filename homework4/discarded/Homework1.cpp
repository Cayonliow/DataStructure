#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef enum{matrix,header,entry}tagfield;

typedef struct matrixnode *matrixpointer;

struct entrynode
{
	int row;
	int col;
	int value;
};

struct matrixnode
{
	tagfield tag;
	
	union
	{
		matrixpointer next;
		entrynode entry;
	}u;

	matrixpointer right;
	matrixpointer down;
};

matrixpointer NewNode(tagfield Tag)
{
	matrixnode p=(matrixnode)malloc(sizeof(p));
	//MALLOC(p,sizeof(matrixnode));
/*
	if(p==NULL)
	{
		printf("fail creating new node\n");
		return p;
	}

	if(Tag==header)
	{
		p->u.next=NULL;
	}
	p->tag=Tag;
	p->right=NULL;
	p->down=NULL;*/
}

/*void mwrite(node* firstnode)
{
		node* temp;
		node* head=firstnode->right;
		
		for(int i=0;i<firstnode->prop.element.row;++i)
		{
			for(temp=head->right;temp!=head;temp=temp->right)
				printf("%5d %5d %5d\n",temp->prop.element.row,temp->prop.element.col,temp->prop.element.value);
			
			head=head->prop.next;
		}
} */

int main()
{
	int m1,n1;
	int m2,n2;

	int count_SM1=0;
	int count_SM2=0;

	scanf("%d",&m1);
	scanf("%d",&n1);
	
	if(m1==0||n1==0)
	{
		printf("the size of the matrix is not valid\n");
		return 0;
	}
	/*
	matrixpointer firstnode=NewNode(matrix);
	firstnode->prop.element.row=n1;
	firstnode->prop.element.col=m1;

	int max1=m1>n1?m1:n1;
	matrixpointer header1[max1];

	for(int i=0;i<max1;++i)
	{
		header1[i]=NewNode(header);
	}
		
	int currentrow=0;
	matrixpointer last1=header1[0];
	matrixpointer point=NewNode(entry);
	for(int i=0;i<m1;++i)
	{
		for(int j=0;j<n1;++j)
		{
			
			int temp1;

			scanf("%d",&temp1);
			printf("i=%d,j=%d\n",i,j);
			if(temp1!=0)
			{
				count_SM1++;

				if(i>currentrow)
				{				
						//printf("i=%d currentrow=%d",i,currentrow);
						last1->right=header1[currentrow];
						currentrow=i;
						last1=header1[currentrow];
				}

				point->prop.element.row=i;
				point->prop.element.col=j;
				point->prop.element.value=temp1;

				last1->right=point;
				last1=point;
			
			//	header1[j]->prop.next->down=point;
			//	header1[j]->prop.next=point;
			
			}
                            
		}*/
/* 
		last1->right=header1[currentrow];
		
		for(int i=0;i<m1;++i)
		{
			header1[i]->prop.next->down=header1[i];
		}

		for(int i=0;i<count_SM1-1;++i)
		{
			header1[i]->prop.next=header1[i+1];
		}

		header1[count_SM1-1]->prop.next=firstnode;
		firstnode->right=header1[0];
 
	}*/
/*	
	mwrite(firstnode);

	scanf("%lld",&m2);
	scanf("%lld",&n2);

	if(n1!=m2)
	{
		printf("The %lld*%lld matrix and the %lld*%lld matrix are not able to be multiplied.\n ",m1,n1,m2,n2);
		return 0;
	}
*/



}
