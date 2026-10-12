class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        int n=a.size();
        sort(a.begin(),a.end());
        int start=a[0][0];
        int end=a[0][1];
        
        for(int i=1;i<n;i++)
        {
            int s=a[i][0];
            int e=a[i][1];

            if(end>=s) //overlap
            {
                end=max(end,e);
                continue;
            }
            // push
            res.push_back({start,end});
            start=s;
            end=e;
        }
        res.push_back({start,end});
        return res;
    }

};