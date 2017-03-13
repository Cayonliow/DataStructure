#include<stdio.h>
#include<stdbool.h>
#include<math.h>

char set[100];
bool check[100];
void recursive(int level,int n)
{

	if(level==n+1)
	{
		//printf("{");
		int comma=0;
		for(int i=1;i<=n;i++)
		{
			if(check[i]==true)
			{
				printf("%c%c",comma==0?'{':',',set[i]);
				comma++;
			}
			
		}
		printf("}\n");
		return;	
	}

	check[level]=true;
	recursive(level+1,n);

	check[level]=false;
	recursive(level+1,n);
}

int main()
{
	char det;
	char comma;
	//char set[100];
	while(scanf("%c",&det)&&det=='{')
	{
		int n=1;
		while(scanf("%c%c",&set[n],&comma)&&comma!='}')
		{
			n++;
		}
		printf("n=%d\n\n",n);
		
		recursive(1,n);
	}



}
