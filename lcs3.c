#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int max(int a, int b, int c){
	int max = a;
	if(b >= max){
		max = b;
	}
	if(c >= max){
		max = c;
	}
	return max;
}

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	//Same as for 2 lists but using a 3D array instead
	int lcs[n+1][m+1][l+1];

	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < m+1; j++){
			for(int k = 0; k < l+1; k++){
				if(i == 0 || j == 0 || k == 0){
					lcs[i][j][k] = 0;
				}
				else if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				}
				else{
					lcs[i][j][k] = max(lcs[i-1][j][k], lcs[i][j-1][k], lcs[i][j][k-1]);
				}
			}
		}
	}
	return lcs[n][m][l];
}

int main() {
	int n, m, l;

	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);

	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}

	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}

	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array c:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}

	printf("Input sequences are:\n");
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);

	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);

	return 0;
}
