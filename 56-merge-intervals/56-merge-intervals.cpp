class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        vector<int>a=arr[0];
        for(int i=0;i<arr.size();i++){
            if(a[1]>=arr[i][0]){
                a[1]=max(a[1],arr[i][1]);
            }
            else{
                res.push_back(a);
                a=arr[i];
            }
        }
        res.push_back(a);
        return res;
    }
};