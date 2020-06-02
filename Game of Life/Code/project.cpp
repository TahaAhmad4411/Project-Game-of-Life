#include<iostream>
#include<fstream>
using namespace std;

int **UpdateSecondaryArray(int **Grid,int **SurvivingCells)//Updating SurvivingCells Array After applying 1st Generation(If needed)
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(Grid[i][j]=='U')
			{
				SurvivingCells[i][j]=0;
			}
			else{SurvivingCells[i][j]=Grid[i][j];}
		}
	}
	return SurvivingCells;
}


int **KnowYourNeighbours(int**Grid,int**NeighbouringCells)//Know Your Neighburs :3
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(Grid[i][j]=='F')
			{
				for(int y=i-1;y<i+2;y++)
				{
					for(int z=j-1;z<j+2 ;z++)
					{
						if(Grid[y][z]!='F')	
							NeighbouringCells[y][z]+=1;
					}
				}
			
			}			
		}
	}	

return NeighbouringCells;

}


int **PrimaryCells(int**SurvivingCells,int**NeighbouringCells)//Counting the already Existing Cells
{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
			if(NeighbouringCells[i][j]==-4)
			{
				if(NeighbouringCells[i-1][j-1]==-4  && SurvivingCells[i][j]<=10)
				{
					SurvivingCells[i][j]+=1;
				}
				if(NeighbouringCells[i][j-1]==-4 && SurvivingCells[i][j]<=10)
				{
					SurvivingCells[i][j]+=1;
				}
				if(NeighbouringCells[i+1][j+1]==-4  && SurvivingCells[i][j]<=10)
				{
					SurvivingCells[i][j]+=1;
				}
				if(NeighbouringCells[i-1][j]==-4 && SurvivingCells[i][j]<=10)
				{
					SurvivingCells[i][j]+=1;
				}
				if(NeighbouringCells[i+1][j]==-4  && SurvivingCells[i][j]<=10)
				{	
					SurvivingCells[i][j]+=1;		
				}
				if(NeighbouringCells[i-1][j+1]==-4 && SurvivingCells[i][j]<=10)
				{
					SurvivingCells[i][j]+=1;
				}
				if(NeighbouringCells[i][j+1]==-4 && SurvivingCells[i][j]<=10)
				{
					SurvivingCells[i][j]+=1;
				}
				
				if(NeighbouringCells[i+1][j-1]==-4  && SurvivingCells[i][j]<=10)
				{
					SurvivingCells[i][j]+=1;
				}

			}
			}
		}
return SurvivingCells;
	
}

int **DecideDeadAndAlivecells(int**Grid,int**NeighbouringCells)//Decide Alive and Dead Cells
{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(NeighbouringCells[i][j]=='U')
				{
					continue;
				}				
				if(NeighbouringCells[i][j]==3)
				{
					Grid[i][j]='O';
				}
				else if(NeighbouringCells[i][j]==1 || NeighbouringCells[i][j]==2 || NeighbouringCells[i][j]>=4)
				{
					Grid[i][j]=0;
					NeighbouringCells[i][j]=0;
				}

			}
		}
	return NeighbouringCells;
}


int **AlivecellsPrimary(int **SurvivingCells)//Survival Mode for Already Existing Cells 
{
	for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(SurvivingCells[i][j]==2 || SurvivingCells[i][j]==3 )
				{
					SurvivingCells[i][j]='F';
				}
				
				
			}
		}
	return SurvivingCells;
}

int **PurifySecArray(int **SurvivingCells)//Removing redundant numbers from SurvivingCells array
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(SurvivingCells[i][j]!='F' && SurvivingCells[i][j]>0 )
			{	
				SurvivingCells[i][j]='U';
			}
		}
	}
return SurvivingCells;
}

//------------------------------------------------------6.Update Grid--------------------------------------------------------------------//
int **UpdateGrid(int **SurvivingCells,int **Grid)
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(Grid[i][j]=='F')
			{
				Grid[i][j]=SurvivingCells[i][j];
			}
		}
	}
return Grid;
}


void DisplayArray(int **array)
{

	//Display Array

	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(int(array[i][j])>=10){
			cout<<char(array[i][j])<<" ";continue;}
			cout<<array[i][j]<<" ";		
		}
			
			cout<<endl;
	}


}

void DisplayTheGenerationCoordinates(int **Grid)
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(Grid[i][j]=='F' || Grid[i][j]=='O')
			{
			cout<<i<<" "<<j<<"\n";
			}	
		
		}

	}
}



void WritingInAFile(int **Grid,int gen,int livecells)//Writing
{
	ofstream f;
	f.open("output.txt");
	f<<gen<<"\n";
	f<<livecells<<"\n";
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(Grid[i][j]=='F' || Grid[i][j]=='O')
			{
				f<<i<<" "<<j<<endl;			
			}
		}
	}
	f.close();
}

