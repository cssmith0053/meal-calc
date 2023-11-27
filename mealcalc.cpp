// File: mealcalc.cpp
// Class: COP 3003
// Who: Christopher Smith & Angel Vera
// Desc.: Calculate the total cost of a meal using price,
// tip, and tax
// --------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

class MealCost {
    private:
        float price, tip, tax;
    public:
        // Constructor to initialize the meal object with initial values
        MealCost(float oPrice, float oTip, float oTax)
        : price(oPrice), tip(oTip), tax(oTax) {
        }
        // Function to calculate the total cost of the meal
        float calculateTotalCost() const {
            float tipAmount = price * (tip / 100.0);
            float salesTax = price * (tax / 100.0);
            return price + tipAmount + salesTax;
        }
};

int main() {
    // Input variables
    float oPrice{0.0}, oTip{0.0}, oTax{0.0};

    // Get user input
    cout << "Enter the price of the meal: $";
    cin >> oPrice;

    cout << "Enter the percent of tip you'd like to leave: ";
    cin >> oTip;

    cout << "Enter the sales tax of the state you live in: ";
    cin >> oTax;
    
    // Create a MealCost object
    MealCost meal(oPrice, oTip, oTax);

    // Calculate and display the total cost
    cout << "\nTotal cost, including tip and sales tax: $" 
    << fixed << setprecision(2) 
    << meal.calculateTotalCost() << endl;

    return 0;
}
