#include <stdio.h>

void largest(void);
void smallest(void);
void swapFirstLast(void);
void palindrome(void);

void largest(void)
{
    long long n;
    int c[10] = {0};
    int i;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    while (n > 0) {
        c[n % 10]++;
        n /= 10;
    }

    printf("Largest possible number: ");
    for (i = 9; i >= 0; i--) {
        while (c[i] > 0) {
            printf("%d", i);
            c[i]--;
        }
    }
    printf("\n");
}

void smallest(void)
{
    long long n;
    int c[10] = {0};
    int i;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    while (n > 0) {
        c[n % 10]++;
        n /= 10;
    }

    printf("Smallest possible number: ");
    for (i = 1; i <= 9; i++) {
        if (c[i] > 0) {
            printf("%d", i);
            c[i]--;
            break;
        }
    }
    while (c[0] > 0) {
        printf("0");
        c[0]--;
    }
    for (i = 1; i <= 9; i++) {
        while (c[i] > 0) {
            printf("%d", i);
            c[i]--;
        }
    }
    printf("\n");
}

void swapFirstLast(void)
{
    long long n, temp, place = 1;
    long long first, last, middle, result;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    if (n < 10) {
        printf("After swapping: %lld\n", n);
        return;
    }

    temp = n;
    while (temp >= 10) {
        temp /= 10;
        place *= 10;
    }

    first = n / place;
    last = n % 10;
    middle = (n % place) / 10;
    result = last * place + middle * 10 + first;

    printf("After swapping: %lld\n", result);
}

void palindrome(void)
{
    long long n, temp, reverse = 0;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);
    temp = n;

    while (temp > 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }

    if (reverse == n)
        printf("%lld is a palindrome number.\n", n);
    else
        printf("%lld is not a palindrome number.\n", n);
}

int main(void)
{
    int choice;

    printf("\n--- DIGIT OPERATIONS MENU ---\n");
    printf("1. Generate largest possible number\n");
    printf("2. Generate smallest possible number\n");
    printf("3. Swap first and last digits\n");
    printf("4. Check palindrome\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: largest(); break;
        case 2: smallest(); break;
        case 3: swapFirstLast(); break;
        case 4: palindrome(); break;
        default: printf("Invalid choice.\n");
    }
    return 0;
}
