#include <bits/stdc++.h>

using namespace std;

class dynamic_array
{
    private:
        int *arr;
        int space,elements;

    public:
        dynamic_array(int size)
        {
            arr = new int[size];
            space = size;
            elements = 0;
        }
        void add_mem(int s);
        void push(int n);
        void pop();
        int get(int index);
        void insert(int n, int index);
        void del(int index);
        int search(int n);
        void display();
};

void dynamic_array::add_mem(int s)
{
    int *temp = new int(s);
    for(int i = 0; i < elements; i++)
    {
        *(temp+i) = *(arr + i);
    }
    delete arr;
    arr = temp;
}

void dynamic_array::push(int n)
{
    if(elements == space)
    {
        space *= 2;
        add_mem(space);
    }

    *(arr + elements) = n;
    elements++;
}

void dynamic_array::pop()
{
    if(elements)
    {
        elements--;
        cout << "\nElement popped is " << *(arr + elements);
    }

    else
        cout << "\nArray is empty.";
}

int dynamic_array::get(int index)
{
    return *(arr+index);
}

void dynamic_array::insert(int n, int index)
{
    if(elements == space)
    {
        space *= 2;
        add_mem(space);
    }

    for(int i = (elements-1); i >= index; i--)
    {
        *(arr + i + 1) = *(arr + i);
    }

    *(arr + index) = n;
    elements++;
}

void dynamic_array::del(int index)
{
    if(elements)
    {
        for(int i = index; i < (elements-1); i++)
        {
            *(arr + i) = *(arr + i + 1);
        }

        elements--;
    }

    else
        cout << "\nArray is empty.";
}

int dynamic_array::search(int n)
{
    for(int i = 0; i < elements ; i++)
    {
        if( *(arr + i) == n)
            return i;
    }

    return -1;
}

void dynamic_array::display()
{
    for(int i = 0; i < elements; i++)
    {
        cout<< '\n' << *(arr + i);
    }
}


int main()
{
    dynamic_array a(10);
    cout<<"Enter 10 no.s:";
    for(int i = 0; i<10; i++)
    {
        int n;
        cin>>n;
        a.push(n);
    }
    a.display();

    cout<<"\n"<<a.search(5)<<"\n"<<a.get(3);
    a.push(11);
    a.display();
    a.pop();
    a.display();
    a.insert(13,5);
    a.display();
    a.del(5);
    a.display();
    return 0;
}
