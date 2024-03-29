class Solution {
public:
     vector<int> findOriginalArray(vector<int>& A) {
         
        if (A.size() % 2) return {};
        map<int, int> c;
         
        for (int a : A) c[a]++;
         
        vector<int> keys;
         
        for (auto it : c)
        {
            keys.push_back(it.first);
        }
           
         
        vector<int> res;
         
        for (int x : keys) 
        {
            if (c[x] > c[2 * x]) return {};
            
            for (int i = 0; i < c[x]; ++i, c[2 * x]--)
                res.push_back(x);
        }
        return res;
    }
};

 
