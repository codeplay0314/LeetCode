class Solution {
private:
    bool isDigits(string str) {
        int len = str.size();
        if (len == 0) return false;
        for (auto c : str) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }
    bool isInteger(string str) {
        int len = str.size();
        if (len == 0) return false;
        if (str[0] == '+' || str[0] == '-') return isDigits(str.substr(1, len));
        return isDigits(str);
    }
    bool isDecimal(string str) {
        int len = str.size();
        if (len == 0) return false;
        
        int dot_pos = -1;
        for (int i = 0; i < len; i++)
            if (str[i] == '.') {
                dot_pos = i;
                break;
            }
        if (dot_pos == -1) return false;
        if (str[0] == '+' || str[0] == '-') str = str.substr(1, len--), dot_pos--;
        if (len == 1) return false;
        if (dot_pos == 0) return isDigits(str.substr(dot_pos + 1, len));
        if (dot_pos == len - 1) return isDigits(str.substr(0, dot_pos));
        return isDigits(str.substr(0, dot_pos)) && isDigits(str.substr(dot_pos + 1, len));
    }
public:
    bool isNumber(string str) {
        int len = str.size();
        if (len == 0) return false;
        
        int e_pos = -1;
        for (int i = 0; i < len; i++)
            if (str[i] == 'e' || str[i] == 'E') {
                e_pos = i;
                break;
            }
        if (e_pos == -1) return isInteger(str) || isDecimal(str);
        return (isInteger(str.substr(0, e_pos)) || isDecimal(str.substr(0, e_pos))) && isInteger(str.substr(e_pos + 1, len));
    }
};