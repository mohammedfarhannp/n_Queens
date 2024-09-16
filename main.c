#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 25

int State_Tree[MAX_SIZE], Arrangements = 0;

void N_Queens(int);
void Print_Solution(int);

int Place(int);

int main(int argc, char* argv[])
{
	int n;
	printf("Input n: ");
	scanf("%d", &n);

	N_Queens(n);
	
	if (Arrangements == 0)
	{
		printf("Solution Doesn't Exist\n");
	}
	else {
		printf("%d Possible arrangements exist\n", Arrangements);
	}
	return 0;
}

void N_Queens(int Input)
{
	int Tracker = 1;
	State_Tree[Tracker] = 0;
	while (Tracker != 0)
	{
		do {
			State_Tree[Tracker]++;
		} while (State_Tree[Tracker] <= Input && !Place(Tracker));
		if (State_Tree[Tracker] <= Input)
		{
			if (Tracker == Input)
			{
				Print_Solution(Input);
			}
			else {
				Tracker++;
				State_Tree[Tracker] = 0;
			}
		}
		else {
			Tracker--;
		}
	}
}

int Place(int Index)
{
	for (int i = 1; i < Index; i++)
	{
		if (State_Tree[i] == State_Tree[Index] || abs(State_Tree[i] - State_Tree[Index]) == abs(i - Index))
		{
			return 0;
		}
	}
	return 1;
}

void Print_Solution(int limit)
{
	Arrangements++;
	printf("Arrangement #%d\n", Arrangements);
	for (int i = 1; i <= limit; i++)
	{
		for (int j = 1; j <= limit; j++)
		{
			if (State_Tree[i] == j)
			{
				printf("Q");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");
}

