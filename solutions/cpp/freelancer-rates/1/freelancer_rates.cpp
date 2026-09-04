// INFO: Headers from the standard library should be inserted at the top via
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    // TO DO: Implement a function to calculate the daily rate given an hourly 
    double billableHours = 8.0; 
    return hourly_rate * billableHours;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    // TODO: Implement a function to calculate the price after a discount.
    double discountedPrice = before_discount * (1 - (discount/100));
    return discountedPrice;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    // TODO: Implement a function to calculate the monthly rate, and apply a
    // discount.
    double billableDays = 22;
    double finalTotal = apply_discount(daily_rate(hourly_rate) * billableDays, discount);
    return std::ceil(finalTotal);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // TODO: Implement a function that takes a budget, an hourly rate, and a
    // discount, and calculates how many complete days of work that covers.
    double discountedDailyRate = apply_discount(daily_rate(hourly_rate), discount);
    double daysCovered = budget / discountedDailyRate;
    double daysInBudget = std::floor(daysCovered);
    return daysInBudget;
}
