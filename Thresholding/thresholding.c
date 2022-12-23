#include<stdio.h>
void main(){
	FILE *p, *q;
	char a[10];
	char b[100];
	int col;
	int row;
	int max;
	p = fopen("panda.pgm", "r");
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
	fclose(p);
    
	q = fopen("temp.pgm","w");
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "%d\n", max);
	for(int i = 0; i< row; i++){
		for(int j = 0; j< col; j++){
            if(img[i][j] > 130){
                fprintf(q,"%d\n", 255);
            }
            else{
                fprintf(q,"%d\n", 0);
            } 
            		
		}	
	}
	fclose(q);
}