#include<stdio.h>

int function(int n)
{
	if(n==1)	return 1;

	return n*function(n-1);
} 

int main()
{
	int n;
	printf("please enter a number bigger than 0. enter '-1' to end program\n");
	while(scanf("%d",&n)&&n!=-1)
	{
		int temp=n;
		int product=1;
		while(n!=1)
		{
			product=product*(n);
			n--;
		}
		printf("iterative: %d\n",product);
		printf("recursive: %d\n",function(temp));
		printf("please enter a number bigger than 0. enter '-1' to end program\n");
	}
return 0;
}
