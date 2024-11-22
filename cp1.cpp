#include<iostream>
using namespace std;

bool array(int length, int arr[]);

int main()
{
    int length;
    cout << "Enter Array length: ";
    cin >> length;

    int arr[length];
    cout << "Enter array elements each in one line: "<<endl;
    for(int i=0; i<length; i++)
    {
        cin >> arr[i];
    }

    bool output;
    output=array(length,arr);
    cout<<endl<<output;
}

bool array(int length, int arr[])
{
    int temp;
    bool result;

for(int i=length-1; i >= 0; i--)
{
    for(int j=0; j<i; j++)
    {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}

    for(int k=1; k<length; k++)
    {
        int x=k-1;
        int y= arr[x]+1;
        if( arr[k] == y )
        {
            result=true;
        }
        else
        {
            result=false;
            break;
        }
    }

    return result;
}