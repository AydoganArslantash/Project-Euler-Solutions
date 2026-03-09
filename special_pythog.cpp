/*
  Project Euler Problem 9: Special Pythagorean Triplet
  Description:
  A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
  a^2 + b^2 = c^2.
  For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
  Find the product a x b x c.
*/
#include <iostream>

bool checkPyth(int, int, int);

int main()
{
    for (int a = 1; a < 1000; a++)
    {
        for (int b = a + 1; b < 1000; b++)
        {
            int c = 1000 - a - b;

            if (c > b && checkPyth(a, b, c))
            {
                std::cout << "a: " << a << ", b: " << b << ", c: " << c << "\n";
                std::cout << "a x b x c: " << a * b * c;
                return 0;
            }
        }
    }

    std::cout << "No triplet found.";
    return 0;
}

bool checkPyth(int a, int b, int c)
{
    if (a*a + b*b == c*c)
    {
        return true;
    }
    else
    {
        return false;
    }
}
