// C++ program to output the maximum occurring character // in a string
#include<bits/stdc++.h>
using namespace std;

char search_char(char* str)
{

    int count[256] = {0};
    int max = 0;
    char result;

    for (int i = 0; i < strlen(str); i++) {
        count[str[i]]++;
        if (max < count[str[i]]) {
            max = count[str[i]];
            result = str[i];
        }
    }
    return result;
}

int main()
{
    char str[] = "GOODDAY TO LEARN COMPUTERS";
    cout<<"INPUT STRING IS: "<<str<<endl;
    cout << "Character repreating the most "<< search_char(str);
}
