// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int valid(char board[9][9], int num, int row,int col);
bool solve(char board[9][9],int boardSize, int col);

int main() {
    // Write C code here
char board[9][9] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1", "7...2...6",".6....28.","...419..5","....8..79"};

char board2[9][9] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1", "7...2...6",".6....28.","...419..5","....8..79"};
    
   // int valid2 = valid(board,1,0,2);
   // printf("%d\n\n\n", valid2);
    if ((board[0][2] == '.') && (valid(board,1,0,2) == 1))
        printf(":D\n\n\n");
        
for (int i = 0;i<9;i++){
    for (int j = 0;j<9;j++){
        printf("%c ", board[i][j]);
        if (j%3 == 2)
            printf("   ");
    }
    printf("\n");
    if (i%3 == 2)
        printf("\n");
}
 

   // printf("%d", 7%3);
   // valid(board,6,7,2);
    printf("\n\n");
    solve(board,0,0);
    
    
    
    for (int i = 0;i<9;i++){
    for (int j = 0;j<9;j++){
        printf("%c ", board[i][j]);
        if (j%3 == 2)
            printf("   ");
    }
    printf("\n");
    if (i%3 == 2)
        printf("\n");
}
    return 0;
}



int valid(char board[9][9], int num, int row, int col){
    int sc = col - col%3; /*The starting index of each box*/
    int sr = row - row%3;

    int temp;
    char number = num + '0';
    int i = 0;
    for (int i = 0;i<9;i++){

        if ((board[row][i] == number) || (board[i][col] == number)){
         
            temp = 0;
            break;
        }else
            temp = 1;
        
       
}

/*Checking if the number exists in the box its in*/


    for(int i = sr; i<sr+3;i++){
        if (temp == 0)
            break;
        for(int j = sc; j<sc+3;j++){
          
            if (board[i][j] == number){
                temp = 0;
                break;
            }else
                temp = 1;
        }
        }
   
   return temp;
}


bool solve(char board[9][9], int indexi, int indexj){

    char number;
    char blank = '.';
    int valid2;
    int blankcol; // pointer array storing all the blank indices
    int blankrow; // pointer array storing all the blank indices
    int num;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            
        if (board[i][j] == blank){
            
            for (num = 1;num<=9;num++){
                
                    if (valid(board,num,i,j) == 1){
                        number = num + '0';
                       // printf("allocating %d in position [%d,%d]\n\n",num,i,j);
                        board[i][j] = number; // since we changed the value of board, we call the function again to see if this is the correct path to take and if not then we would allocate it as a blank
                        if (solve(board,i,j))
                            return true;
                        board[i][j] = '.';
                            
                    }

                    
                }return false; // if no number from 1-9 works then it returns false
                 
        }
        

           
                
             
        }
        }
        return true; // returns true when the board is solved
    }












