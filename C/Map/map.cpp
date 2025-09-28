#include <bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    map<string, int> mp;

    mp["sahil"] = 98;
    mp["ayush"] = 2;
    mp["akhil"] = 1;

    cout << "marks of sahil is " << mp["sahil"]<<endl;
    mp.find("sahil");

    // if(mp.find("sahil") == mp.end())
    //     cout << "Not found";
    // else
    //     cout << "Found";
    //     return 0;
}