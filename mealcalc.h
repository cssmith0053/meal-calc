#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <stdexcept>

using namespace std;

class MealCalculator
{
private:
    float basePrice, tipPercentage, taxRate;

public:
    MealCalculator() : basePrice(0.0), tipPercentage(0.0), taxRate(0.0) {}

    void setBasePrice(float p);
    void setTipPercentage(float t);
    void setTaxRate(float u);

    float getBasePrice() const { return basePrice; }
    float getTipPercentage() const { return tipPercentage; }
    float getTaxRate() const { return taxRate; }

    float calculateTipAmount() const;
    float calculateTaxAmount() const;
    float calculateTotalCost() const;
};

void MealCalculator::setBasePrice(float p)
{
  while (p < 0)
    {
        cerr << "The tip percentage cannot be negative, please try again: ";
        cin >> p;
    };
    basePrice = p;
}

void MealCalculator::setTipPercentage(float t)
{
  while (t < 0)
    {
        cerr << "The tip percentage cannot be negative, please try again: ";
        cin >> t;
    };
    tipPercentage = t;
}

void MealCalculator::setTaxRate(float u)
{
   while (u < 0 || u > 100)
    {
        cerr << "The tax rate must be between 0 and 100%, please try again: ";
        cin >> u;
    };
    taxRate = u;
}

float MealCalculator::calculateTipAmount() const
{
    return basePrice * (tipPercentage / 100.0f);
}

float MealCalculator::calculateTaxAmount() const
{
    return basePrice * (taxRate / 100.0f);
}

float MealCalculator::calculateTotalCost() const
{
    return basePrice + calculateTipAmount() + calculateTaxAmount();
}

#endif
