'''
    Here is the python code for generating a magic squre.
    1) It's for n x n matrix
    2) It contains 1 to n^2 integer values
    3) It works only for odd integer n
    
    steps:- 1) Insert 1 in the top middle cell
            2) then go to the left up cell and insert the next integer value
            3) if that cell is occupied then go to the down cell and insert the value
            4) repeat the 2-4 until all the cells are filled.

    fact:- the sum of any row, column or diagonal numbers are same.
'''
import numpy as np

def magic_squre(n_value: int = 3):

    if n_value % 2 == 0:
        return 'Please enter an odd integer!'

    matrix = np.zeros((n_value, n_value), dtype = int)
    row = 0
    col = n_value//2

    for i in range(n_value**2):

        if matrix[row][col] == 0:
            matrix[row][col]= i + 1
        else:
            if row == n_value - 1 and col == n_value - 1:
                row = 1
                col = 0
                matrix[row][col] = i + 1
            else:
                row = row + 2 
                col = col + 1
                matrix[row][col] = i + 1

        if row == 0 and col == 0:
            row = n_value - 1
            col = n_value - 1
        elif col == 0:
            row = row - 1
            col = n_value - 1
        elif row == 0:
            row = n_value - 1
            col = col - 1
        else:
            row = row - 1
            col = col - 1

    return matrix

if __name__ == '__main__':
    print(magic_squre()) # as a parameter of the function we can pass any odd integer, by default it is 3.

