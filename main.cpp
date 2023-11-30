#include "mealcalc.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float price{0.0}, tip{0.0}, tax{0.0};
    int numberOfPeople = 0;

    MealCalculator meal;

    cout << setw(100) << "Welcome to the Meal Calculator!" << endl;

    cout << "Enter the base price of the meal: $";
    cin >> price;
    meal.setBasePrice(price);

    cout << "Enter the tip percentage: ";
    cin >> tip;
    meal.setTipPercentage(tip);

    cout << "Enter the tax rate of the state or county if they differ: ";
    cin >> tax;
    meal.setTaxRate(tax);

    cout << "Will the check be split among multiple people? If not, enter 1, and if so, enter how many people enter: ";
    cin >> numberOfPeople;

    cout << fixed << setprecision(2);
    cout << "\nTip amount per person: $" << meal.calculateTipAmount() / numberOfPeople << endl;
    cout << "Tax amount per person: $" << meal.calculateTaxAmount() / numberOfPeople << endl;
    cout << "Total cost per person: $" << meal.calculateTotalCost() / numberOfPeople << endl;

    return 0;
}
