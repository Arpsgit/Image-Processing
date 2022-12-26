#include<stdio.h>

int main(){
	FILE *p_one, *p_two, *q;
	char a1[10], a2[10];
	char b1[100], b2[100];
	int col, col_one, col_two;
	int row, row_one, row_two;
	int max_one, max_two;
    // We should use two images of same dimension.

	p_one = fopen("mypic.pgm", "r");
	fscanf(p_one, "%s\n", a1);
	fscanf(p_one, "%[^\n]\n", b1);
	fscanf(p_one, "%d %d\n", &col_one, &row_one);
	fscanf(p_one, "%d\n", &max_one);
	int img_one[row_one][col_one];
	for(int i = 0; i< row_one; i++){
		for(int j = 0; j<col_one; j++){
			fscanf(p_one,"%d\n", &img_one[i][j]);		
		}	
	}
	fclose(p_one);

    p_two = fopen("panda.pgm", "r");
	fscanf(p_two, "%s\n", a2);
	fscanf(p_two, "%[^\n]\n", b2);
	fscanf(p_two, "%d %d\n", &col_two, &row_two);
	fscanf(p_two, "%d\n", &max_two);
	int img_two[row_two][col_two];
	for(int i = 0; i< row_two; i++){
		for(int j = 0; j<col_two; j++){
			fscanf(p_two,"%d\n", &img_two[i][j]);		
		}	
	}
	fclose(p_two);
    if(row_one == row_two && col_one == col_two){
        row = row_one;
        col = col_one;
    }
    else{
        printf("Please provide two pictures of same dimension\n");
        return 0;
    }

	q = fopen("output_1.pgm","w");
	fprintf(q, "P2\n");
	fprintf(q, "# CREATOR: Arpan Manna\n");
	fprintf(q, "%d %d\n", col, row);
	fprintf(q, "255\n");
	for(int i = 0; i< row; i++){
		for(int j = 0; j<col; j++){
            if(img_one[i][j] < img_two[i][j]){
                if(img_one[i][j] < 128){
                    fprintf(q,"%d\n", img_one[i][j]);
                }
                else{
                    fprintf(q,"%d\n", img_two[i][j]);
                }
            }
            else{
                if(img_two[i][j] < 128){
					fprintf(q,"%d\n", img_two[i][j]);
				}
				else{
					fprintf(q,"%d\n", img_one[i][j]);
				}
            }
					
		}	
	}
	fclose(q);
    return 0;
}