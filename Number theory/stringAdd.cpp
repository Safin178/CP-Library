
/*
Add two Big int:
*/

string add(string n1, string n2)
{
    string res = "";
    int sum, carry = 0;
    for (int i = sz(n1) - 1; i >= 0; i--)
    {
        sum = n1[i] - '0' + n2[i] - '0' + carry;
        if (sum > 9)
        {
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }
        else
        {
            res = to_string(sum) + res;
            carry = 0;
        }
    }
    if (carry)
        res = to_string(carry) + res;
    return res;
}
