﻿// HelloWorld.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

const double InflateRate = 9;  // ставка инфляции в %
const double SalaryIncrease = 9;  // ставка повышения з/п в %

// ставки для подсчетов
const double RealInflateRate = 1 + InflateRate / 100;
const double RealSalaryIncrease = 1 + SalaryIncrease / 100;

struct Bob
{
    double Deposit;      // сумма вклада
    double DepositRate; // ставка вклада(в %)
    double RentAMonth;  // стоимость аренды
    double SalaryAMonth; // зарплата
    int YearCount;
};

double Calculation_Bob(Bob Data)      // сумма вклада
{
    double Result = 0;

    // ставка деозита для подсчета
    double RealDepositRate = 1 + Data.DepositRate / 100;

    // сумма депозита после нескольких лет
    Data.Deposit *= pow(RealDepositRate, Data.YearCount);


    for (int Year = 1; Year <= Data.YearCount; Year++)
    {
        Result += (Data.SalaryAMonth - Data.RentAMonth) * 12;  // зарплата - аренда

        Data.SalaryAMonth *= RealSalaryIncrease; // повышение зарплаты
        Data.RentAMonth *= RealInflateRate; // повышение стоимости аренды
    }

    return Result + Data.Deposit;
}

double Alice(double FirstPay, // сумма первого взноса
    double Credit,      // сумма кредита
    double CreditRate, // ставка кредита(в %)
    double SalaryAMonth, // зарлплата
    int YearCount)
{
    double Result = 0;

    // ежемесячная ставка
    double RealCreditRate = CreditRate / 12 / 100; // теперь НЕ в процентах
    // формула расчета "общей ставки"
    double GeneralCreditRate = pow(1 + CreditRate, YearCount * 12);
    // платеж в месяц
    double PaymentAMonth = Credit * RealCreditRate * GeneralCreditRate / (GeneralCreditRate - 1);
    
    for (int Year = 1; Year <= YearCount; Year++)
    {
        Result += (SalaryAMonth - PaymentAMonth) * 12;  // зарплата - ежемесячный платеж

        SalaryAMonth *= RealSalaryIncrease; // повышение зарплаты
    }

    return Result - FirstPay;
}

int main()
{
    Bob DataForBob = {.Deposit=1000000,20,30000,200000,30 };

    //printf("Итог Боба:%.2f", Calculation_Bob(1000000, 20, 30000, 200000, 30));
    printf("Итог Боба:%.2f", Calculation_Bob(DataForBob);
    printf("Итог Алисы:%.2f:", Alice(1000, 13000000, 17, 200000, 30));
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
