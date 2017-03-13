#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

int heap[100000];
int total;

void insert(int value,int number)
{
	int temp=number;
	heap[temp]=value;
	
	while(temp>1)
	{
		if(heap[temp/2]<heap[temp])
		{
			heap[temp]=heap[temp/2];
			heap[temp/2]=value;
		}
		temp=temp/2;
	}
}

void print_HEAP(int n)
{
	int mark=1;
	int i; 
	for(i=1;i<n;++i)
	{
		printf("%d ",heap[i]);
		
		if(i==mark)
		{
			if(i<n)
			{
				printf("\n");
			}

			mark=mark*2+1;
		}
	}
	printf("\n");
}

void comparetree(int n)
{	int temp;
	
	if(n*2>=total||n*2+1>=total)	
	{	
		return;
	}
	
	
	if(heap[n/2]<heap[n]&&n!=1)
	{
		temp=heap[n/2];
		heap[n/2]=heap[n];
		heap[n]=temp;
		comparetree(n/2);
	}

	else if(heap[n*2+1]>heap[n])
	{
		if(heap[n*2]>heap[n])
		{
			if(heap[n*2+1]>heap[n*2])
			{
				temp=heap[n*2+1];
				heap[n*2+1]=heap[n];
				heap[n]=temp;
				comparetree(n*2+1);
			}

			else
			{
				temp=heap[n*2];
				heap[n*2]=heap[n];
				heap[n]=temp;
				comparetree(n*2);
			}
		}

		else
		{	
			temp=heap[n*2+1];
			heap[n*2+1]=heap[n];
			heap[n]=temp;
		printf("n=%d\n",n);
			comparetree(n*2+1);
		}
	}

	else if(heap[n*2]>heap[n])	
	{
		temp=heap[n*2];
		heap[n*2]=heap[n];
		heap[n]=temp;	
		printf("n=%d\n",n);
		comparetree(n*2);
	}

}

int main()
{
	FILE *filein;
	char comma;
	int value;	
	int n=1;
	int i; 

	LARGE_INTEGER Time1, Time2, TimeS;

	memset(heap,0,sizeof(heap));

	filein=fopen("in.txt","r");
	if(filein==NULL)
	{
		printf("Invalid to open file\n");
		return 0;
	}
	else
	{
		while(fscanf(filein,"%d%c",&value,&comma)!=EOF)
		{
			insert(value,n);
			n++;
		}
	}

	fclose(filein);

	total=n;
	printf("Create Max Heap:\n");
	printf("Max Heap:\n");

	print_HEAP(n);

	printf("Change priority?(Y/N):");

	while(1)
	{
		char YnN;
		//printf("Change priority?(Y/N):");
		scanf("%c",&YnN);

		if(YnN=='Y'||YnN=='y')
		{
			int priority;
			printf("Choice priority:");
			scanf("%d",&priority);
			bool flag=false;
			int g;
			for(i=1;i<n;++i)
			{
				if(priority==heap[i])
				{
					g=i;
					flag=true;
				}
			}

			if(flag==false)
			{
				printf("The priority is not available.\n");
				printf("Please type again\n");
			}

			else
			{
				int tochange;
				printf("Change priority to:");
				scanf("%d",&tochange);
				heap[g]=tochange;

				QueryPerformanceFrequency(&TimeS);
				QueryPerformanceCounter(&Time1);
				
				comparetree(g);
				print_HEAP(n);

				QueryPerformanceCounter(&Time2);

				printf("Spend time: %lf sec\n",(Time2.QuadPart-Time1.QuadPart)/(double)(TimeS.QuadPart));
				printf("Change priority?(Y/N):");
			}
		}

		else if(YnN=='N'||YnN=='n')
		{
			int play;
			printf("Press any key to continue...");
			scanf("%d",&play);
			return 0;
		}
	}
}
