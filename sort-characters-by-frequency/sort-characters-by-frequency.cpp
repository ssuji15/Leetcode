class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> charCount;
        
        for(int i=0;i<s.length();i++) {
            charCount[s[i]]++;
        }
        
        priority_queue<pair<int,char>, vector<pair<int,char>>, less<pair<int,char>>> pq;
        
        for(int i=0;i<26;i++) {

            if(charCount.find(i+'a') != charCount.end() && charCount[i+'a'] > 0) {
                pq.push({charCount[i+'a'], i+'a'});
            }
            
            if(charCount.find(i+'A') != charCount.end() && charCount[i+'A'] > 0) {
                pq.push({charCount[i+'A'], i+'A'});
            }
            
            if(i <= 9 && charCount.find(i+'0') != charCount.end() && charCount[i+'0'] > 0) {
                pq.push({charCount[i+'0'], i+'0'});
            }
        }
        
        string result = "";
        while(!pq.empty()) {
            pair<int,char> temp = pq.top();
            pq.pop();
            
            int count = temp.first;
            char ch = temp.second;
            
            for(int i=0;i<count;i++) {
                result += ch;
            }
        }
        
        return result;
    }
};