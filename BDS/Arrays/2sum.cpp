#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define MIN 10000
int hash2[MIN + 1] = {0};
int cnt = 0;
void readData()
{
    ifstream fin("sumSmall.txt");
    int temp = 0;
    while (fin >> temp)
    {
        if (temp < MIN)
        {
            hash2[temp]++;
        }
    }
}
bool hashMap(int n)
{
    if (n > MIN)
    {
        return false;
    }
    if (hash2[n])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    readData();
    for (int i = -10000; i <= 10000; i++)
    {
        for (int j = -10000; j <= 10000; j++)
        {
            if (hashMap(j) && hashMap(i - j))
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}