#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int i) {
 
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;

    return isPrime(n, i + 1);
}

void printPrimes(int n, int i) {
    if (i <= n) {
        if (isPrime(i, 2))
            printf("%d ", i);
        printPrimes(n, i + 1);
    }
}

int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are:\n", limit);
    printPrimes(limit, 2); 

    printf("\n");

    return 0;
}

