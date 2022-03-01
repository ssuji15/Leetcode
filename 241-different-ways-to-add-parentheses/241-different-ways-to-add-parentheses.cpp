class Solution {
public:
    unordered_map<string,vector<int>> cache;
    vector<int> diffWaysToCompute(string expression) {
        if(cache.find(expression) != cache.end()) {
            return cache[expression];
        }
        vector<int> values;
        for(int i=0;i<expression.length();i++) {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> values1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> values2 = diffWaysToCompute(expression.substr(i+1));
                for(int j=0;j<values1.size();j++) {
                    for(int k=0;k<values2.size();k++) {
                        int curValue;
                        switch(expression[i]) {
                            case '+': 
                                curValue = values1[j] + values2[k];
                                break;
                            case '-':
                                curValue = values1[j] - values2[k];
                                break;
                            case '*':
                                curValue = values1[j] * values2[k];
                                break;
                        }
                        values.push_back(curValue);
                    }
                }
            }
        }
        
        if(values.size() == 0) {
            values.push_back(stoi(expression));
        }
        cache[expression] = values;
        return values;
    }
};