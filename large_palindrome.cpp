/*
  Project Euler Problem 4: Largest Palindrome Product
  Description:
  <p>A palindromic number reads the same both ways. The largest palindrome made from the product of two $2$-digit numbers is $9009 = 91 \times 99$.</p>
<p>Find the largest palindrome made from the product of two $3$-digit numbers.</p>

Solution Idea:
Create two variables (each starting from 100) which will change their value so that we multiply all possible 3 digit numbers with each other and after each calculation, we will put the result into a vector called "results". At the end of calculations,we will traverse through the entire vector and we will check if that current position in the vector is palindrome. If so, we pick it as the largest palindrome and we will continue traversing and updating largest palindrome variable if needed.

EDIT: The code you are seeing below isn't the "codified" version of the solution idea on top of here. Because of the potential performance issues the code have been changed. Please read the blog post related to this problem to see the explanation for the code below if needed.
*/


#include <vector>
#include <iostream>

bool isPalindrome(int);

int main()
{
    int highestPalindrome = 0;

    for (int a = 100; a <= 999; a++)
    {
        for (int b = a; b <= 999; b++)
        {
            int temp = a * b;
            if (isPalindrome(temp) && temp > highestPalindrome)
            {
                highestPalindrome = temp;
            }
        }
    }

    std::cout << "Largest Palindrome Product is: " << highestPalindrome;
    return 0;
}
bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}
