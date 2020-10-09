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
        cout<< "\nValue must be greater than zero";
        return;
    }
    if(getValue(key))
    {
        cout<< "\nKey already exist...";
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
    int n, value;
    string key;
    vector<string> keys;

    cout << endl << "Enter size for the map:";
    cin >> n;

    hashMap dataSet(n);

    do
    {
        cout<< endl << "---Hash Map Menu---"
            << endl << "1.Insert Data"
            << endl << "2.Modify Data Value"
            << endl << "3.Find Key Value"
            << endl << "4.Delete Data"
            << endl << "5.Show All Keys"
            << endl << "6.Exit"
            << endl << "Enter values between 1-6";
        cin >> n;
        switch(n)
        {
            case 1 : cout << "\nEnter Key String:";
                     cin >> key;
                     cout << "\nEnter Value:";
                     cin >> value;
                     dataSet.insertKey(key,value);
                     break;

            case 2 : cout << "\nEnter Key String to be modified:";
                     cin >> key;
                     cout << "\nEnter NEW Value:";
                     cin >> value;
                     dataSet.modifyValue(key,value);
                     break;

            case 3 : cout << "\nEnter Key String to get value:";
                     cin >> key;
                     value = dataSet.getValue(key);
                     if(value)
                        cout << '\n' << key << ':' << value;
                     else
                        cout << "\nKey not found...";
                     break;

            case 4 : cout << "\nEnter Key String to delete value:";
                     cin >> key;
                     dataSet.deleteKey(key);
                     break;

            case 5 : cout << "\nKeys in the map are:\n";
                     keys = dataSet.keys();
                     if(keys.size())
                        for(int i = 0; i < keys.size(); i++)
                            cout << keys[i] << ' ';
                     else
                        cout << "There is no data in the set";
                     break;

            case 6 : cout<< "\nExiting...\n";
            default: cout<< "\nInvalid Value ";
        }
    }
    while(n != 6);

    return 0;
}


/*
 - delete fucntion
 - traversal function
 - key
 */
