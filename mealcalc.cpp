// File: mealcalc.cpp
// Class: COP 2006, 202208, 80599
// Who: Christopher Smith
// Desc.: Calculate a meal with price, tax and tip using
//      console
// --------------------------------------------------------

#include <iostream> // Console I/O
#include <iomanip> // Formatting floating point

// Constants
// --------------------------------------------------------
const float SALES_TAX_RATE = 0.065;

/**
 * main application starting point
 * @return integer (0=SUCCESS)
 */

int main(){

    // Prompt user for a meal ticket price
    float mealPrice = 0.0; // Copy Assign
    std::cout << "Enter Price: ";
    std::cin >> mealPrice;

    std::cout << std::fixed << std::setprecision(2);

    float salesTax = mealPrice * SALES_TAX_RATE;
    std::cout << "Tax: " << salesTax << std::endl;

    float subtotal = mealPrice + salesTax;
    std::cout << "Subtotal: " << subtotal << std::endl;

    float tipPercent = 0.0;
    std::cout << "Enter tip percentage (20)%: ";
    std::cin >> tipPercent;

    float tip = subtotal * (tipPercent / 100.0f);
    std::cout << "Tip: " << tip << std::endl;

    float total = subtotal + tip;
    std:: cout << "Total: " << total << std::endl;

    char tmp;
    std::cin >> tmp;

    return 0;
} // End main