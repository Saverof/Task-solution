#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void solve(string& str, int max_size)
{
    // Уаляем все пробелы больше одного
    str.erase(unique_copy(str.begin(), str.end(), str.begin(), [](char ch1, char ch2) { return ch1 == ' ' && ch2 == ' '; }), str.end());

    // Проверяем чем является первый символ
    if (str.at(0) == ' ')
    {
        str.erase(0, 1);
    }

    // Если размер больше, уменьшаем размер
    if (str.size() > max_size)
    {
        str.erase(max_size, max_size + str.size());
        str.append("...");
    }
}

int main()
{
    // Задаем исходные данные
    int m = 40;
    string text = "   Lorem   ipsum  dolor      sit  amet,    consectetuer adipiscing elit.       Maecenas porttitor congue   massa. Fusce posuere, magna sed  pulvinar ultricies, purus lectus malesuada libero, sit amet commodo magna eros quis     urna.";
   
    // Вызываем решение
    solve(text, m);

    // Выводим
    cout << text << '\n';

    return 0;
}
