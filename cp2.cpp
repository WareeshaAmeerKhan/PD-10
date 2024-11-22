#include<iostream>
using namespace std;

int rotation(int length, string arr[]);

int main()
{
    int length;
    cout << "Enter Array length: ";
    cin >> length;

    string arr[length];
    cout << "Enter array elements each in one line(right/left): "<<endl;
    for(int i=0; i<length; i++)
    {
        cin >> arr[i];
    }

    int output;
    output=rotation(length,arr);
    cout<<endl<<output;
}

int rotation(int length, string arr[])
{
    int spin=0;
    int result;

    for(int i=0; i<length; i++)
    {
        if(arr[i]=="right")
        {
            spin+=90;
        }
        else if(arr[i]=="left")
        {











































































































































































































































































































            spin-=90;
        }
    }

    result=spin/360;
    result=abs(result);
    return result;
}