class Solution {
public:
    int shortestWay(string source, string target) {
        int count = 0;
        for(int i=0;i<target.length();) {
            int temp = i;
            for(int j=0;j<source.length();j++) {
                if(source[j]==target[i]) i++;
            }
            if(temp == i) return -1;
            count++;
        }
        return count;
    }
};