#include <cstdio>
#define ARR_SIZE 1001
//Longest increasing subsequence
int main()
{
	int arr[ARR_SIZE] = {0,};
	int d[ARR_SIZE] = {0, };
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &arr[i]);
	}
	d[1] = arr[1];
	for (int i = 1; i < ARR_SIZE; i++)
	{
		d[i] = arr[i];
		for (int j = i-1; j > 0; j--)
		{
			if (arr[i] > arr[j] && d[i] < d[j])
			{
				d[i] = d[j] + arr[i];
			}
		}
	}

	int answer = 0;
	for (size_t i = 1; i <= t; i++)
	{
		//printf("%d ", d[i]);
		if (d[i] > answer)
			answer = d[i];
	}
	printf("%d\n", answer);
	return 0;
}
