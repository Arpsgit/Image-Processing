/*
    Here is the python code for generating a magic squre.
    1) It's for n x n matrix
    2) It contains 1 to n^2 integer values
    3) It works only for odd integer n
    
    steps:- 1) Insert 1 in the top middle cell
            2) then go to the left up cell and insert the next integer value
            3) if that cell is occupied then go to the down cell and insert the value
            4) repeat the 2-4 until all the cells are filled.

    fact:- the sum of any row, column or diagonal numbers are same.
*/
#include<stdio.h>
#include <stdlib.h>
 
int** magicSqure(int n_value){
    int **array;
    array = malloc(sizeof(int*) * n_value);
    for(int j = 0; j < n_value; j++){
        array[j] = malloc(sizeof(int*) * n_value);
    }
    for(int m = 0; m < n_value; m++){
        for(int x = 0; x < n_value; x++){
            array[m][x] = 0;
        }
    }
    int row = 0;
    int col = n_value / 2;
    int limit = n_value * n_value;
    for(int i = 0; i < limit; i++){

        if(array[row][col] == 0){
            array[row][col]= i + 1;
        }
        else{
            if(row == n_value - 1 && col == n_value - 1){
                row = 1;
                col = 0;
                array[row][col] = i + 1;
            }
            else{
                row = row + 2;
                col = col + 1;
                array[row][col] = i + 1;
            }
        }
        if(row == 0 && col == 0){
            row = n_value - 1;
            col = n_value - 1;
        }
        else if(col == 0){
            row = row - 1;
            col = n_value - 1;
        }
        else if(row == 0){
            row = n_value - 1;
            col = col - 1;
        }
        else{
            row = row - 1;
            col = col - 1;
        }
            
    }

    return array;
}

void main(){
    int n_value;
    n_value = 7; // we can get any n x n matrix as a magic square, by changing this n_value which should be an odd integer.
    int ** result;
    result = magicSqure(n_value);
    for(int m = 0; m < n_value; m++){
        for(int x = 0; x < n_value; x++){
            printf("%d\t", result[m][x]);
        }
        printf("\n");
    }
}