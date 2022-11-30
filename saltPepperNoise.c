#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *p, *q;
	char a[10];
	char b[100];
	int col;
	int row;
	int max;
    int noiseMatrix[row][col];
	p = fopen("mypic.pgm", "r");
	fscanf(p, "%s\n", a);
	fscanf(p, "%[^\n]\n", b);
	fscanf(p, "%d %d\n", &col, &row);
	fscanf(p, "%d\n", &max);
	int img[row][col];
	for(int i = 0; i< row; i++){
		for(int j = 0; j<col; j++){
			fscanf(p,"%d\n", &img[i][j]);		
		}	
	}
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            noiseMatrix[i][j] = rand() % 15;
        }
    }
	fclose(p);
	q = fopen("noisepic.pgm","w");
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "%d\n", max);
	for(int i = 0; i< row; i++){
		for(int j = 0; j<col; j++){
            if(noiseMatrix[i][j] == 0){
                fprintf(q,"0\n");
            }
			else if(noiseMatrix[i][j] == 14){
                fprintf(q,"255\n");
            }
            else{
                fprintf(q,"%d\n", img[i][j]);
            }	
		}	
	}
	fclose(q);
}