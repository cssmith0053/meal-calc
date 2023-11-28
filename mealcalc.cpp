// What: Project 5 - Meal Calculator
// Class: COP 3003
// Who: Christopher Smith & Angel Vera
// Desc.: Calculate the total cost, tax, and tip associated
// with a meal and be able to split it
// --------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

class MealCalculator {
    private:
        float basePrice, tipPercentage, taxRate;
        
    public:
        MealCalculator() : basePrice(0.0f), tipPercentage(0.0f), taxRate(0.0f) {
        }
        
        void setPrice(float p) {
            basePrice = p;
        }
        void setTip(float t) {
            tipPercentage = t;
        }
        void setTax(float u) {
            taxRate = u;
        }
        
        float calculateTip() const {
            float tipAmount = basePrice * (tipPercentage / 100.0f);
            return tipAmount;
        }
        float calculateTax() const {
            float taxAmount = basePrice * (taxRate / 100.0f);
            return taxAmount;
        }
        float calculateTotalCost() const {
            return basePrice + calculateTip() + calculateTax();
        }
};

int main() {
    float price{0.0f}, tip{0.0f}, tax{0.0f};
    MealCalculator meal;

    cout << setw(40) << "Welcome to the Meal Calculator!" << endl;

    cout << "Enter the price of the meal: $";
    cin >> price;
    meal.setPrice(price);
    cout << "Enter the percent of tip: ";
    cin >> tip;
    meal.setTip(tip);
    cout << "Enter the sale tax rate of the state or county if they differ: ";
    cin >> tax;
    meal.setTax(tax);

    cout << fixed << setprecision(2);
    cout << "\nTip amount: $" << meal.calculateTip() << endl;
    cout << "Tax amount: $" << meal.calculateTax() << endl;
    cout << "Total cost of the meal: $" << meal.calculateTotalCost() << endl;
    
    return 0;
}
