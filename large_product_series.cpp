/*
  Project Euler Problem 8: Largest Product in a Series
  Description:
  The four adjacent digits in the 1000-digit number that have the greatest product are 9 x 9 x 8 x 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

Solution Idea:
So the idea is that we are going to write a loop with an counting iterator that  counts to 13, which will do multiplication of this 13 elements and store the values in an array/vector.

The algorithm will start from 1st to 13th element and get the product and insert it into array/vector. In the next iteration 2nd to 14th and so on. It will stop once the 13 number counting iterator is less than 13 which will mean we are going beyond the last digit.

In the end, we will search for the maximum value in results array/vector.

MODIFICATION:
So instead of storing the values in an vector, we can just a variable to hold the current highest result and update it if the new result is higher than that current result.
*/

#include <iostream>
#include <vector>
#include <fstream>

int main()
{

	std::ifstream file("euler1.txt");
	if (!file) {
		std::cout << "Something wrong with the file";
		return -1;
	}

	std::string digits;
	std::string line;
	while (std::getline(file, line)) {
		digits += line;  // concatenate all lines into one string
	}


	long long max_result;
	for (int i = 0; i <= (int)digits.size() - 13; i++)
	{
		long long curr_result = 1;
		for (int j = 0; j < 13; j++)
		{
			curr_result *= digits[i + j] - '0';
			if (curr_result > max_result)
				max_result = curr_result;
		}
	}

	std::cout << "Max Result: " << max_result;

	return 0;
}
