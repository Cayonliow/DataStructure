#include<iostream>
#include<cstdio>
#include<stack>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

struct COOR
{
	int x,y;
};

int Dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
int Dy[8]={-1, 0, 1, -1,1, -1, 0,1};

char maze[100][100];
bool used[100][100];
COOR path[100];
int no_path[100000];

static int r=0,q=0,fuck=0;
int M,N;
FILE *txtout;


void print_maze()
{
	for(int i=0;i<r;++i)
	{
		maze[path[i].x][path[i].y]='*';
	}
	for(int i=1;i<=M;++i)
	{
		for(int j=1;j<=N;++j)
		{
			fprintf(txtout,"%c",maze[i][j]);
			if(maze[i][j]=='*')
			{
				maze[i][j]='0';
			}
		}
		fprintf(txtout,"\n");
	}
}

void DFS(int Sx,int Sy,int Ex,int Ey)
{
	for(int i=0;i<8;++i)
	{
		if(maze[Sx+Dx[i]][Sy+Dy[i]]=='d')
		{
			no_path[q++]=r;
			print_maze();
			fprintf(txtout,"\n");
			//return;	
		}
	}

	for(int i=0;i<8;++i)
	{
		if(maze[Sx+Dx[i]][Sy+Dy[i]]=='0'&& used[Sx+Dx[i]][Sy+Dy[i]]==false)
		{
			//printf("%d, %d\n", Sx+Dx[i], Sy+Dy[i]);
			path[r].x=Sx+Dx[i];
			path[r++].y=Sy+Dy[i];
			used[Sx+Dx[i]][Sy+Dy[i]]=true;
			DFS(Sx+Dx[i],Sy+Dy[i],Ex,Ey);
			r--;
			used[Sx+Dx[i]][Sy+Dy[i]]=false;
		}
	}
	//return;
}

int main()
{
	FILE *txtfile;
	
	memset(maze,'1',sizeof(maze));
	memset(used,false,sizeof(used));
	memset(path,-1,sizeof(path));
	memset(no_path,0,sizeof(no_path));
	
	txtfile=fopen("in.txt","r");
	txtout=fopen("out.txt","w");
	
	if (!txtfile)
	{
		fprintf(txtout,"FAIL TO OPEN FILE\n");
		return 0;
	}
	
	txtout=fopen("out.txt","w");
	
	if (!txtout)
	{
		fprintf(txtout,"FAIL TO OPEN FILE\n");
		return 0;
	}
	
	int a=1,b=1;
	while(fscanf(txtfile,"%c",&maze[a][b++])!=EOF)
	{
		if(maze[a][b-1]=='\n')
		{
			a++;
			N=b-2;
			b=1;
		}
		M=a;
	}
	
	COOR start,end;
	for(int i=1;i<=M;++i)
	{
		for(int j=1;j<=N;++j)
		{
			if(maze[i][j]=='s')
			{
				start.x=i;
				start.y=j;
				used[i][j]=true;	
			}
			
			if(maze[i][j]=='d')
			{
				end.x=i;
				end.y=j;
				used[i][j]=true;
			}
		}
	}
	
	path[0]=start;
	DFS(start.x,start.y,end.x,end.y);
	int shortest=200000; 
	for(int i=0;i<q;++i)
	{ 
		if(no_path[i]<shortest)
		{
			shortest=no_path[i];
		}
	}
	if(shortest==200000)
	{
		fprintf(txtout,"No route");
	} 
	else
	{
		fprintf(txtout,"The shortest path : %d steps\n",shortest+1);
	}
	
	
	fclose(txtfile);
	fclose(txtout);
}
