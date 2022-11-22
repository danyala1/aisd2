#include <stdio.h>
#include <iostream>
#include "Header.h"

using namespace std;


double CheckDouble()
{
    double number = 0;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Input correct value" << endl;
    }
    return number;
}

int CheckChoise()
{
    int number = 0;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter a number" << endl;
    }
    return number;
}

int main() {
    try
    {
        double coefficent, degree;
        int choice;
        setlocale(LC_ALL, "RUS");
        cout << "��������� ���� �� ������, ������� ���������� ������� ��������: " << endl;
        coefficent = CheckDouble();
        cout << "������� ��� �������: " << endl;
        degree = CheckDouble();
        Equalization A(coefficent, degree);
        bool flag = true;
        while (flag) {
            A.DeleteElement(0);
            cout << A;
            cout << "�������� ��������:\n1)�������� ����� �������\n2)�������� �� ������\n3)��������� �\n4)����� �����������\n5)����� � ������ �����������\n6)������� �� ���� ������ ���������\n7)��������������� ����������\n8)������� �������\n9)�����\n";
            choice = CheckChoise();
            if (choice == 1)
            {
                cout << "������� ���������� ������ ��������: " << endl;
                coefficent = CheckDouble();
                cout << "������� ��� �������: " << endl;
                degree = CheckDouble();
                A.Set(coefficent, degree);
            }
            else if (choice == 2) {
                cout << "������� �������� �� ������� ������ ��������: " << endl;
                degree = CheckDouble();
                A.Multiplication(degree);
            }
            else if (choice == 3) {
                cout << "������� �������� �: " << endl;
                degree = CheckDouble();
                A.Calculation(degree);
            }
            else if (choice == 4) {
                A.Derivative();
            }
            else if (choice == 5 || choice == 6) {
                bool SumOperation = false;
                if (choice == 5) SumOperation = true;
                Equalization B(0, 0);
                do {
                    cout << "�������� ���������� �������� ������ ����������: ";
                    coefficent = CheckDouble();
                    cout << "�������� ������� �������� ������ ����������: ";
                    degree = CheckDouble();
                    B.Set(coefficent, degree);
                    cout << "�������� ��� ���� ������� � ����������? \n1)��\n2)���\n";
                    choice  = CheckChoise();
                } while (choice == 1);
                if (SumOperation) A + B;
                else A - B;
            }
            else if (choice == 7) {
                cout << "�������� ������� �������� ������� �����������: ";
                degree = CheckDouble();
                A[degree];
            }
            else if (choice == 8) {
                cout << "�������� ������� �������� ������� �������: ";
                degree = CheckDouble();
                if (A.DeleteElement(degree) == 0) cout << "��� ������ �������� :(" << endl;
            }
            else if (choice == 9) {
                flag = false;
            }
            else {
                system("CLS");
            }

        }
    }
    catch (EClassException& err)
    {
        err.Print();
    }
}
