#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["Akib"] = 500; // O(logN);
    mp["Sakib"] = 200;
    mp["Rakib"] = 20;
    mp["Hamim"] = 0;
    // cout << mp["Hamim"] << endl; // 0 O(logN)
    mp.insert(make_pair("Ashraful", 300));
    mp.insert({"Mubarak", 600});

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " << it->second << endl;
    }

    if(mp.count("Hamim")){
        cout<<"Achhe";
    }else{
        cout<<"Nai";
    }

    return 0;
}