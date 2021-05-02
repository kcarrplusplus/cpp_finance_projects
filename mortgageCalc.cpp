#include <iostream>
#include <cmath>
using namespace std;

double calculateMonthlyPayments(double principal, double rate, double months, double years) {
    // Payment Formula 
    // Payment = P x (r / n) x (1 + r / n)^n(t)] / (1 + r / n)^n(t) - 1
    // Formula source: https://www.thebalance.com/calculate-mortgage-315668
    
    double numerator = (principal * (rate / months) * pow((1 + rate / months), (months * years)) );
    double denominator = (pow((1 + rate / months), (months * years))) - 1;
    return  (numerator / denominator);
}

double calculateTotalCostOfMortgage(double monthlyPayments, double months, double years) {
    return monthlyPayments * (months * years);
}

int main() {

    double principal, months, rate, downPaymentPercentage, years;
    bool downPaymentPercentageEntered;
    months = 12;

    cout << "Please enter principal amount (ex: 330000.0)\n";
    cin >> principal;
    
    while (!downPaymentPercentageEntered) {
        cout << "Downpayment Percentage between 0% and 100%. Please enter between 0.0 and 1.0\n";
        cin >> downPaymentPercentage;
        if (downPaymentPercentage >= 0.0 && downPaymentPercentage <= 1.0)
            downPaymentPercentageEntered = true;
    }
    principal = principal - (principal * downPaymentPercentage);
    cout << "What interest rate? Please enter as decimal. 6% should be input as .06\n";
    cin >> rate;
    cout << "Finally, how many years is your mortgage: \n";
    cin >> years;

    double monthlyPayments = calculateMonthlyPayments(principal, rate, months, years);
    cout << "Monthly Payments: $" << monthlyPayments << "\n";
    cout << "Total Cost of Mortgage: $" << calculateTotalCostOfMortgage(monthlyPayments, months, years) << "\n";
    return 0;
}