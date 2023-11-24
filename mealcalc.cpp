#include <iostream>
#include <iomanip>

class MealCalculator {
private:
    float mealPrice;
    const float SALES_TAX_RATE = 0.065;

public:
    MealCalculator() : mealPrice(0.0) {}

    void setMealPrice(float price) {
        mealPrice = price;
    }

    void calculateTax() const {
        float salesTax = mealPrice * SALES_TAX_RATE;
        std::cout << "Tax: " << salesTax << std::endl;
    }

    void calculateSubtotal() const {
        float subtotal = mealPrice + (mealPrice * SALES_TAX_RATE);
        std::cout << "Subtotal: " << subtotal << std::endl;
    }

    void calculateTip(float tipPercent) const {
        float subtotal = mealPrice + (mealPrice * SALES_TAX_RATE);
        float tip = subtotal * (tipPercent / 100.0f);
        std::cout << "Tip: " << tip << std::endl;
    }

    void calculateTotal(float tipPercent) const {
        float subtotal = mealPrice + (mealPrice * SALES_TAX_RATE);
        float tip = subtotal * (tipPercent / 100.0f);
        float total = subtotal + tip;
        std::cout << "Total: " << total << std::endl;
    }
};

int main() {
    MealCalculator mealCalc;

    float mealPrice;
    std::cout << "Enter Price: ";
    std::cin >> mealPrice;
    mealCalc.setMealPrice(mealPrice);

    std::cout << std::fixed << std::setprecision(2);

    mealCalc.calculateTax();
    mealCalc.calculateSubtotal();

    float tipPercent;
    std::cout << "Enter tip percentage (20)%: ";
    std::cin >> tipPercent;

    mealCalc.calculateTip(tipPercent);
    mealCalc.calculateTotal(tipPercent);

    char tmp;
    std::cin >> tmp;

    return 0;
}
