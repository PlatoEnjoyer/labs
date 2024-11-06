#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;


/*
Дан файл, содержащий английский текст. Найти в тексте N<=2000 слов, содержащих наибольшее количество одинаковых букв. 
Записать найденные слова в текстовый файл в порядке невозрастания количества одинаковых букв. 
Для каждого слова вывести также это количество. Все найденные слова должны быть разными!
*/

string readFile()
{
    string line;
    string text;

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

    return text;
}

void removing_punctuation(string & str)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ')
        {
            str.erase(i, 1);
            n--;
            i--;
        }
    }
}

int max_number_of_identical_letters(const string & text)
{
    int max_number = 0;
    string max_word;


    for (int i = 0; i < text.length(); i++)
    {
        map<char, int> count_of_chars;
        string curr_word = "";

        while (text[i] != ' ')
        {
            curr_word += text[i];
            count_of_chars[text[i]]++;
            i++;
        }

        for (const auto& [chr, count]: count_of_chars)
        {
            if (max_number < count)
            {
                max_number = count;
                max_word = curr_word;
            }
        }
    }

    cout << "наибольшее количество букв в слове " << max_word << " а именно: " << max_number; 

    return max_number;
}


int main()
{
    string text = readFile();
    removing_punctuation(text);
    max_number_of_identical_letters(text);
}