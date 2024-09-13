#include "stdafx.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL," Rus");
	int* a;
	int n;
	int max = 100,min=-100;
	printf("¬ведите желаемую длину массива \n");
	scanf_s("%d",&n);
	a = (int*)malloc(n * sizeof(int));
	for (int i=0; i<n; i++) 
	{
		a[i] = min+rand()%(max-min+1);
		printf("%d, ",a[i]);
	}

	getchar();
	getchar();

}
