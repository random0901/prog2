#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main() {
	int r, i, ans = 0;
	printf("Enter number of sections : ");
	scanf_s("%d", &r);
	int arr[50][50], size[50], sum[50] = { 0 };
	omp_set_num_threads(r);
#pragma omp parallel
	{
#pragma omp for
		for (i = 0; i < r; i++) {
			srand(i);
			int j;
			size[i] = rand() % 20;
			for (j = 0; j < size[i]; j++) {
				arr[i][j] = rand() % 100;
				sum[i] += arr[i][j];
			}
#pragma omp critical
			ans += sum[i];
		}
	}
	for (i = 0; i < r; i++) {
		printf("Section - %2d ( %3d Items ) : ", i, size[i]);
		for (int j = 0; j < size[i]; j++)
			printf("%3d ", arr[i][j]);
			printf("sum: %6d", sum[i]);
		printf("\n");
	}
	printf("Total Amount : %d", ans);
}