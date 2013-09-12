#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	/* type, row number, column number, low bound, up bound */
	
	if(argc != 6) {
		printf("please enter data  type(int, float), row number, column number, low bound, up bound\n");
		return 0;
	}	

	int i;
	int row_num;
	int col_num;
	time_t t;
	FILE *fp;

	row_num = atoi(argv[2]);
	col_num = atoi(argv[3]);

	srand((unsigned) time(&t));

	fp = fopen("kmeans.dat", "wb");

	if(strcmp(argv[1], "int") == 0) {
		int low_bound;
		int up_bound;
		int *buf;
		low_bound = atoi(argv[4]);
		up_bound = atoi(argv[5]);
		
		buf = (int *)malloc(row_num * col_num * sizeof(int));

		for(i = 0; i < row_num * col_num; i++) {
			buf[i] = rand() % (up_bound - low_bound + 1) + low_bound;			
			/* printf("%d ", buf[i]); */
		}
		
		/* printf("\n"); */
		
		fwrite(buf, sizeof(int), row_num * col_num, fp);

		free(buf);
	}
	if(strcmp(argv[1], "float") == 0) {
		float low_bound;
		float up_bound;
		float *buf;
		low_bound = atof(argv[4]);
		up_bound = atof(argv[5]);

		int _low_bound = low_bound * pow(10, 6);
		int _up_bound = up_bound * pow(10, 6);

		buf = (float *)malloc(row_num * col_num * sizeof(float));
		
		for(i = 0; i < row_num * col_num; i++) {
			buf[i] = (rand() % (_up_bound - _low_bound +1) + _low_bound) / pow(10, 6);
			/* printf("%f ", buf[i]); */
		}
		
		/* printf("\n"); */
		
		fwrite(buf, sizeof(float), row_num * col_num, fp);

		free(buf);
	}

	close(fp);
	
	return 0;
}
	
