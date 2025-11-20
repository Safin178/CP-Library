// Convert binary string to integer
ll binaryToInt(const string &s) {
    ll val = 0;
    for (char c : s) {
        val = val * 2 + (c - '0');   // shift left, add bit
    }
    return val;
}

// Convert integer to binary string
string intToBinary(ll x) {
    if (x == 0) return "0";

    string s = "";
    while (x > 0) {
        s += char('0' + (x % 2));  // take last bit
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
