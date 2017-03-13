#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{matrix,header,entry}tagfield;

typedef struct matrixnode* matrixpointer;

typedef struct entrynode 
{
	int row;
	int col;
	int value;
}e;

typedef struct matrixnode
{
	matrixpointer down;
	matrixpointer right;
	tagfield tag;
	
	union
	{
		matrixpointer next;
		e entry;
	}u;	
};

matrixpointer NewNode(tagfield Tag)
{
	//matrixpointer p=(matrixpointer*)malloc(sizeof(p));
	//matrixpointer p=(matrixpointer*)malloc(sizeof(matrixpointer));
	matrixpointer p=malloc(sizeof(struct matrixnode));
	
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
	

	scanf("%d",&m1);
	scanf("%d",&n1);
	
	if(m1==0||n1==0)
	{
		printf("the size of the matrix is not valid\n");
		return 0;
	}
	
	matrixpointer firstnode1=NewNode(header);
	firstnode1->u.entry.row=m1;
	firstnode1->u.entry.col=n1;
	firstnode1->u.entry.value=0;

	int max1=m1>n1?m1:n1;
	matrixpointer *header1=(matrixpointer* )malloc(sizeof(matrixpointer)*max1);
	
	matrixpointer tp1;
	for(i=0;i<max1;++i)
	{
		tp1=NewNode(header);
		header1[i]=tp1;
		header1[i]->tag=header;
		header1[i]->right=tp1;
		header1[i]->u.next=tp1;
	}
		
	int currentrow1=0;
	matrixpointer last1=header1[0];
	
	for(i=0;i<m1;++i)
	{
		for(j=0;j<n1;++j)
		{		
			int temp1;
			scanf("%d",&temp1);
			if(temp1!=0)
			{
				matrixpointer point1=NewNode(entry);
				firstnode1->u.entry.value++;

				if(i>currentrow1)
				{				
						last1->right=header1[currentrow1];
						currentrow1=i;
						last1=header1[i];
				}
				
				point1->u.entry.row=j;
				point1->u.entry.col=i;
				point1->u.entry.value=temp1;

				last1->right=point1;
				last1=point1;
									
				header1[j]->u.next->down=point1;
				header1[j]->u.next=point1;
			}                  
		}
	}
  
  	last1->right=header1[currentrow1];
		
	for(i=0;i<n1;++i)
	{
		header1[i]->u.next->down=header1[i];
	}

	for(i=0;i<max1-1;++i)
	{
		header1[i]->u.next=header1[i+1];
	}
	
	header1[max1-1]->u.next=firstnode1;
	firstnode1->right=header1[0];
//print out the result for checking

	matrixpointer tt1;
	matrixpointer head1=firstnode1->right;
	
	for(i=0;i<firstnode1->u.entry.col;i++)
	{
		int ii=0;
		int jj=0;
		for(tt1=head1->down;tt1!=head1;tt1=tt1->down)
		{
			while(tt1->u.entry.col!=jj)
			{
				
				printf("0 ");
				jj++;
			}
			
			printf("%d ",tt1->u.entry.value);
			jj++;
		}
		
		while(jj!=firstnode1->u.entry.row)
		{
			printf("0 ");jj++;
		}
		printf("\n");
		head1=head1->u.next;
	}
	
}
