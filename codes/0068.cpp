class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0, sz = words.size();
        while (i < sz) {
            int len = 0, num = 0;
            while (i < sz && len + words[i].size() + num <= maxWidth) {
                len += words[i].size();
                num++;
                i++;
            }
            string line = words[i - num];
            if (num == 1) {                
                while (line.size() < maxWidth) line += " ";
            } else {                
                if (i == sz) {
                    for (int j = i - num + 1; j < i; j++)
                        line += " " + words[j];
                    while (line.size() < maxWidth) line += " ";
                } else {
                    int p = (maxWidth - len) / (num - 1), q = maxWidth - len - p * (num - 1);
                    for (int j = i - num + 1; j < i; j++) {
                        int o = p + (j - i + num - 1 < q);
                        while (o--) line += " ";
                        line += words[j];
                    }
                }
            }
            ans.push_back(line);
        }
        return ans;
    }
};