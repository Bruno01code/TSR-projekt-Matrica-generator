#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int matrix[10][10];
void  Nulmatrica(int red) {
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < red; j++) {
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < red; i++) {
		printf("\n");
		for (int j = 0; j < red; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

}
void  Dijagonalna(int red) {
	int a = -1;
	for (int i = 0; i < red; i++) {
		a++;
		for (int j = 0; j < red; j++) {
			if (j == a) {
				matrix[i][j] = rand() % 10;
			}
			else {
				matrix[i][j] = 0;
			}
			
		}
	}
	for (int i = 0; i < red; i++) {
		printf("\n");
		for (int j = 0; j < red; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

}
void  Jedinicna(int red) {
	int a = -1;
	for (int i = 0; i < red; i++) {
		a++;
		for (int j = 0; j < red; j++) {
			if (j == a) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}

		}
	}
	for (int i = 0; i < red; i++) {
		printf("\n");
		for (int j = 0; j < red; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

}
void  GornjeTrok(int red) {
	int a = -1;
	for (int i = 0; i < red; i++) {
		a++;
		for (int j = 0; j < red; j++) {
			while (j < a) {
				matrix[i][j] = 0;
				j++;
			}
			matrix[i][j] = rand() % 10;
			

		}
	}
	for (int i = 0; i < red; i++) {
		printf("\n");
		for (int j = 0; j < red; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

}
void  DoljnjeTrok(int red) {
	int a = -1;
	for (int i = 0; i < red; i++) {
		a++;
		for (int j = 0; j < red; j++) {
			while (j < a) {
				matrix[i][j] = rand() % 10;
				j++;
			}
			matrix[i][j] = 0;

		}
	}
	for (int i = 0; i < red; i++) {
		printf("\n");
		for (int j = 0; j < red; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

}
void  Simetricna(int red) {
	int a = -1;
	int temp;
	for (int i = 0; i < red; i++) {
		a++;
		for (int j = 0; j < red; j++) {
			while (j < a) {
				matrix[i][j] = 0;
				j++;
			}
			matrix[i][j] = rand() % 10;


		}
	}
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < red; j++) {
			temp = matrix[i][j];
			matrix[j][i] = temp;
		}
	}
	for (int i = 0; i < red; i++) {
		printf("\n");
		for (int j = 0; j < red; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

}
void  Antisimetricna(int red) {
	int a = -1;
	int temp;
	for (int i = 0; i < red; i++) {
		a++;
		for (int j = 0; j < red; j++) {
			while (j < a) {
				matrix[i][j] = 0;
				j++;
			}
			matrix[i][j] = rand() % 10;


		}
	}
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < red; j++) {
			temp = matrix[i][j];
			matrix[j][i] = temp * -1;
		}
	}
	for (int i = 0; i < red; i++) {
		matrix[i][i] = 0;
	}
	for (int i = 0; i < red; i++) {
		printf("\n");
		for (int j = 0; j < red; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

}
int DohvatiElement(int i, int j) {
	return matrix[i][j];
}
void GenerirajMatricu(int red, int vrsta) {
	switch (vrsta) {
	case 1:
		Nulmatrica(red);
		break;
	case 2:
		Dijagonalna(red);
		break;
	case 3:
		Jedinicna(red);
		break;
	case 4:
		GornjeTrok(red);
		break;
	case 5:
		DoljnjeTrok(red);
		break;
	case 6:
		Simetricna(red);
		break;
	case 7:
		Antisimetricna(red);
		break;
	}
}
int main() {
	srand(time(NULL));
	return 0;
}