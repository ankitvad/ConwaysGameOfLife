//Conway's Game of Life 
//Servet Ulaþ
//03.10.2009

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int size=20;
int grid [20][20];
int buffergrid [20][20];
int choice=0;

int fillArray();
int printArray();
int checkNeighbor();
int fillGlider();
int fillSimple();
int swapGrids();



void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}


int main(){

	int steps=0;
    
	printf("Conway's Game of Life\n\n");
    printf("Each cell with one or no neighbors dies, as if by loneliness.\n"); 
    printf("Each cell with four or more neighbors dies, as if by overpopulation.\n");
    printf("Each cell with two or three neighbors survives.\n");
    printf("Each cell with three neighbors becomes populated.\n");

	printf("\nHow many steps would you like to simulate\ntype in 1337 for a glider with 40 steps\n");

	scanf("%d",&steps);
	if(steps==1337){
		steps=40;
		fillGlider();
	}else{
    	fillArray();
	}

	for(int i=0;i<steps;i++){
		
		wait(1);
	    printArray();
        checkNeighbor();
        swapGrids();
		//printf("\a");
	}




	scanf("%d");
	return 0;
}

int fillArray(){
    //fill the array with random junk, from 0 to 1
	int random=0;
    srand(time(NULL));


	for(int i=1;i<=size-1;i++){
		for(int j=1;j<=size-1;j++){
			random=rand()%2+0;
            grid[i][j]=random;
		}
	}
return 0;
}

int printArray(){
	system("cls");
    //print all the stuff that's been pushed into our array
    for(int i=0;i<=size;i++){
		printf("\n");
		for(int j=0;j<=size;j++){
            printf("%d ",grid[i][j]);
		}
	}

  return 0;
}

int checkNeighbor(){
//check a cell's 8 neighbors
    int cellHasNeighbor = 0;


	for(int i=1;i<=size-1;i++){
		for(int j=1;j<=size-1;j++){
          
			/*
			//all possible neighbors
			grid[i-1][j]
			grid[i-1][j-1]
			grid[i-1][j+1]
			grid[i+1][j]
			grid[i+1][j+1]
			grid[i+1][j-1]
			grid[i][j+1]
			grid[i][j-1]
          */
            
            cellHasNeighbor=0;

			if(grid[i-1][j]==1){
				cellHasNeighbor+=1;
			
              //printf("\n has %d neighbor tolal",cellHasNeighbor);

			}

			if(grid[i-1][j-1]==1){
				cellHasNeighbor+=1;
			

			}

			if(grid[i-1][j+1]==1){
				cellHasNeighbor+=1;

			}

			if(grid[i+1][j]==1){
				cellHasNeighbor+=1;
				

			}

			if(grid[i+1][j+1]==1){
				cellHasNeighbor+=1;
			 

			}

			if(grid[i+1][j-1]==1){
				cellHasNeighbor+=1;
			

			}

			if(grid[i][j-1]==1){
				cellHasNeighbor+=1;
			
				

			}

			if(grid[i][j+1]==1){
				cellHasNeighbor+=1;
			

			}

			if(grid[i][j]==1){
				//printf("cell has %d neighbors\n",cellHasNeighbor);
			  if(cellHasNeighbor==3||cellHasNeighbor==2){
				buffergrid[i][j]=1;
			  }
			  else{
				  buffergrid[i][j]=0;
			  }
			}
          // printf("cell has %d neighbors",cellHasNeighbor);

            if(grid[i][j]==0&&cellHasNeighbor==3){
				buffergrid[i][j]=1;
			}
            
			//printf("cell has %d neighbors\n",cellHasNeighbor);



			cellHasNeighbor=0;
		}
	}




 return 0;
}


int fillGlider(){
   
	for(int i=0;i<=size;i++){
		for(int j=0;j<=size;j++){
            grid[i][j]=0;
		}
	}

	grid[4][4]=1;
	grid[4][5]=1;
	grid[4][6]=1;
	grid[3][6]=1;
	grid[2][5]=1;
	

return 0;
}

int fillSimple(){
   
	for(int i=0;i<=size;i++){
		for(int j=0;j<=size;j++){
            grid[i][j]=0;
		}
	}

	grid[4][4]=1;
	grid[4][5]=1;
	grid[4][6]=1;
	

return 0;
}

int swapGrids(){

	for(int i=0;i<=size;i++){
		for(int j=0;j<=size;j++){
            grid[i][j]=buffergrid[i][j];
		}
	}
return 0;
}
