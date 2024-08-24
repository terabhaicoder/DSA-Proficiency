class Solution
{
public:
    string large(string s)
    {
        int n = s.size();
        int mid = (n + 1) / 2;
        string temp = s.substr(0, mid);
        bool flag = true;
        for (int i = mid; i < n; i++)
        {
            if (s[i] == s[n - 1 - i])
            {
                continue;
            }
            else if (s[i] > s[n - 1 - i])
            {
                flag = true;
                break;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            int carry = 1;
            for (int i = mid - 1; i >= 0; i--)
            {
                if (temp[i] == '9')
                {
                    temp[i] = '0';
                }
                else
                {
                    temp[i] = temp[i] + 1;
                    carry = 0;
                    break;
                }
            }
            if (carry)
            {
                return "1" + string(n - 1, '0') + "1";
            }
        }
        for (int i = n - mid - 1; i >= 0; i--)
        {
            temp += temp[i];
        }
        return temp;
    }
    string small(string s)
    {
        int n = s.size();
        int mid = (n + 1) / 2;
        string temp = s.substr(0, mid);
        bool flag = true;
        for (int i = mid; i < n; i++)
        {
            if (s[i] == s[n - 1 - i])
            {
                continue;
            }
            else if (s[i] > s[n - 1 - i])
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            int carry = -1;
            for (int i = mid - 1; i >= 0; i--)
            {
                if (temp[i] == '0')
                {
                    temp[i] = '9';
                }
                else
                {
                    temp[i] = temp[i] - 1;
                    carry = 0;
                    break;
                }
            }
            if (temp[0] == '0')
            {
                return string(n - 1, '9');
            }
        }
        for (int i = n - mid - 1; i >= 0; i--)
        {
            temp += temp[i];
        }
        return temp;
    }
    string nearestPalindromic(string n)
    {
        if (n.size() == 1)
        {
            int x = stoi(n);
            x -= 1;
            return to_string(x);
        }
        string l = "", s = "";
        l = large(n);
        s = small(n);
        long long re = stoll(n);
        long long la = stoll(l);
        long long sm = stoll(s);
        if ((re - sm) > (la - re))
        {
            return l;
        }
        return s;
    }
};