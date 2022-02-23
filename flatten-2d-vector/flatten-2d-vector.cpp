class Vector2D {
public:
    vector<vector<int>> temp;
    int i,j;
    Vector2D(vector<vector<int>>& vec) {
        temp = vec;
        i=0;
        j=0;
    }
    void moveToNext() {
        while(i<temp.size() && j==temp[i].size()) {
            i++;
            j=0;
        }
    }
    int next() {
        moveToNext();
        int element = temp[i][j];
        j++;
        return element;
    }
    
    bool hasNext() {
        moveToNext();
        return i<temp.size() && j<temp[i].size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */