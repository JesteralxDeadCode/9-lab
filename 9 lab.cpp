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
    string buffer;
    string strings[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Введите строку #" << i + 1 << " :";
        cin>>strings[i];
    }

    for (int i = 0; i < 10; i++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (strings[x] > strings[x + 1])
            {
                buffer = strings[x];
                strings[x] = strings[x + 1];
                strings[x + 1] = buffer;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout<< endl << strings[i];
    }
}

void zad3()
{
    string str1 = "Never ", str2 = "Say ", str3 = "Never ", strResult = str1 + str2 + str3;
    strResult.erase(strResult.size() - 1);
    strResult += '!';
    for (int i = 0; i < strResult.size(); i++)
    {
        if (isupper(strResult[i]))
        {
            strResult[i] = tolower(strResult[i]);
        }
    }
    if (islower(strResult[0]))
    {
        strResult[0] = toupper(strResult[0]);
    }

    cout << strResult;
}

void zad4()
{
    string first, second;
    bool concurrence = false;
    int i2 = 0, buffer = 0;
    cout << "Введите текст в котором будет искааться фрагмент :";
    cin >> first;
    cout << "Введите фрагмент который будет искаться в тексте :";
    cin >> second;

    for (int i = 0; i < first.size(); i++)
    {
        if (i2 <= second.size())
        {
            if (first[i] == second[i2])
            {
                i2++;
                buffer = i;
            }
            else
            {
                i2 = 0;
            }
        }
    }

    if (i2 == second.length())
    {
        cout << "В тексте был найден фрагмент !, начиная с симовла номер :" << buffer+1-second.length() ;
    }
    else
    {
        cout << "такого фрагмента в тексте не найдено !";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    
    zad4();

}