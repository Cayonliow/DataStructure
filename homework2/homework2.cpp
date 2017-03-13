#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
	srand(time(NULL));

	int imove[8]={-1, 0, 1, 1, 1, 0,-1,-1};
	int jmove[8]={ 1, 1, 1, 0,-1,-1,-1, 0};
	//size of floor
	int N,M;
	//the initial coordinates of the cockroach
	int x,y;
	//the current coordinates of the cockroach 
	int currentX, currentY;
	//the random number
	int k;
	//the number of the tiles (N*M)
	int count;
	//total steps needed
	int step;
	//the floor
	int floor[45][25];

	FILE *Foutput;
	Foutput=fopen("Sample_Output.txt","w");
	if(!Foutput)
	{
		cout<<"Failed to open file"<<endl;
		return 0;
	}
	//-1 is marked to mean it is not the tiles of the floor
	memset(floor,-1,sizeof(floor));

	cout<<"N: ";
	cin>>N;
	if(N<2||N>40)
	{
		cout<<"the N you inserted is out of range"<<endl;
		exit(1);
	}
	
	cout<<"M: ";
	cin>>M;
	if(M<2||M>20)
	{
		cout<<"the M you inserted is out of range"<<endl;
		exit(1);
	}

	cout<<"Initial bug position X: ";
	cin>>x;
	if(x<0||x>=N)
	{
		cout<<"the position is out of range"<<endl;
		exit(1);
	}
	
	cout<<"Initial bug position Y: ";
	cin>>y;
	if(y<0||y>=M)
	{
		cout<<"the position is out if range"<<endl;
		exit(1);
	}
	
	
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			floor[i][j]=0;
		}
	}

	//the initial position is said to be reached
	//floor[x+1][y+1]++;
	currentX=x+1;
	currentY=y+1;

	step=0;
	count=1;
	while(count!=N*M)
	{
		k=rand()%8;
		
		//make sure the new position is not out the range of tile of the floor
		if(floor[currentX+imove[k]][currentY+jmove[k]]!=-1)
		{
			//update the neww position of the cockroach
			currentX=currentX+imove[k];
			currentY=currentY+jmove[k];
			
			step++;
			
			//the position haven't be reached
			if(floor[currentX][currentY]==0)
			{
				count++;
			}

			//to avoid the infinite loops 
			if(step==50000)
			{
				fprintf(Foutput,"maximum steps reached");
				return 0;
			}
			
			//the times of the cockroach reached ar every tiles is recorded
			floor[currentX][currentY]++;
		}
	}

	fprintf(Foutput,"Total Steps: %d\n\n",step);
	
	fprintf(Foutput,"Count Array: \n");
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
			fprintf(Foutput,"%3d ",floor[i][j]);
		
		fprintf(Foutput,"\n");
	}
	
	fclose(Foutput);

	return 0;
}

