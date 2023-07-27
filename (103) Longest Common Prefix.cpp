string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans= "";
    for(int i = 0;i<arr[0].length();i++){
        char ch = arr[0][i];
        for(int j=1;j<n;j++){
            if(i>=arr[j].length() || arr[j][i]!=ch) return ans; 
        }
        ans+=ch;
    }
    return ans;
}
