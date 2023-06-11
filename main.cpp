#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double determineInterestRate(double principal) {
    if (principal < 10000000) {
        return 15.0;  // 15% interest rate for principal < N 10,000,000
    } else if (principal < 5000000) {
        return 10.5;  // 10.5% interest rate for principal < N 5,000,000
    } else if (principal < 1000000) {
        return 6.5;  // 6.5% interest rate for principal < N 1,000,000
    } else {
        return 4.0;  // 4% interest rate for principal >= N 1,000,000
    }
}

double calculateMonthlyPayment(double principal, double monthlyRate, int months) {
    double monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -months));
    return monthlyPayment;
}

int main() {
    string first_name;
    string last_name;
    int age;
    double principal;  // Loan principal amount
    double annualRate; // Annual interest rate
    int months;        // Loan duration in months

    cout << "\t\t\t\t\t\t\tGroup 3" << endl;
    cout << "\t\t\t\t\t\tWelcome to the ACU Loan" << endl;

    while (true) {
        cout << "Enter your First Name: ";
        cin >> first_name;
        cout << "Enter your Last Name: ";
        cin >> last_name;

        cout << "Please enter your age: ";
        cin >> age;

        if (age < 18) {
            cout << first_name << " " << last_name << "\n"
                 << "Sorry, you are too young to borrow." << endl;
            return 0;
        }

        while (true) {
            cout << "Enter the principal amount (between N 100,000 and N 10,000,000): N";
            cin >> principal;

            if (principal >= 100000 && principal <= 10000000) {
                break;
            } else {
                cout << "Invalid amount. Please enter an amount between N 100,000 and N 10,000,000." << endl;
            }
        }

        annualRate = determineInterestRate(principal);

        while (true) {
            cout << "Enter the loan duration in months: ";
            cin >> months;

            if (months > 0) {
                break;
            } else {
                cout << "Invalid loan duration. Please enter a positive value." << endl;
            }
        }

        // Calculate the monthly interest rate and the number of months
        double monthlyRate = annualRate / (12 * 100);

        // Calculate the monthly payment
        double monthlyPayment = calculateMonthlyPayment(principal, monthlyRate, months);

        // Calculate the total payment
        double totalPayment = monthlyPayment * months;

        cout << first_name << " " << last_name << " " << "Your Loan has been granted" << endl;
        cout << first_name << " " << last_name << " " << "You have received Payment of: N" << fixed << setprecision(2) << principal << endl;
        cout << "You have Total Payment of: N" << fixed << setprecision(2) << totalPayment << endl;

        double remainingBalance = totalPayment;

        while (remainingBalance > 0) {
            double repaymentAmount;
            cout << "Enter the desired repayment amount (N for full repayment): N";
            cin >> repaymentAmount;

            if (repaymentAmount > remainingBalance) {
                cout << "Sorry, the repayment amount is greater than the remaining balance." << endl;
                continue;
            }

            remainingBalance -= repaymentAmount;

            if (remainingBalance == 0.00) {
                cout << "Debt cleared." << endl;
                break;
            } else {
                cout << "Remaining Balance: N" << fixed << setprecision(2) << remainingBalance << endl;
                cout << "Do you want to repay more? (Y/N): ";
                char choice;
                cin >> choice;

                if (choice == 'N' || choice == 'n')
                    break;
            }
        }

        cout << "Do you want to borrow again? (Y/N): ";
        char choice;
        cin >> choice;
         if (choice == 'N' || choice == 'n')
            break;
    }

    return 0;
}
