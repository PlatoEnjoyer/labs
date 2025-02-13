#include <iostream>
#include <map>
using namespace std;

map<char, int> str_to_int = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5} ,{'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};


class BigInt
{
private:
    static const int BASE = 10;
    static const int SIZE = 1000;
public:
    int digits[SIZE];
    bool is_negative = false;

public:
    BigInt()
    {
        for (int i = 0; i < SIZE; i++)
        {
            digits[i] = 0;
        }
    }

    BigInt(const string& num): BigInt()
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if (num[i] == '-')
            {
                is_negative = true;
                break;
            }
            digits[num.size() - i - 1] = str_to_int[num[i]];
        }
    }

    BigInt(const BigInt& other): BigInt()
    {
        is_negative = other.is_negative;
        for (int i = 0; i < SIZE; i++)
        {
            digits[i] = other.digits[i];
        }
    }

    int get_size()
    {
        return SIZE;
    }

    int get_base()
    {
        return BASE;
    }

    BigInt addition(const BigInt& left, const BigInt& right)
    {
        BigInt res;

        for (int i = 0; i < SIZE; i++)
        {
            res.digits[i] = left.digits[i] + right.digits[i];
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (res.digits[i] >= BASE)
            {
                res.digits[i+1]++;
                res.digits[i] -= BASE;
            }
        }
        return res;
    }

    BigInt subtraction(const BigInt& left, const BigInt& right)
    {
        BigInt res;

        for (int i = 0; i < SIZE; i++)
        {
            res.digits[i] = left.digits[i] - right.digits[i];
        }

        for (int i = 0; i < SIZE - 1; i++)
        {
            if (res.digits[i] < 0)
            {
                res.digits[i] += BASE;
                res.digits[i + 1]--;
            }
        }

        return res;
    }

    void operator+=(const BigInt& other)
    {
        if (is_negative)
        {
            if(!other.is_negative)
            {
                if(module_compare(other) == 1)
                {
                    *this = subtraction(*this, other);
                    is_negative = true;
                    return;
                }
                else if (module_compare(other) == 0)
                {
                    BigInt n;
                    *this = n;
                    is_negative = false;
                    return;
                }
                else
                {
                    *this = subtraction(other, *this);
                    is_negative = false;
                    return;
                }
            }
            else
            {
                *this = addition(*this, other);
                is_negative = true;
                return;
            }
        }
        else
        {
            if (other.is_negative)
            {
                if (module_compare(other) == 1)
                {
                    *this = subtraction(*this, other);
                    return;
                }
                else if (module_compare(other) == 0)
                {
                    BigInt n;
                    *this = n;
                    return;
                }
                else
                {
                    *this = subtraction(other, *this);
                    is_negative = true;
                    return;
                }
            }
            else
            {
                *this = addition(*this, other);
                return;
            }
        }
    }

    BigInt operator+(BigInt& other)
    {
        BigInt num(*this);
        num += other;
        return num;
    }

    void operator*=(const BigInt& other) 
    {
        *this = *this * other;
    }

    BigInt operator*(const BigInt& other) 
    {
        BigInt result;

        for (int i = 0; i < SIZE; i++) 
        {             
            for (int j = 0; j < SIZE; j++) 
            {
                result.digits[i + j] += digits[i] * other.digits[j];
            }
        }
        for (int i = 0; i < SIZE - 1; i++) 
        {
            result.digits[i + 1] += result.digits[i] / BASE;
            result.digits[i] %= BASE;
        }

        if ((is_negative && other.is_negative) || (!is_negative && !other.is_negative))
        {
            result.is_negative = false;
        }
        else
        {
            result.is_negative = true;
        }
        return result;
    }

    int get_order_of_number()
    {
        int result = 0;

        for (int i = SIZE - 1; i >= 0; i--)
        {
            if (digits[i] != 0)
            {
                result = i;
                break;
            }
        }

        return result + 1;
    }

    void operator-=(BigInt& other)
    {
        if (is_negative)
        {
            if (!other.is_negative)
            {
                *this = addition(*this, other);
                is_negative = true;
                return;
            }
            else
            {
                if (module_compare(other) == 1)
                {
                    *this = subtraction(*this, other);
                    is_negative = true;
                    return;
                }
                if (module_compare(other) == 0)
                {
                    BigInt n;
                    *this = n;
                    is_negative = false;
                    return;
                }
                if (module_compare(other) == -1)
                {
                    *this = subtraction(other, *this);
                    is_negative = false;
                    return;
                }
            }
        }
        else
        {
            if (other.is_negative)
            {
                *this = addition(*this, other);
                return;
            }
            else
            {
                if (module_compare(other) == 1)
                {
                    *this = subtraction(*this, other);
                    return;
                }
                if (module_compare(other) == 0)
                {
                    BigInt n;
                    *this = n;
                    return;
                }
                if (module_compare(other) == -1)
                {
                    *this = subtraction(other, *this);
                    is_negative = true;
                    return;
                }
            }
        }
    }

    BigInt operator-(BigInt& other)
    {
        BigInt num(*this);
        num -= other;
        return num;
    }

    bool operator>(const BigInt& other)
    {
        if (is_negative > other.is_negative)
        {
            return true;
        }
        if (is_negative < other.is_negative)
        {
            return false;
        }

        for (int i = SIZE - 1; i >= 0; i--)
        {
            if (digits[i] > other.digits[i])
            {
                return true;
            }
            if (digits[i] < other.digits[i])
            {
                return false;
            }
        }

        return false;
    }

    bool operator<(BigInt& other)
    {
        return !(*this > other) && (*this!=other);
    }

    bool operator==(BigInt& other)
    {
        if (is_negative != other.is_negative)
        {
            return false;
        }

        for (int i = SIZE - 1; i >= 0; i--)
        {
            if (digits[i] != other.digits[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(BigInt& other)
    {
        return !(*this == other);
    }

    int module_compare(const BigInt& other)
    {
        for (int i = SIZE - 1; i >= 0; i--)
        {
            if (digits[i] > other.digits[i])
            {
                return 1;
            }
            if (digits[i] < other.digits[i])
            {
                return -1;
            }
        }

        return 0;
    }
};


ostream& operator<<(ostream& os, BigInt& num)
{
    string result;
    int idx_first_digit = num.get_order_of_number();

    if (idx_first_digit == 0)
    {
        return os;
    }

    for (int i = idx_first_digit - 1; i >= 0; i--)
    {
        result += to_string(num.digits[i]);
    }

    if (num.is_negative)
    {
        cout << '-';
    }
    cout << result;
    return os;
}

istream& operator>>(istream& os, BigInt& num)
{
    string num_str;
    cin >> num_str;
    num = BigInt(num_str);
    return os;
}

int main()
{
    BigInt num;
    BigInt num1;
    cin >> num;
    cin >> num1;
    num *= num1;
    num -= num1;
    num1 -= num;
    cout << num << endl;
    cout << num1 << endl;
    return 0;
}