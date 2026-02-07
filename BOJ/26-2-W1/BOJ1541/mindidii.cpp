// 잃어버린 괄호 

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

int main()
{

    string s;
    string num = "";
    cin >> s;
    int total_sum = 0;
    bool check = false;
    for (int i=0; i<s.size()+1; i++)
    {

        if(s[i] == '+' || s[i] == '-' || i == s.size())
        {
            if(!check)
            {
                total_sum += stoi(num);
                num = "";
            }
            else if (check)
            {
                total_sum -= stoi(num);
                num = "";
            }
        }
        else
        {
            num += s[i];
        }
       
        if(s[i] == '-')
        {
            check = true;
        }
    }
    cout << total_sum << '\n';

    return 0;
}