#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{matrix,header,entry}tagfield;

typedef struct matrixnode *matrixpointer;

typedef struct entrynode 
{
	int row;
	int col;
	int value;
}E;

struct matrixnode
{
	matrixpointer down;
	matrixpointer right;
	tagfield tag;
	
	union
	{
		matrixpointer next;
		E entry;
	}u;	
}matrixpointer;

matrixpointer NewNode(tagfield Tag)
{
	matrixpointer p=malloc(sizeof(&p));
	printf("gg");
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
	p->down=NULL;
	
	return p; 
}

int main()
{
	int i,j;
	
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
	
	matrixpointer firstnode=NewNode(header);
/*	firstnode->u.entry.row=n1;
	firstnode->u.entry.col=m1;

	int max1=m1>n1?m1:n1;
	matrixpointer header1[max1];

	for(i=0;i<max1;++i)
	{
		header1[i]=NewNode(header);
	}
		
	int currentrow=0;
	matrixpointer last1=header1[0];
	matrixpointer point=NewNode(entry);

	for(i=0;i<m1;++i)
	{
		for(j=0;j<n1;++j)
		{
			
			int temp1;
			scanf("%d",&temp1);
			if(temp1!=0)
			{
				count_SM1++;

				if(i>currentrow)
				{				
						last1->right=header1[currentrow];
						currentrow=i;
						last1=header1[currentrow];
				}

				point->u.entry.row=i;
				point->u.entry.col=j;
				point->u.entry.value=temp1;

				last1->right=point;
				last1=point;
			
				header1[j]->u.next->down=point;
				header1[j]->u.next=point;
			
			}
                            
		}
		

 
		last1->right=header1[currentrow];
		
		for(i=0;i<m1;++i)
		{
			header1[i]->u.next->down=header1[i];
		}

		for(i=0;i<count_SM1-1;++i)
		{
			header1[i]->u.next=header1[i+1];
		}

		header1[count_SM1-1]->u.next=firstnode;
		firstnode->right=header1[0];
 
	}*/
/*	

	scanf("%lld",&m2);
	scanf("%lld",&n2);

	if(n1!=m2)
	{
		printf("The %lld*%lld matrix and the %lld*%lld matrix are not able to be multiplied.\n ",m1,n1,m2,n2);
		return 0;
	}
*/



}
