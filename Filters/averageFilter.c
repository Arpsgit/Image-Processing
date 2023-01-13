#include<stdio.h>

void main(){
	FILE *p, *q;
	char a[10];
	char b[100];
	int col, col1;
	int row, row1;
	int max;
    int fil;
    int start;
    int sum;
	p = fopen("panda.pgm", "r");
	fscanf(p, "%s\n", a);
	fscanf(p, "%[^\n]\n", b);
	fscanf(p, "%d %d\n", &col, &row);
	fscanf(p, "%d\n", &max);
    printf("Enter the filter size: "); // enter a filter size of odd number.
    scanf("%d", &fil);
    printf("\n");
    col1 = col + fil - 1;
    row1 = row + fil - 1;
	int img[row1][col1];
    int newImg[row1][col1];
    start = (fil - 1) / 2;
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            img[i][j] = 0;
        }
    }
	for(int i = start; i< (row1 - start); i++){
		for(int j = start; j< (col1 - start); j++){
			fscanf(p,"%d\n", &img[i][j]);		
		}	
	}
	fclose(p);

    for(int i = start; i < (row1 - start); i++){
        for(int j = start; j < (col1 - start); j++){
            sum = 0;
            for(int k = (i - start); k < (i + fil - start); k++){
                for(int l = (j - start); l < (j + fil - start); l++){
                    sum = sum + img[k][l];
                }
            }
            newImg[i][j] = sum / (fil * fil);
        }
    }

	q = fopen("pandac.pgm","w");
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "%d\n", max);
	for(int i = start; i< (row1 - start); i++){
		for(int j = start; j<(col1 - start); j++){
			fprintf(q,"%d\n", newImg[i][j]);		
		}	
	}
	fclose(q);
}
