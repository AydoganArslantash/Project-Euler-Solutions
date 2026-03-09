/*
 * Project Euler Problem 7: 10001st Prime
 * Description:
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13. What is the 10001st prime number?
 *
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>

static const int TARGET = 10001;

int main()
{
    std::vector<int> primes;
    primes.push_back(2);

    int candidate = 3;
    while ((int)primes.size() < TARGET)
    {
        bool is_prime = true;
        int root = std::sqrt(candidate);

        for (int p : primes)
        {
            if (p > root) break;
            if (candidate % p == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            primes.push_back(candidate);

        candidate += 2;
    }

    std::cout << TARGET << "st prime: " << primes.back() << "\n";
    return 0;
}
