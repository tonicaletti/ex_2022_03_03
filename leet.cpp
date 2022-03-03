#include <iostream>
#include <map>
#include <string>
#include <vector>

int trivial_sol(int *array, int size)
{
    return 0;
}

bool anagramcheck(std::string s, std::string t)
{
    std::map<char, int> dict_s;
    std::map<char, int> dict_t;

    for (int i = 0; i < s.size(); i++)
    {
        if (dict_s.find(s[i]) != dict_s.end())
        {
            dict_s[s[i]] = dict_s[s[i]] + 1;
        }
        else
        {
            dict_s[s[i]] = 1;
        }
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (dict_t.find(t[i]) != dict_t.end())
        {
            dict_t[t[i]] = dict_t[t[i]] + 1;
        }
        else
        {
            dict_t[t[i]] = 1;
        }
    }

    for (auto val : dict_s)
    {
        if (dict_t[val.first] != val.second)
        {
            return false;
        }
    }
    for (auto val : dict_t)
    {
        if (dict_s[val.first] != val.second)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    std::string s = "anad";
    std::string t = "dana";

    std::cout << anagramcheck(s, t);

    return 0;

    int array[] = {1, 2, 3, 4};
    const int size = sizeof(array) / sizeof(int);

    int diff[size]{};

    for (int i = 1; i < size; i++)
    {
        diff[i] = array[i] - array[i - 1];
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << diff[i] << std::endl;
    }

    int curr_len = 2;
    int sum = 0;
    for (int i = 2; i < size; i++)
    {
        if (diff[i] == diff[i - 1])
        {
            curr_len++;
        }
        else
        {
            curr_len = 2;
        }


        if (curr_len >= 3)
        {
            sum = sum + curr_len - 2;
        }
    }

    std::cout << "sum: " << sum << std::endl;
}