//-----------------------------------------------------10.Default Values----------------------------------------------------------//
void Initializer(int**cell)
{	
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
		cell[i][j]=0;
		}
	}
}

int **UpdatingNeiArray(int**Grid,int**NeighbouringCells)
{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(Grid[i][j]>=10 && Grid[i][j]!='U')
				{
				NeighbouringCells[i][j]=-4;
				Grid[i][j]='F';
				}	
				else if(Grid[i][j]=='U')
				{
				NeighbouringCells[i][j]='U';
				}
			}
		}
	return NeighbouringCells;
	}


	
	
	

int** Generation(int **Grid,int**SurvivingCells,int**NeighbouringCells,int gen)
{
	


	NeighbouringCells=KnowYourNeighbours(Grid,NeighbouringCells);//Counting the neighbours of NeighbouringCells Array
	
	SurvivingCells=PrimaryCells(SurvivingCells,NeighbouringCells);	//Counting Secondary Cells	
	
	
	NeighbouringCells=DecideDeadAndAlivecells(Grid,NeighbouringCells);//Deciding the Neibouring cells of alive or Death	
	
	SurvivingCells=AlivecellsPrimary(SurvivingCells);//Identifying thoseCells that have been survived

	SurvivingCells=PurifySecArray(SurvivingCells);//Duplicates Finding
	
	
	Grid=UpdateGrid(SurvivingCells,Grid);//Grid Checking
		
	cout<<"\n\nGrid Array\n\n";	
	DisplayArray(Grid);
	cout<<"\nThe Generation Coordinates are "<<endl;
	return Grid;	

}
//--------------------------------------------------------------11.Describing the Letters in a game--------------------------------------//
void UserMessage()
{
cout<<"\tWelcome  \n";
	cout<<"\nFollowing are the rules\n";
	cout<<"\n1. O means new birth";
	cout<<"\n2.   F means Remaining in a  generation\n";
	cout<<"3. \'U \'  where U means UnderRecognize or in a generation\n";	
}	

void start()//Start of the game
{
		
	UserMessage();
	
	int **NeighbouringCells=new int*[20];
	int **Grid=new int*[20];
	int **SurvivingCells=new int*[20];
	for(int i=0;i<20;i++)
	{
		NeighbouringCells[i]=new int[20];
		SurvivingCells[i]=new int[20];
		Grid[i]=new int[20];
	}
	Initializer(Grid);
	Initializer(SurvivingCells);
	Initializer(NeighbouringCells);
	
	
	ifstream f;
	int a,row,col;
	f.open("input.txt");
	f>>a;
	int gen=a;
	cout<<"\nTotal number of Generations: "<<gen<<endl;
	f>>a;
	int livecells=a;
	cout<<"livecells Cells Read from File: "<<livecells<<endl;		
	cout<<"\n\n";
	while(f>>a){
		row=a;
		f>>a;
		col=a;
		Grid[row][col]='F';
		NeighbouringCells[row][col]=-4;
		SurvivingCells[row][col]=0;
		
		cout<<row<<" "<<col<<endl;
		}
	f.close();
	cout<<"\nThe Original Coordinates\n";	
	DisplayArray(Grid);
	
	cout<<"\nIts Generation "<<1<<endl;	

	Grid = Generation(Grid,SurvivingCells,NeighbouringCells,gen);
	DisplayTheGenerationCoordinates(Grid);	
	

	//----------------------------------------------------------Generation----------------------------------------------------------//
	for(int i=1;i<gen;i++)
	{	
		cout<<"Its Generation "<<i+1<<endl;
		Initializer(SurvivingCells);
		Initializer(NeighbouringCells);
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				if(Grid[i][j]=='F' || Grid[i][j]=='O')
				{
					Grid[i][j] = 'F';
					NeighbouringCells[i][j]=-4;
					SurvivingCells[i][j]=0;
				}	
				else if(Grid[i][j]=='U'){
					Grid[i][j] = 0;
				}
			
			}
	
		}
			
		Grid = Generation(Grid,SurvivingCells,NeighbouringCells,gen);
		DisplayTheGenerationCoordinates(Grid);
	
	}
	
	
	WritingInAFile(Grid,gen,livecells);//Write

	
	for(int i=0;i<20;i++)//Destroy array
	{
		delete[]Grid[i];	
		delete[]NeighbouringCells[i];
		delete[]SurvivingCells[i];	
	}
	delete[]Grid;
	delete[]NeighbouringCells;
	delete[]SurvivingCells;
}


	//---------------------------------------------------------Main Function-----------------------------------------------------//
int main()
{
	start();
	return 0;

}
