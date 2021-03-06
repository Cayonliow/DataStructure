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
	//matrixpointer header1[100000];

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

				
				point1->u.entry.row=i;
				point1->u.entry.col=j;
				point1->u.entry.value=temp1;

				last1->right=point1;
				last1=point1;
							
			
				header1[j]->u.next->down=point1;
				header1[j]->u.next=point1;

				//printf("row=%d,col=%d value=%d\n",point->u.entry.row,point->u.entry.col,point->u.entry.value);
			}
			//printf("i=%d,j=%d temp1=%d\n",i,j,temp1);                    
		}
		
	}

  	printf("tt00=%d",currentrow1);
  
	last1->right=header1[currentrow1];
		
	printf("max=%d n1=%d\n",max1,n1);
		
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

	matrixpointer tt1;
	matrixpointer head1=firstnode1->right;
	printf("row=%d,col=%d, value=%d\n",firstnode1->u.entry.row,firstnode1->u.entry.col,firstnode1->u.entry.value);
	for(i=0;i<firstnode1->u.entry.row;i++)
	{
		for(tt1=head1->right;tt1!=head1;tt1=tt1->right)
		{
			printf("here=%5d %5d %5d\n",tt1->u.entry.row,tt1->u.entry.col,tt1->u.entry.value);
		}
		
		head1=head1->u.next;
	}
	printf("Tony\n");
	printf("ok");
	int m2,n2;
	
	scanf("%d",&m2);
	scanf("%d",&n2);

	if(n1!=m2)
	{
		printf("The %d*%d matrix and the %d*%d matrix are not able to be multiplied.\n ",m1,n1,m2,n2);
		return 0;
	}
	
	if(m2==0||n2==0)
	{
		printf("the size of the matrix is not valid\n");
		return 0;
	}
	
	matrixpointer firstnode2=NewNode(header);
	firstnode2->u.entry.row=m2;
	firstnode2->u.entry.col=n2;
	firstnode2->u.entry.value=0;

	int max2=m2>n2?m2:n2;
//	matrixpointer header2[max2];
	matrixpointer *header2=(matrixpointer*) malloc(sizeof(matrixpointer)*max2);
	
	matrixpointer tp2;
	for(i=0;i<max2;++i)
	{
		tp2=NewNode(header);
		header2[i]=tp2;
		header2[i]->tag=header;
		header2[i]->right=tp2;
		header2[i]->u.next=tp2;
	}
		
	int currentrow2=0;
	matrixpointer last2=header2[0];
	

	for(i=0;i<m2;++i)
	{
		for(j=0;j<n2;++j)
		{
			
			int temp2;
			scanf("%d",&temp2);
			if(temp2!=0)
			{
				matrixpointer point2=NewNode(entry);
				firstnode2->u.entry.value++;

				if(i>currentrow2)
				{				
						last2->right=header2[currentrow2];
						currentrow2=i;
						last2=header2[i];
				}

				
				point2->u.entry.row=i;
				point2->u.entry.col=j;
				point2->u.entry.value=temp2;

				last2->right=point2;
				last2=point2;
							
			
				header2[j]->u.next->down=point2;
				header2[j]->u.next=point2;

				//printf("row=%d,col=%d value=%d\n",point->u.entry.row,point->u.entry.col,point->u.entry.value);
			}
			//printf("i=%d,j=%d temp1=%d\n",i,j,temp1);                    
		}
		
	}

  	printf("tt00=%d",currentrow2);
  
	last2->right=header2[currentrow2];
		
	printf("max=%d n1=%d\n",max2,n2);
		
	for(i=0;i<n2;++i)
	{
		header2[i]->u.next->down=header2[i];
	}

	for(i=0;i<max2-1;++i)
	{
		header2[i]->u.next=header2[i+1];
	}
	
	header2[max2-1]->u.next=firstnode2;
	firstnode2->right=header2[0];

	matrixpointer tt2;
	matrixpointer head2=firstnode2->right;
	printf("row=%d,col=%d, value=%d\n",firstnode2->u.entry.row,firstnode2->u.entry.col,firstnode2->u.entry.value);
	for(i=0;i<firstnode2->u.entry.row;i++)
	{
		for(tt2=head2->right;tt2!=head2;tt2=tt2->right)
		{
			printf("here=%5d %5d %5d\n",tt2->u.entry.row,tt2->u.entry.col,tt2->u.entry.value);
		}
		
		head2=head2->u.next;
	}
	

	int qmax=m1>n2?m1:n2;

































	
	int c[10][10];
	for(i=0;i<10;++i)
		for(j=0;j<10;++j)
			c[i][j]=0;
	
	matrixpointer son1;matrixpointer son2;
	
	//son1->right=son1;
	//son1->down=son1;
	//son2->right=son2;
	//son2->down=son2;
	for(i=0;i<m1;++i)
	{	
		//son1=header1[i]->right;
		for(j=0;j<n2;++j)
		{ 
			int c=0;
		//printf("i=%d j=%d\n",i,j);
			son1=header1[i]->right;
			son2=header2[j]->down;
			while(son1!=header1[i]&&son2!=header2[j])
			{
				if(son1->u.entry.col==son2->u.entry.row)
				{
					c=c+(son1->u.entry.value*son2->u.entry.value);
					//c[i][j]=c[i][j]+(son1->u.entry.value*son2->u.entry.value);
					son1=son1->right;
					son2=son2->down;
				}
				
				else
				{
					if(son1->u.entry.col>son2->u.entry.row)
					{
						son2=son2->down;
					}
					
					else
					{
						son1=son1->right;
					}
				}
			}






















		}
	}
	 
	for(i=0;i<m1;++i)
	{
		for(j=0;j<n2;++j)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	

	
	
	
	

}
