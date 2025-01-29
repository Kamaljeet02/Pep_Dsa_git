#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Welcome to the Simple Calculator!" << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the operator (+, -, *, /, %): ";
    cin >> op;
    cout << "Enter the second number: ";
    cin >> num2;

    switch (op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;
            break;
        
        default:
            cout << "Error: Invalid operator!" << endl;
    }

    return 0;
}
