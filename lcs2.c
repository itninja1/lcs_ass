#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int max(int a, int b){
	if (a >= b){
		return a;
	}
	return b;
}


int lcs2(int *a, int n,  int *b, int m) {
	//First create the dynamic table as a 2D array. It's n+1 and m+1 because  I'm including the empty arrays as subproblems.
	int lcs[n+1][m+1];

	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < m+1; j++){
			if(i == 0 || j == 0){
				lcs[i][j] = 0;
				printf("%d ", lcs[i][j]);
			}
			else if(a[i-1] == b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1; //The length of the longest subsequence is just one plus the longest subsequence without including the two last elements
				printf("%d ", lcs[i][j]);
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				printf("%d ", lcs[i][j]);
			}
		}
		printf("\n");
	}
	//write your code here
	return lcs[n][m];
}

int main() {
	int n, m;

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

	printf("Input sequences are:\n");
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);

	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);

	return 0;
}
