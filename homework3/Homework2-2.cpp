/*Circular*/ 

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int size=4;
int NQ[4];
int Front=0,Rear=0;
int In=0;
bool flag[4];

void printNQ()
{
	printf("Queue:[");
	int u=0;
	while(u!=size)
	{
		if(u)	printf("[");
		
		if(flag[u]==true)	printf("%d",NQ[u]);
		
		u++;
		printf("]");
	}
	
	printf("\n");
}

int main()
{
	int mode;
	int number;
	bool mark=false;
	int r=0;
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
			
			if((Rear+1)%size==0)
			{
				if(Front==0)
				{
					printf("Queue is Full\n");
				}
				else
				{
					if(In==Front)
					{
						printf("Queue is Full\n");
					}
					else
					{
						flag[In]=true;
						NQ[In++]=number;
					}

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
				Front=0; Rear=0;
				mark=true;
			}
			else
			{
				Front++;
				
				flag[Front]=false;
				tmp=NQ[Front];
				if(Front==Rear)
				{
					Front=0;
					Rear=In;
					In=0; 
				}
				
			}
		}
		
		else
		{
			printf("Invalid Input\n");
			return 0;
		}
		
		printf("Front=%d, Rear=%d, In=%d\n", Front, Rear, In);
		
		if(mode==2&&mark==false)
		{
			printf("delete: %d\n",tmp);
		}
		printNQ();
		printf("\nInsert(1)delete(2): ");
		
	}
}
