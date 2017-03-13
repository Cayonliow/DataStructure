#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int size=4;
int NQ[4];
int Front=0,Rear=0;

void printNQ()
{
	printf("Queue:[");
	for(int i=0;i<size;++i)
	{
		if(i!=0)
		printf("[");
		if(NQ[i]!=-1)
		{
			printf("%d",NQ[i]);
		}
		printf("]");
	}
	printf("\n");
	//printf("\nInsert(1)delete(2): ");
}

int main()
{
	int mode;
	int number;
	memset(NQ,-1,sizeof(NQ));
	printf("Insert(1)delete(2): ");
	while(scanf("%d",&mode)!=0)
	{
		if(mode==1)
		{
			printf("Insert number: ");
			scanf("%d",&number);
			
			if(Rear+1==size)
			{
				if(Front!=0)
				{
					for(int i=1;i<=Rear-Front;++i)
					{
						NQ[i]=NQ[i+Front];
					}
				
					
					Rear=Rear-Front+1;
					//Front=0;
					NQ[Rear]=number;
					for(int i=Rear+1;i<=size;++i)
					{
						NQ[i]=-1;
					}
					Front=0;
					printf("Front=%d, Rear=%d\n", Front, Rear);
					printNQ();	
				}	
				
				else
				{
					printf("Front=%d, Rear=%d\n", Front, Rear);
					printf("Queue is full\n");
					//printf("Insert(1)delete(2): ");
					printNQ();
				}
			}
			
			else
			{
				NQ[++Rear]=number;
				printf("Front=%d, Rear=%d\n", Front, Rear);
				printNQ();
			}
			
		}
		
		else if(mode==2)
		{
			if(Front==Rear)
			{
				printf("Front=%d, Rear=%d\n",Front,Rear);
				printf("Queue is empty\n");
				Front=0,Rear=0;
			}
			
			else
			{
				Front++;
				
				NQ[Front]=-1;
				printf("Front=%d, Rear=%d\n",Front,Rear);
				printNQ();
				if(Front==Rear)
				{
					Front=0,Rear=0;	
				}
			}
		}
		
		else
		{
			printf("Invalid Input\n");
			return 0;
		}
		
		printf("\nInsert(1)delete(2): ");
		
	}
}
