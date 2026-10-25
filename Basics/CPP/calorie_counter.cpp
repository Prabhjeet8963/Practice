#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<string, double> caloric_values = {
    {"rice", 130},
    {"rajma", 337},
    {"salad", 17},
    {"raita", 60},
    {"aloo_baigan", 100},
    {"roti", 70}
};

int main() {
    double total_calories = 0;
    string food_item;
    double quantity;

    while (true) {
        cout << "Enter food item (or 'done' to finish): ";
        cin >> food_item;
        if (food_item == "done") {
            break;
        }
        if (caloric_values.find(food_item) == caloric_values.end()) {
            cout << "Caloric value for " << food_item << " not found." << endl;
            continue;
        }
        cout << "Enter quantity of " << food_item << " consumed: ";
        cin >> quantity;
        total_calories += caloric_values[food_item] * quantity;
    }

    cout << "Total caloric intake: " << total_calories << " calories" << endl;

    return 0;
}
