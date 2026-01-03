#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        string s;
        cin >> s;

        if(s == "*") break;

        bool flag = true;
        int len = 1;

        while(len < s.length())
        {
            vector<string>v;

            for(int i = 0 ; i < s.length(); ++i)
            {
                if( i + len >= s.length()) break;

                string temp ="";
                temp += s[i];
                temp += s[i + len];
                v.push_back(temp);
            }

            for(int i = 0; i < v.size(); ++i)
            {
                for(int j = i + 1; j < v.size(); ++j)
                {
                    if(v[i] == v[j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            
            if(!flag) break;

            len++;
            
        }

        if(flag)
        {
            cout << s << " is surprising." << '\n';
        }
        else
        {
            cout << s << " is NOT surprising." << '\n';
        }
    }


    return 0;
}