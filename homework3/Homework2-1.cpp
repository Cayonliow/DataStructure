
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int size=4;
int NQ[4];
int flag[4];
int Front=-1,Rear=-1;

void printNQ()
{
	printf("Queue:[");
	int u=0;
	for(int u=0;u<size;++u)
	{
		if(u)	printf("[");
		if(flag[u]==true)	printf("%d",NQ[u]);
		printf("]");
	}
		
	
	printf("\n");
}

int main()
{
	int mode;
	int number;
	bool mark=false;
	int tmp=0;
	memset(NQ,-1,sizeof(NQ));
	memset(flag,false,sizeof(flag));
	printf("Insert(1)delete(2): ");
	while(scanf("%d",&mode)!=0)
	{
		if(mode==1)
		{
			mark=false;
			printf("Insert number: ");
			scanf("%d",&number);
			
			if(Rear+1==size)
			{
				if(Front!=-1)
				{
					for(int i=0;i<Rear-Front;++i)
					{
						NQ[i]=NQ[i+Front+1];
						flag[i]=true;
					}
					
					for(int i=Rear-Front;i<size;++i)
					{
						flag[i]=false;
					}
					
					Rear=Rear-Front-1;
					Front=-1;
					
					NQ[++Rear]=number;
					flag[Rear]=true;
				}
				
				else
				{
					printf("Queue is Full\n");
				}	
			}
			
			else
			{
				NQ[++Rear]=number;
				flag[Rear]=true;
			} 	
		}
		
		else if(mode==2)
		{
			if(Front==Rear)
			{
				printf("Queue is Empty\n");
				Front=-1;
				Rear=-1;
				mark=true;
			}
			
			else
			{
				
				Front++;flag[Front]=false;
				tmp=NQ[Front];
				if(Front==Rear)
				{
					Front=-1;
					Rear=-1;
				}
			}
		}
		
		else
		{
			printf("Invalid Input\n");
			return 0;
		}
		
		printf("Front=%d, Rear=%d\n", Front, Rear);
		if(mode==2&&mark==false)
		{
			printf("delete: %d\n",tmp);
		}
		printNQ();
		printf("\nInsert(1)delete(2): ");
		
	}
}
