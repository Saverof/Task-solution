#include <iostream>
#include <algorithm>

using namespace std;

// Логичнее вернуть новую строку, а не изменять существующую
// Исправил
void solve(string& str, int max_size)
{
    // Переменная для хранения обработанного текста
    string new_text = str;

    // Удаляем все пробелы больше одного
    new_text.erase(unique_copy(new_text.begin(), new_text.end(), new_text.begin(), [](char ch1, char ch2) { return ch1 == ' ' && ch2 == ' '; }), new_text.end());

//    А последний не надо проверять?
// Исправил
    // Проверяем чем является первый символ
    if (new_text.at(0) == ' ')
        new_text.erase(0, 1);
    
    // Проверяем чем является последний символ
    if (new_text.back() == ' ')
        new_text.pop_back();
   
    // Если размер больше максимального значения, уменьшаем размер
    if (new_text.size() > max_size)
    {
        new_text.erase(max_size, max_size + new_text.size());
        new_text.append("...");
    }

    return new_text;
}

int main()
{
    // Задаем исходные данные
    int m = 40;
  
    // Исправил
    string text = "   Lorem   ipsum  dolor      sit  amet,    consectetuer adipiscing elit.       Maecenas porttitor congue   massa. Fusce posuere, magna sed  pulvinar ultricies, purus lectus malesuada libero, sit amet commodo magna eros quis     urna.      ";
   
    // Вызываем решение
    solve(text, m);

    // Выводим исходную строку
    cout << text << '\n';
    // Выводим исправленную строку
    cout << endl << solve(text, m) << '\n';
    return 0;
}
