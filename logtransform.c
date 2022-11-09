#include<stdio.h>
#include<math.h>
void main(){
	FILE *p, *q;
	char a[10];
	char b[100];
	int col;
	int row;
	int max;
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
	fclose(p);
    int r;
	q = fopen("logmypic1.pgm","w");
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "%d\n", max);
	for(int i = 0; i< row; i++){
		for(int j = 0; j<col; j++){
            r = round(104 * log(1 + img[i][j])/log(10));
			fprintf(q,"%d\n", r);
            
            //printf("%d -> %d\n", img[i][j], r);		
		}	
	}
	fclose(q);
}
