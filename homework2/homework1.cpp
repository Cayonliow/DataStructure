#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<fstream>

using namespace std;

int arr[100][100];
int e[100];

//the function required
void value (int n,int a,int b,int i,int j,int e[])
{
	static int count=0;
	int ti=i;
	int tj=j;
	
	while(ti<n&&tj<n)
	{
		e[count]=arr[ti][tj];
		cout<<"e["<<count<<"]=	"<<e[count];
		cout<<"		d("<<ti<<","<<tj<<")"<<endl;
		ti++;tj++;count++;
	}
}

int main()
{
	int num;
	int N;
	int a,b;
	FILE *openfile;
	string txtname;

	memset(arr,0,sizeof(arr));
	memset(e,0,sizeof(e));

	cout<<"Please input the file name(need .txt followed)"<<endl;
	cin>>txtname;

	openfile=fopen(txtname.c_str(),"r");
	if(openfile==NULL)
	{
		cout<<"the file you inserted is not exist"<<endl;
		exit(1);
	}

	fscanf(openfile,"%d",&N);

	if(N<=0)
	{
		cout<<"Invalid Input Format"<<endl;
		return 0;
	}

	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			fscanf(openfile,"%d",&arr[i][j]);
		}

	}
	fclose(openfile);

	cout<<"a: ";
	cin>>a;
	if(a>N)
	{
		cout<<"Invalid Input"<<endl;
		return 0;
	}
	
	cout<<"b: ";
	cin>>b;
	if(b>N)
	{
		cout<<"Invalid Input"<<endl;
		return 0;
	}

	//the lower triangle
	for(int i=a-1;i>=0;--i)
	{
		value(N,a,b,i,0,e);
	}

	//the upper triangle
	for(int j=1;j<b;++j)
	{
		value(N,a,b,0,j,e);

	}

return 0;
}
