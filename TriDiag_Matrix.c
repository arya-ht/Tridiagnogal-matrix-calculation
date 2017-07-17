#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4
#define N2 6

void makeMatrix1();
void makeMatrix2();
void printMatirx(double[], double[], double[], double[]);
void printMatirx2(double[], double[], double[], double[], double[]); // I could not figure out how to make this function work with any given array size

void makeMatrix1() {
	double matrix[N][N], alpha[N], f[N] = { 40.8,0.8,0.8,200.8 }, b[N], c[N], g[N], a[N], u[N];
	alpha[0] = 2.04, g[0] = 40.8;
	int i, j, k;
	for (int k = 0; k < N; k++) {
		c[k] = -1; b[k] = -1; a[k] = 2.04;
	}
	for (j = 1; j < N; j++) {
		alpha[j] = a[j] - (b[j - 1] * c[j - 1]) / alpha[j - 1];
		g[j] = f[j - 1] - (b[j - 1] / alpha[j - 1])*g[j - 1];
	}
	u[N - 1] = g[N - 1] / alpha[N - 1];
	for (j = 2; j >= 0; j--) {
		u[j] = (g[j] - (c[j] * u[j + 1])) / alpha[j];
	}
	const int size = N;
	printMatirx(f, u, a, b);
}

void makeMatrix2() {
	int i, j, k;

	double matrix[N2][N2], alpha[N2], g[N2], u[N2],
		f[N2] = { 1,3,4,25,235,23523 }, // you can input any value for f()
		a[N2] = { -3.48,2.48,1.48,1.48,2.48,3.48 },
		b[N2] = { -0.49,-0.49,-0.99,-1.99,-2.99 },
		c[N2] = { -2.99,-1.99,-0.99,-0.49,-0.49 };

	alpha[0] = a[0], g[0] = f[0];

	for (j = 1; j < N2; j++) {
		alpha[j] = a[j] - (b[j - 1] * c[j - 1]) / alpha[j - 1];
		g[j] = f[j - 1] - (b[j - 1] / alpha[j - 1])*g[j - 1];
	}

	u[N2 - 1] = g[N2 - 1] / alpha[N2 - 1];
	for (j = N2-1; j >= 0; j--) {
		u[j] = (g[j] - (c[j] * u[j + 1])) / alpha[j];
	}
	printMatirx2(f, u, a, b, c);
}
void printMatirx(double f[], double u[], double a[], double b[]) {
	int i, j, k;
	double matrix[N][N];
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == j) {
				matrix[i][j] = a[j];
			}
			else if (j == i - 1 || i == j - 1) {
				matrix[i][j] = b[j];
			}
			else {
				matrix[i][j] = 0;
			}
			printf("[%.2lf] ", matrix[i][j]);

		} printf("\n\n");
	}
	printf("\nX\n\n");

	for (k = 0; k < N; k++) {
		printf("[%lf]\n\n", u[k]);
	}
	printf("\n=\n\n");

	for (k = 0; k < N; k++) {
		printf("[%.1lf]\n\n", f[k]);
	}
	printf("\n=====================================================================\n");
}
void printMatirx2(double f[], double u[], double a[], double b[], double c[]) {
	int i, j, k;
	double matrix[N2][N2];
	for (i = 0; i < N2; i++) {
		for (j = 0; j < N2; j++) {
			if (i == j) {
				matrix[i][j] = a[j];
			}
			else if (j == i - 1) {
				matrix[i][j] = b[j];
			}
			else if (i == j - 1) {
				matrix[i][j] = c[j];
			}
			else {
				matrix[i][j] = 0;
			}
			printf("[%.2lf] ", matrix[i][j]);

		} printf("\n\n");
	}
	printf("\nX\n\n");
	for (k = 0; k < N2; k++) {
		printf("[%lf]\n\n", u[k]);
	}
	printf("\n=\n\n");
	for (k = 0; k < N2; k++) {
		printf("[%.2lf]\n\n", f[k]);
	}
}

int main(int argc, char *argv[]) {
	makeMatrix1();
	makeMatrix2();
	return 0;
}