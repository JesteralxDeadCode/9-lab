#include <iostream>
using namespace std;

void zad1()
{
    char buffer;
    int length = NULL;
    cout << "Введите длину строчки:";
    cin >> length;
    char* strings = new char[length];

    cout << "Введите в строчку инофрмацию :";
    cin >> strings;

    for (int i = 0; i < length; i++)
    {
        for (int x = 0; x < length-1; x++)
        {
            if (strings[x] > strings[x + 1])
            {
                buffer = strings[x];
                strings[x] = strings[x + 1];
                strings[x + 1] = buffer;
            }
        }

    }

    for (int i = 0; i < length; i++)
    {
        cout << strings[i];
    }
}

void zad2()
{

}

int main()
{
    setlocale(LC_ALL, "ru");
    
    zad1();

}