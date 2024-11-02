#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/*
Дан файл, содержащий английский текст. Найти в тексте N<=2000 слов, содержащих наибольшее количество одинаковых букв. 
Записать найденные слова в текстовый файл в порядке невозрастания количества одинаковых букв. 
Для каждого слова вывести также это количество. Все найденные слова должны быть разными!
*/


int main()
{
    string line;
    string text;
    string max_letter_words[2000];

    ifstream in("text.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            text += line;
            text += " ";
        }
    }
    in.close();

    cout << text;

}