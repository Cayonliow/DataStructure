#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	//int N=atoi(argv[1]);
	char p[33];
	int a[50];
	printf("gg");
	strcpy(p,argv[1]);
	int i;
	for(i=1;i<32;i++)
	{
		a[i]=(int)p[i]-48;
		printf("%d",a[i]);
	
	}

}
