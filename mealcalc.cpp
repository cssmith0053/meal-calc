// What: Project 5 - Meal Calculator
// Class: COP 3003
// Who: Christopher Smith & Angel Vera
// Desc.: Calculate the total cost, tax, and tip associated
// with a meal and be able to split it
// ---------------------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

class MealCalculator {
    private:
        float basePrice, tipPercentage, taxRate;
        
    public:
        MealCalculator() : basePrice(0.0), tipPercentage(0.0), taxRate(0.0) {
        }
        
        void setPrice(float p) {
            while (p < 0) {
                try {
                    if (p < 0) {
                        throw 1;
                    }
                } catch (int e) {
                    cout << "The price of the meal cannot be negative, please try again (ERROR NUMBER: " 
                    << e << ")" << endl;
                    cout << "$";
                    cin >> p;
                }
            }
            basePrice = p;
        }
        void setTip(float t) {
            while (t < 0) {
                try {
                    if (t < 0) {
                        throw 2;
                    }
                } catch (int e) {
                    cout << "The percent of tip cannot be negative, please try again (ERROR NUMBER: "
                    << e << ")" << endl;
                    cin >> t;
                }
            }
            tipPercentage = t;
        }
        void setTax(float u) {
            while (u < 0 || u > 100) {
                try {
                    if (u < 0 || u > 100) {
                        throw 3;
                    }
                } catch (int e) {
                    cout << "The percent of tip cannot be negative or greater than 100%, "
                    << "please try again (ERROR NUMBER: "
                    << e << ")" << endl;
                    cin >> taxRate;
                }
            }
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
    float price{0.0}, tip{0.0}, tax{0.0};
    int numberOfPeople;
    MealCalculator meal;

    cout << setw(55) << "Welcome to the Meal Calculator!" << endl;

    cout << "Enter the price of the meal: $";
    cin >> price;
    meal.setPrice(price);
    cout << "Enter the percent of tip: ";
    cin >> tip;
    meal.setTip(tip);
    cout << "Enter the sale tax rate of the state or county if they differ: ";
    cin >> tax;
    meal.setTax(tax);
    
    cout << "Will the check be split (if not, enter 1), and if so, among how many people: ";
    cin >> numberOfPeople;

    cout << fixed << setprecision(2);
    cout << "\nTip amount: $" << meal.calculateTip() / numberOfPeople << endl;
    cout << "Tax amount: $" << meal.calculateTax() / numberOfPeople << endl;
    cout << "Total cost of the meal: $" << meal.calculateTotalCost() / numberOfPeople << endl;
    
    return 0;
}
