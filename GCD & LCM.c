#include <stdio.h>

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Function to calculate LCM (Least Common Multiple)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculate GCD and LCM
    int result_gcd = gcd(num1, num2);
    int result_lcm = lcm(num1, num2);

    // Display the results
    printf("GCD of %d and %d is: %d\n", num1, num2, result_gcd);
    printf("LCM of %d and %d is: %d\n", num1, num2, result_lcm);

    return 0;
}
