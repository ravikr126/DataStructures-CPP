#include<bits/stdc++.h>

using namespace std;

struct data {
    string key;
    int value;
};

class hashMap {
    private:
        vector< vector<data> > dataMap;
        int hashString(string key);
    public:
        int get(string key);
        void set(string key, int value);
};
