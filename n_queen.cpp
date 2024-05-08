#include <bits/stdc++.h>
#define N 8
using namespace std;

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

bool isSafe(int board[N][N],int col,int row){
   	 int i,j;
   	 
   	 for(i = 0;i<col;i++)
   	     if(board[row][i] == 1)
   	        return false;
   	
   	for(i = row,j = col;i >= 0 && j >= 0; i--,j--){
   	      if(board[i][j] == 1)
   	         return false;
   	}
   	for(i = row,j = col; i < N && j >= 0; i++,j--){
   	      if(board[i][j] == 1)
   	         return false;
   	}
   	return true;
	 
	
}

bool solveNQUtil(int board[N][N],int col){
    if(col >= N){
        return true;
    }
    for(int row = 0;row < N;row++){
        if(isSafe(board,col,row)){
            board[row][col] = 1;
            if(solveNQUtil(board,col+1)){
                return true;
            };
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int board[N][N];
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
             board[i][j] = 0;
        }
    }

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		
	}

	printSolution(board);

	return 0;
}