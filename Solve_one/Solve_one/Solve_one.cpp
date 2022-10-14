#include <iostream>
#include <algorithm>

using namespace std;

string solve(string str, int max_size)
{
    // Удаляем все пробелы больше одного
   str.erase(unique_copy(str.begin(),str.end(),str.begin(), [](char ch1, char ch2) { return ch1 == ' ' && ch2 == ' '; }),str.end());

    // Проверяем чем является первый символ
    if (str.at(0) == ' ')
       str.erase(0, 1);

    // Проверяем чем является последний символ
    if (str.back() == ' ')
       str.pop_back();

    // Если размер больше максимального значения, уменьшаем размер
    if (str.size() > max_size)
    {
       str.erase(max_size, max_size +str.size());
       str.append("...");
    }

    return str;
}

int main()
{
    // Задаем исходные данные
    int m = 40;
    string text = "   Lorem   ipsum  dolor      sit  amet,    consectetuer adipiscing elit.       Maecenas porttitor congue   massa. Fusce posuere, magna sed  pulvinar ultricies, purus lectus malesuada libero, sit amet commodo magna eros quis     urna.      ";

    // Выводим исходную строку
    cout << text << '\n';
    // Выводим исправленную строку
    cout << endl << solve(text, m) << '\n';

    return 0;
}
