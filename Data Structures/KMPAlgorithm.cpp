// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    vector<int> computeLPS(string& pat, int m){
        vector<int> LPS(m, 0);
        
        int i = 1; // lps of 0 = 0;
        int len = 0;
        
        while(i < m){
            if(pat[i] == pat[len]){
                LPS[i] = len + 1; // 
                
                len++;
                i++;
            }
            else{
                if(len != 0){
                    len = LPS[len - 1];
                }
                else
                {
                    LPS[i] = 0; //
                    i++;
                }
            }
        }
        
        return LPS;
    }
    
    int KMPSearch(string& txt, string& pat){
        int n = txt.size();
        int m = pat.size();
        
        vector<int> lps = computeLPS(pat, m);
        
        int i = 0;
        int j = 0;
        
        while(i < n){
            if(txt[i] == pat[j]){
                i++;
                j++;
                
                if(j == m){
                    // print(i - j);
                    // j = lps[j - 1];
                    
                    return i - j;
                }
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return KMPSearch(haystack, needle);
    }
};
