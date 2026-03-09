/*
 * Project Euler Problem 6: Sum Square Difference
 Description:
 The sum of the squares of the first ten natural numbers is,
    1^2 + 2^2 + ... + 10^2 = 385.

	The square of the sum of the first ten natural numbers is,
	(1 + 2 + ... + 10)^2 = 55^2 = 3025.

	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the su is 3025 - 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <numeric>
#include <cmath>

int main()
{
	int sum1, sum2, result;

	int accumulator1 = 0;
	int accumulator2 = 0;
	for (int i = 1; i <= 100; i++) // for sum of squares
	{
		accumulator1 += std::pow(i,2);
		sum1 = accumulator1;
	}

	for (int i = 1; i <= 100; i++)
	{
		accumulator2 += i;

		if (i == 100)
		{
			sum2 = accumulator2 * accumulator2;
		}
	}

	result = sum2 - sum1;
	std::cout << result;
	return 0;
}
