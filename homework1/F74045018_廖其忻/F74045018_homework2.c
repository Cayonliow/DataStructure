#include<stdio.h>
#include<stdbool.h>
#include<math.h>

char set[100];
bool check[100];
int count_PS=0;

void find(int level,int index,int n,int N)
{
	int i;
	if(level==n)
	{
		int comma=0;
		printf("{");
		for(i=0;i<N;i++)
		{
			if(check[i]==true)
			{
				if(comma!=0)
				printf(",");
				printf("%c",set[i]);
				comma++;
			}
			
		}
		printf("}\n");
		count_PS++;
		return;
	}
	
	for(i=index;i<N;i++)
	{
		check[i]=true;
		find(level+1,i+1,n,N);
		
		check[i]=false;
	}
}
void recursive(int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		find(0,0,i,n);
	}
}
int main()
{
	char det;
	char comma;
	//char set[100];
	while(scanf("%c",&det)&&det=='{')
	{
		int n=0;
		while(scanf("%c%c",&set[n],&comma)&&comma!='}')
		{
			n++;
		}

		recursive(n+1);
		printf("There are total %d elements in the powerset.",count_PS);
	}
}
