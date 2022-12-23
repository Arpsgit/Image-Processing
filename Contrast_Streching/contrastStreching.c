#include<stdio.h>
#include<math.h>
void main(){
	FILE *p, *q;
	char a[10];
	char b[100];
	int col;
	int row;
	int max;
	p = fopen("low_contrast_image.pgm", "r");
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
    float max_pixel = 0;
    float min_pixel = 255;
    int r;
    float c;
    float d;

    for(int i = 0; i< row; i++){
        for(int j = 0; j<col; j++){
            if(img[i][j] > max_pixel){
                max_pixel = img[i][j];
            }
            if(img[i][j] < min_pixel){
                min_pixel = img[i][j];
            }
        }
    }
	q = fopen("highContrastImage.pgm","w");
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "%d\n", max);
	for(int i = 0; i< row; i++){
		for(int j = 0; j< col; j++){
            c = img[i][j] - min_pixel;
            d = max_pixel - min_pixel;
            r = (c/d)*255;
			fprintf(q,"%d\n", r);
            
            		
		}	
	}
	fclose(q);
}