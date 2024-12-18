#include <iostream>
#include <cstdlib> 
#include <vector>
#include <locale>
#include "polinom.h" 

using namespace std;

void ShowMenu() {
    cout << "1. Ввести новый полином" << '\n';
    cout << "2. Вывести все полиномы" << '\n';
    cout << "3. Сложить два полинома" << '\n';
    cout << "4. Вычесть два полинома" << '\n';
    cout << "5. Умножить полином на число" << '\n';
    cout << "6. Умножить два полинома" << '\n';
    cout << "7. Взять производную от полинома" << '\n';
    cout << "8. Вычислить значение полинома" << '\n';
    cout << "9. Выход" << '\n';
}

bool isValidIndex(size_t index, const vector<Polinom>& polynomials) {
    return index > 0 && index <= polynomials.size();
}

void WaitForKeyPress() {
    cout << "Нажмите Enter для продолжения...";
    cin.ignore();
    cin.get();
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Polinom> polynomials;
    int choice;

    do {
        system("cls");
        ShowMenu();
        cout << "Выберите опцию: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        system("cls");
        switch (choice) {
        case 1: {
            string polStr;
            cout << "Введите полином: ";
            cin.ignore();
            getline(cin, polStr);
            try {
                Polinom p(polStr);
                polynomials.push_back(p);
            }
            catch (const invalid_argument& e) {
                cout << "Ошибка: " << e.what() << '\n';
                WaitForKeyPress();
            }
            break;
        }
        case 2: {
            for (size_t i = 0; i < polynomials.size(); ++i) {
                cout << i + 1 << ". " << polynomials[i] << '\n';
            }
            WaitForKeyPress();
            break;
        }
        case 3: {
            size_t idx1, idx2;
            cout << "Введите номер первого полинома: ";
            cin >> idx1;
            cout << "Введите номер второго полинома: ";
            cin >> idx2;

            if (isValidIndex(idx1, polynomials) && isValidIndex(idx2, polynomials)) {
                Polinom result = polynomials[idx1 - 1] + polynomials[idx2 - 1];
                polynomials.push_back(result);
                cout << "Результат: " << result << '\n';
            }
            else {
                cout << "Некорректные номера полиномов!" << '\n';
            }
            WaitForKeyPress();
            break;
        }
        case 4: {
            size_t idx1, idx2;
            cout << "Введите номер первого полинома: ";
            cin >> idx1;
            cout << "Введите номер второго полинома: ";
            cin >> idx2;

            if (isValidIndex(idx1, polynomials) && isValidIndex(idx2, polynomials)) {
                Polinom result = polynomials[idx1 - 1] - polynomials[idx2 - 1];
                polynomials.push_back(result);
                cout << "Результат: " << result << '\n';
            }
            else {
                cout << "Некорректные номера полиномов!" << '\n';
            }
            WaitForKeyPress();
            break;
        }
        case 5: {
            size_t idx;
            double scalar;
            cout << "Введите номер полинома: ";
            cin >> idx;
            cout << "Введите число: ";
            cin >> scalar;

            if (isValidIndex(idx, polynomials)) {
                Polinom result = polynomials[idx - 1] * scalar;
                polynomials.push_back(result);
                cout << "Результат: " << result << '\n';
            }
            else {
                cout << "Некорректный номер полинома!" << '\n';
            }
            WaitForKeyPress();
            break;
        }
        case 6: {
            size_t idx1, idx2;
            cout << "Введите номер первого полинома: ";
            cin >> idx1;
            cout << "Введите номер второго полинома: ";
            cin >> idx2;

            if (isValidIndex(idx1, polynomials) && isValidIndex(idx2, polynomials)) {
                Polinom result = polynomials[idx1 - 1] * polynomials[idx2 - 1];
                polynomials.push_back(result);
                cout << "Результат: " << result << '\n';
            }
            else {
                cout << "Некорректные номера полиномов!" << '\n';
            }
            break;
        }
        case 7: {
            size_t idx;
            char variable;
            cout << "Введите номер полинома: ";
            cin >> idx;
            cout << "Введите переменную для взятия производной (x, y или z): ";
            cin >> variable;

            if (variable != 'x' && variable != 'y' && variable != 'z') {
                cout << "Некорректная переменная!" << '\n';
            }

            if (isValidIndex(idx, polynomials)) {
                Polinom result = polynomials[idx - 1].derivative(variable);
                polynomials.push_back(result);
                cout << "Результат: " << result << '\n';
            }
            else {
                cout << "Некорректный номер полинома!" << '\n';
            }
            WaitForKeyPress();
            break;
        }
        case 8: {
            size_t idx;
            double x, y, z;
            cout << "Введите номер полинома: ";
            cin >> idx;
            cout << "Введите значение x: ";
            cin >> x;
            cout << "Введите значение y: ";
            cin >> y;
            cout << "Введите значение z: ";
            cin >> z;

            if (isValidIndex(idx, polynomials)) {
                double result = polynomials[idx - 1].calculate(x, y, z);
                cout << "Результат: " << result << '\n';
            }
            else {
                cout << "Некорректный номер полинома!" << '\n';
            }
            WaitForKeyPress();
            break;
        }
        case 9: {
            cout << "Выход..." << '\n';
            break;
        }
        default: {
            cin.ignore();
            cout << "Некорректный выбор! Пожалуйста, попробуйте снова." << '\n';
            cin.get();
            WaitForKeyPress();
        }
        }

    } while (choice != 9);

    return 0;
}

