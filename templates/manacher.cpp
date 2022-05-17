// See: Problem 336. Palindrome Pairs

void Manacher(string& str) {
    int len = str.length();    
    int slen = 2 * len + 1;
    string s(slen, '#');
    for (int i = 0; i < len; i++) {
        s[i * 2 + 1] = str[i];
    }
    vector<int> d(slen);
    for (int i = 0, l = 0, r = -1; i < slen; i++) {
        d[i] = i > r ? 1 : min(d[l + r - i], r - i + 1);
        while (i - d[i] >= 0 && i + d[i] < slen && s[i - d[i]] == s[i + d[i]]) d[i]++;
        if (i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;
    }
}    