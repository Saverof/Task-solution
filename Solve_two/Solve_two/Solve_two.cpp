﻿#include <iostream>
#include <stack>

using namespace std;

// Функция вывода результата
bool result(const string &str, bool state)
{
    if (state)
        cout << str << " - правильная скобочная последовательность\n";
    else
        cout << str << " - неправильная скобочная последовательность\n";

    return 0;
}

// Функция обработки строки
bool bracket_check(const string &str)
{
    bool state = true;      // Отображает правильно ли выражение
    int bracket_open = 0;   // Количество открытых скобок

    for (int i = 0; i < str.size(); i++)
    {
        switch (str[i])
        {
        case '(':
            if (i != 0) // Если мы находимся в первом символе то пропускаем этот шаг
            {
                if (str[i - 1] == '(') // Если предыдущая скобка была открывающей, увеличиваем счетчик открытых скобок
                    bracket_open++;
                else if (str[i - 1] != '(' && str[i] == '(') // Иначе если предыдущая скобка НЕ была открывающей, а текущая является открывающей
                {
                    if (bracket_open < 0) // И если число закрывающих скобок меньше числа открывающих 
                        state = false; // Получаем, что последовательность заведомо неправильная 
                    else
                        bracket_open++; // Иначе увеличиваем число открывающих скобок
                }
            }else
                bracket_open++; // И увеличиваем число открывающих скобок
            break;
        case ')':
            bracket_open--;
            break;
        default:
            break;
        }  
    }

    // Проверяем соотвествуют ли полученные данные требуемым
    if (bracket_open != 0)
        state = false;

    // Выводим результат
    result(str, state);
    return 0;
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    
    // Тестовые комбинации 
    bracket_check("((x * y) + (2 * (x + y))) * (y + 3)");
    bracket_check("((((x * y) + (2 * (x - y)))");
    bracket_check(")(");
    bracket_check("())(())");
    bracket_check(")(())(");
    bracket_check("(()())");

    return 0;
}

