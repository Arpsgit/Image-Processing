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
    int r;
    float gamma;
    float c;
    printf("Enter the gamma value: ");
    scanf("%f", &gamma);
    printf("\n");
    printf("Enter the C value: ");
    scanf("%f", &c);
    printf("\n");
	q = fopen("powpandac.pgm","w");
	fprintf(q, "%s\n", a);
	fprintf(q, "%s\n", b);
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "%d\n", max);
	for(int i = 0; i< row; i++){
		for(int j = 0; j<col; j++){     
            r = round(c * pow(img[i][j], gamma));
            if(r > 255){
                fprintf(q, "255\n");
            }
            else if(r < 0){
                fprintf(q, "0\n");
            }
            else{
                fprintf(q,"%d\n", r);
            }
            //printf("%d -> %d\n", img[i][j], r);		
		}	
	}
	fclose(q);
}