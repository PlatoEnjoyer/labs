#include <iostream>


/*
Дана строка, состоящая из английских букв, 
длиной не более 100 символов, определите, является ли она палиндромом.
*/



bool is_palinrome(std::string& s, int i, int j)
{
    if (s[i] != s[j])
    {
        return false;
    }

    if (i >= j)
    {
        return true;
    }

    return is_palinrome(s, i+1, j-1);
}


int main()
{
    std::string s = "";

    std::cout << is_palinrome(s, 0, s.length() - 1) << std::endl;
    
    return 0;
}