#include <iostream>

using namespace std;

int main(){
    double sales;
    double stateTax;
    double countryTax;
    cout << "Enter sales - State Tax - and Country Tax: ";
    cin >> sales >> stateTax >> countryTax;
    cout << "Sales = " << sales << endl
        << "State Tax = " << sales * stateTax << endl
        << "Country Tax = " << sales * countryTax << endl
        << "Profit = " << sales - (sales * countryTax + sales * stateTax) << endl;
    return 0;
}