#include <stdio.h>
void displayMenu()
{
    printf("\n===== ATM Menu =====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("====================\n");
}

void checkBalance(float balance)
{
    printf("Your balance is: $%.2f\n", balance);
}

float deposit(float balance, float amount)
{
    balance += amount;
    printf("Deposit successful. Your new balance is: $%.2f\n", balance);
    return balance;
}

float withdraw(float balance, float amount)
{
    if (amount > balance)
    {
        printf("Insufficient funds\n");
    }
    else
    {
        balance -= amount;
        printf("Withdrawal successful. Your new balance is: $%.2f\n", balance);
    }
    return balance;
}

int main()
{
    float balance = 1000.0;
    int choice;
    float amount;

    do
    {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            printf("Enter the deposit amount: $");
            scanf("%f", &amount);
            balance = deposit(balance, amount);
            break;
        case 3:
            printf("Enter the withdrawal amount: $");
            scanf("%f", &amount);
            balance = withdraw(balance, amount);
            break;
        case 4:
            printf("Thank you for using the ATM. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
