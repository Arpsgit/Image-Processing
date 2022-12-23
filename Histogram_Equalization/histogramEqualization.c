#include<stdio.h>
#include<math.h>
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
    
    float pdf[256];
    float cdf[256];
    int mapping[256];
    for(int i = 0; i < 256; i++){
        pdf[i] = 0;
        cdf[i] = 0;
        mapping[i] = 0;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            pdf[img[i][j]]++;
        }
    }
    for(int i = 0; i < 256; i++){
        pdf[i] = pdf[i] / (col * row);
    }
    cdf[0] = pdf[0];
    for(int i = 1; i < 256; i++){
        cdf[i] = cdf[i-1] + pdf[i];
    }
    for(int i = 1; i < 256; i++){
        mapping[i] = round(cdf[i] * 255);
    }

    int r;
	q = fopen("panda1.pgm","w");
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "%d\n", max);
	for(int i = 0; i< row; i++){
		for(int j = 0; j< col; j++){
            r = mapping[img[i][j]];
			fprintf(q,"%d\n", r);  		
		}	
	}
	fclose(q);
}