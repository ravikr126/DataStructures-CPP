#include<bits/stdc++.h>

using namespace std;

struct data
{
    string key;
    int value;
};

class hashMap
{
    private:
        vector< vector<data> > dataMap;
        int hashString(string key);
    public:
        int getValue(string key);
        void insertKey(string key, int value);
        void deleteKey(string key);
        void modifyValue(string key, int newValue);
        vector<string> keys();

        hashMap(int n){
            dataMap.resize(n);
        }
};

int hashMap::hashString(string key)
{
    int hash = 0;
    for (int i =0; i < key.length(); i++){
        hash = (hash + int(key[i]) * i) % dataMap.size();
    }
    return hash;
}

int hashMap::getValue(string key)
{
    int pos = hashString(key);
    if(dataMap[pos].size())
    {
        for(int i = 0; i < dataMap[pos].size(); i++)
        {
            if(dataMap[pos][i].key == key)
            {
                return dataMap[pos][i].value;
            }
        }
    }
    return 0;
}

void hashMap::deleteKey(string key)
{
    int pos = hashString(key);
    if(dataMap[pos].size())
    {
        for(int i = 0; i < dataMap[pos].size(); i++)
        {
            if(dataMap[pos][i].key == key)
            {
                dataMap[pos].erase(dataMap[pos].begin() + i);
                return;
            }
        }
    }
    cout<< "Key does not exist...";
}

void hashMap::insertKey(string key, int value)
{
    if(value < 1)
    {
        cout<< "Value must be greater than zero";
        return;
    }
    int pos = hashString(key);
    data temp;
    temp.key = key;
    temp.value = value;
    dataMap[pos].push_back(temp);
}

void hashMap::modifyValue(string key, int newValue)
{
    int pos = hashString(key);
    if(dataMap[pos].size())
    {
        for(int i = 0; i < dataMap[pos].size(); i++)
        {
            if(dataMap[pos][i].key == key)
            {
                dataMap[pos][i].value = newValue;
                return;
            }
        }
    }
    cout<< "Key does not exist...";
}

vector<string> hashMap::keys()
{
    vector<string> keys;
    for(int i = 0; i < dataMap.size(); i++)
    {
        if(dataMap[i].size())
        {
            for(int j = 0; j < dataMap[i].size(); j++)
            {
                keys.push_back(dataMap[i][j].key);
            }
        }
    }

    return keys;
}


int main()
{

}


/*
 - delete fucntion
 - traversal function
 - key
 */
