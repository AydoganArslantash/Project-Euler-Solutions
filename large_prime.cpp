#include <iostream>
#include <cmath>

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i <= std::sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

// Returns one non-trivial factor of N, or N if prime
long long fermat(long long N) {
    if (N % 2 == 0) return 2;
    if (isPrime(N)) return N;

    long long a = (long long)std::ceil(std::sqrt((double)N));
    long long b2 = a * a - N;
    long long b = (long long)std::sqrt((double)b2);

    while (b * b != b2) {
        a++;
        b2 = a * a - N;
        b = (long long)std::sqrt((double)b2);
    }
    return a - b;  // one factor
}

long long largestPrimeFactor(long long N) {
    if (isPrime(N)) return N;

    long long factor = fermat(N);
    long long other = N / factor;

    return std::max(largestPrimeFactor(factor), largestPrimeFactor(other));
}

int main() {
    long long N;
    std::cout << "N: ";
    std::cin >> N;

    // Handle even numbers first
    long long largest = 1;
    while (N % 2 == 0) {
        largest = 2;
        N /= 2;
    }

    if (N > 1)
        largest = std::max(largest, largestPrimeFactor(N));

    std::cout << largest << std::endl;
    return 0;
}
