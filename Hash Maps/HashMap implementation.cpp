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
        int get(string key);
        void set(string key, int value);

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


int hashMap::get(string key)
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
    return -1;
}

void hashMap::set(string key, int value)
{
    int pos = hashString(key);
    data temp;
    temp.key = key;
    temp.value = value;
    dataMap[pos].push_back(temp);
}


int main()
{
    hashMap hm(10);

    hm.set("a",1);
    hm.set("b",2);
    hm.set("c",3);
    hm.set("d",4);
    hm.set("aa",5);
    hm.set("ba",6);
    hm.set("ca",7);
    hm.set("da",8);

    std::cout<<std::endl<<hm.get("a");
    std::cout<<std::endl<<hm.get("b");
    std::cout<<std::endl<<hm.get("c");
    std::cout<<std::endl<<hm.get("d");
    std::cout<<std::endl<<hm.get("aa");
    std::cout<<std::endl<<hm.get("ba");
    std::cout<<std::endl<<hm.get("ca");
    std::cout<<std::endl<<hm.get("da");

    return 0;
}
