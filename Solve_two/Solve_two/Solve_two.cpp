#include <iostream>

using namespace std;

void bracket_check(string str)
{
    bool state = true;  // условие выхода из цикла state == false
    bool stateEND = false; // принудительное окончание цикла
    int chL = 0; // счет левых скобок (
    int chR = 0; // счет правых скобок )
    int i = 0; // итератор внутри цикла


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

}

