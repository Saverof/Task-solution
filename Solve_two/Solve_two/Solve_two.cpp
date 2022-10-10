#include <iostream>

using namespace std;

// Зачем отправлять копию строки? Может быть лучше константная ссылка?
// Почему возвращается void, а не bool?
void bracket_check(string str)
{
    bool state = true;  // условие выхода из цикла state == false
//    Зачем нужна переменная stateEND?
    bool stateEND = false; // принудительное окончание цикла
    int chL = 0; // счет левых скобок (
    int chR = 0; // счет правых скобок )
//    Зачем нужна эта переменная?
    int i = 0; // итератор внутри цикла

//    Можно использовать цикл for?
    while (state)
    {
        switch (str[i])
        {
        case '(': 
            chL++;
            break;
        case ')':
            chR++;
            break;
        default:
            break;
        }

        if (i == str.size())
        {
            state = false;
            stateEND = true;
        }

        i++;

        if (chL == chR)
        {
            if (i == str.size())
            {
                state = false;
            }
        }
    }

//    Вынести в отдельную функцию. Зачем проверять условия здесь?
//    Зачем писать != true?
    if (i == str.size() && stateEND != true)
    {
        cout << str << " - правильная скобочная последовательность\n";
    }
    else
    {
        cout << str << " - неправильная скобочная последовательность\n";
    }
   
    
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    bracket_check("((x * y) + (2 * (x + y))) * (y + 3)");
    bracket_check("((((x * y) + (2 * (x - y)))");
//    В этом случае будет неправильная последовательность
    bracket_check(")(");
}

