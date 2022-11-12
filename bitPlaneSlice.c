#include<stdio.h>
#include<math.h>

int bitPlane(int pixel, int plane){
    for(int i = 0; i < plane - 1; i++){
        pixel = pixel / 2;
    }
    return(pixel % 2);
}

void main(){
	FILE *p, *q;
	char a[10];
	char b[100];
	int col;
	int row;
	int max;
	p = fopen("mypic.pgm", "r"); // provide the image path here
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
	q = fopen("msbmypic1.pgm","w"); // provide the output file name here
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "1\n");
	for(int i = 0; i< row; i++){
		for(int j = 0; j<col; j++){
            r = bitPlane(img[i][j], 8); // change the second argument of the bit_plane function according to bit plane
			fprintf(q,"%d\n", r);		
		}	
	}
	fclose(q);
}