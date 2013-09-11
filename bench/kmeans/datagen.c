#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	/* type, row number, column number, low bound, up bound, cluster number */
	
	if(argc != 7) {
		printf("please enter type(int, float), row number, column number, low bound, up bound, cluster number\n");
		return 0;
	}	

	int i;
	int j;	
	int row_num;
	int col_num;
	int cluster_num;
	time_t t;

	row_num = atoi(argv[2]);
	col_num = atoi(argv[3]);
	cluster_num = atoi(argv[6]);

	srand((unsigned) time(&t));

	if(strcmp(argv[1], "int") == 0) {
		int low_bound;
		int up_bound;
		low_bound = atoi(argv[4]);
		up_bound = atoi(argv[5]);

		for(i = 0; i < row_num; i++) {
			for(j=0; j < col_num; j++) {
				printf("%d ", rand() % (up_bound - low_bound + 1) + low_bound);
			}
			printf("\n");
		}
	}
	if(strcmp(argv[1], "float") == 0) {
		float low_bound;
		float up_bound;
		low_bound = atof(argv[4]);
		up_bound = atof(argv[5]);

		int _low_bound = low_bound * pow(10, 6);
		int _up_bound = up_bound * pow(10, 6);

		for(i = 0; i < row_num; i++) {
			for(j = 0; j < col_num; j++) {
				printf("%f ", (rand() % (_up_bound - _low_bound +1) + _low_bound) / pow(10, 6));
			}
			printf("\n");
		}

	}

	return 0;
}
