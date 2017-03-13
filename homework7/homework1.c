#include<stdio.h>

int num;
int aoe[100][100];
int count=0;

int MAX(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int early(int vertex_out)
{
int i,j;
	int maxxx=0;
	
	if(vertex_out==0)
	{
		return 0;
	}
		
	for(i=0;i<num;i++)
	{
		if(aoe[i][vertex_out]!=0)
		{
			maxxx=MAX(maxxx,aoe[i][vertex_out]+early(i));
		}	
	}

	return maxxx;
}

int late(int vertex_out,int vertex_in)
{
	int i,j;
	int maxxx=0;
	if(vertex_in==num-1)
	{
		return aoe[vertex_out][vertex_in];
	}
	
	for(i=0;i<num;i++)
	{
		if(aoe[vertex_in][i]!=0)
		{
			maxxx=MAX(maxxx,aoe[vertex_out][vertex_in]+late(vertex_in,i));
		}
	}
	
	return maxxx;
	
}

int main()
{
	FILE* file_in;
	//int num;
	//int aoe[100][100];
	int ee[100],ll[100];
	int last_path=0;

	int i,j;
	
	file_in=fopen("Sample_input.txt","r");
	if(file_in==NULL)
	{
		printf("The file is not valid to open\n");
		return 0;
	}

	else
	{
		fscanf(file_in,"%d",&num);
		//printf("%d",num);
		for(i=0;i<num;++i)
		{
			for(j=0;j<num;++j)
			{
				fscanf(file_in,"%d",&aoe[i][j]);
			}
		}

		fclose(file_in);
	}

	int mark=0;
	
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(aoe[j][i]!=0)
			{	
				ee[count++]=early(j);
				
				if(i==num-1)
				{
					last_path=MAX(last_path,ee[count-1]+aoe[j][i]);
				}
			}
		}
	}
	//printf("lastpath=%d\n",last_path);
	//for(i=0;i<count;++i)
		//printf("ee[%d]=%d\n",i,ee[i]);

	int back_count=count-1;
	for(i=num-1;i>=0;--i)
	{
		for(j=num-1;j>=0;--j)
		{
			if(aoe[j][i]!=0)
			{
				ll[back_count--]=last_path-late(j,i);
			}
		}
	}
	
	//for(i=0;i<count;++i)
	//	printf("ll[%d]=%d\n",i,ll[i]);
	
	printf("\t\t early time\t late time\t slack\n");
	printf("activity\t e\t\t l\t\t l-e\n");
	for(i=0;i<count;i++)
	{
		printf("a%d\t\t %d\t\t %d\t\t %d\n",i,ee[i],ll[i],ll[i]-ee[i]);
	}
}
