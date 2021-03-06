class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2) return s;
        int anslen = 0,ansidx = 0;
        for(int i=0;i<(int)s.size();){
            int start = i;
            while(s[start] == s[i+1]) i++;
            int end = i;
            
            while(start > -1 && end < (int)s.size() && s[start] == s[end]){
                start--,end++;
            }
            if(end - start >= 3 && end-start-1 > anslen) ansidx = start+1,anslen = end - start - 1;
            i++;
        }
        return s.substr(ansidx,anslen);
    }
};

