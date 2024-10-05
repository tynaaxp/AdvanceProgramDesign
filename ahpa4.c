#include <stdio.h>
#include <string.h>

void calculateBills(int amount) {
    if (amount <= 0) {
        printf("No valid amount entered.\n");
        return;
    }

    int hundred = amount / 100;
    amount %= 100;
    int fifty = amount / 50;
    amount %= 50;
    int twenty = amount / 20;
    amount %= 20;
    int ten = amount / 10;
    amount %= 10;
    int five = amount / 5;
    amount %= 5;
    int one = amount;

    // Print $100 bills
    for (int i = 0; i < hundred; i++) {
        printf("$100 bill\n");
    }

    // Print $50 bills
    for (int i = 0; i < fifty; i++) {
        printf("$50 bill\n");
    }

    // Print $20 bills
    for (int i = 0; i < twenty; i++) {
        printf("$20 bill\n");
    }

    // Print $10 bills
    for (int i = 0; i < ten; i++) {
        printf("$10 bill\n");
    }

    // Print $5 bills
    for (int i = 0; i < five; i++) {
        printf("$5 bill\n");
    }

    // Print $1 bills
    for (int i = 0; i < one; i++) {
        printf("$1 bill\n");
    }
}

int main() {
    int accounts[2][2] = {{500, 1000}, {750, 325}}; // a: {checking, savings}, b: {checking, savings}
    char name[10];
    char accountType;
    int person, accountIndex, amount;

    printf("Enter your name (a or b):\n");
    scanf("%s", name);

    if (strcmp(name, "a") == 0) {
        person = 0;
    } else if (strcmp(name, "b") == 0) {
        person = 1;
    } else {
        printf("Invalid name.\n");
        return 1;
    }

    printf("Would you like to withdraw from (c)hecking or (s)avings?\n");
    scanf(" %c", &accountType);

    if (accountType == 'c') {
        accountIndex = 0;
    } else if (accountType == 's') {
        accountIndex = 1;
    } else {
        printf("Invalid account type.\n");
        return 1;
    }


    printf("How much would you like to withdraw?\n");
    scanf("%d", &amount);

// Display the account balance before withdrawal
    printf("Amount in account to be withdrawn from: $%d\n", accounts[person][accountIndex]);
        printf("You will receive the following bills:\n");
        calculateBills(amount);
        
        if (amount > accounts[person][accountIndex]) {
        printf("Insufficient funds.\n");
        return 1;
    } else {
        accounts[person][accountIndex] -= amount;
        printf("Withdrawal successful. Amount in account after withdrawal: $%d\n", accounts[person][accountIndex]);

    }

    return 0;
}
