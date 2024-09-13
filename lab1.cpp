// lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int min = -100, max = 100;
	int a[10], i, k, n;
	srand(time(NULL));
	for (i=0; i<10; i++) 
	{
		a[i] = min+rand()%(max-min+1);
		printf("%d, ",a[i]);
	}
	max = a[0];
	min = a[0];
	for(i=0; i<10;i++)
	{
		if(max< a[i])
		{
			max = a[i];
		}
		if(min>a[i])
		{
			min = a[i];
		}
		
	}
	printf("\n%d",max);
	printf("\n%d",min);
	printf("\n%d",max-min);
	getchar();

}

