/*
---LARGE SUM---
Work out the first ten digits of the sum of the one hundred 50 digit numbers.

SOLVED BY: Aydo 
   */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  // For std::reverse

using namespace std;

// Function to add two large numbers represented as strings
string addLargeNumbers(const string &num1, const string &num2) {
    string result = "";
    int carry = 0;
    int len1 = num1.size();
    int len2 = num2.size();
    int maxLen = max(len1, len2);
    
    // Pad the shorter number with leading zeros
    string paddedNum1 = string(maxLen - len1, '0') + num1;
    string paddedNum2 = string(maxLen - len2, '0') + num2;
    
    // Add digits from right to left
    for (int i = maxLen - 1; i >= 0; --i) {
        int sum = (paddedNum1[i] - '0') + (paddedNum2[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    
    // Handle remaining carry
    if (carry) {
        result += carry + '0';
    }
    
    // Reverse the result back to normal order
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    ifstream inputFile("large_number.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    
    string number;
    string sum = "0";
    
    // Read each number from the file and add to the sum
    while (getline(inputFile, number)) {
        sum = addLargeNumbers(sum, number);
    }
    
    inputFile.close();
    
    // Output the first 10 digits of the sum
    string first10Digits = sum.substr(0, 10);
    
    cout << "The first 10 digits of the sum are: " << first10Digits << endl;

    return 0;
}

