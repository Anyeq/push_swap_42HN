#include "merge_sort.h"
#include <stdio.h>

int	main(void)
{
	int	arr[20] = {8, 2, 4, 1, 10, -12, 500, -500, 7, 10, 12, 25, 73, 91, 31, 26, 81, 19, -1, 0};
	merge_sort(arr, 0, 20);
	int	i = 0;
	while (i < 20)
		printf("%d\n", arr[i++]);
	return (0);
}
