/*
  Project Euler Problem 5: Smallest Multiple
  Description: 2050 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

  What is the smallest positive number that's *evenly divisible* by all of the numbers from 1 to 20?

  Solution Idea: Well, evenly divisible means 'divisible with no remainder' which prompts me to think about using modulo operator.

  So the idea first thing that comes to my mind is to find the number which has least common multiple of 20!. Important thing is to make sure its evenly divisible.

  I got also another idea. I will write a loop which will go from 1 to 20, which will do LCM and check for remainder with modulo operator which will basically do something.

  Another idea is, I found a thing that says gcd(a,b) x lcm(a,b) = ab maybe we can utilize it somehow??
*/

#include <iostream>
#include <numeric>

int main()
{

	long long result = 1;
	for (int i = 1 ; i <= 20; i++)
	{
        // we will use logic lcm(a, b, c) = lcm(lcm(a, b), c)
		// we have to populate 20 lcm's nested inside each other.
		result = std::lcm(result, i);
	}
	std::cout << result;
	return 0;
}
