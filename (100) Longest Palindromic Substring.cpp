string longestPalinSubstring(string str)
{
    // Write your code here.
    // we need to solve for two cases whether the target string could be of even length or odd length.

    string oddtarget="",eventarget="";
    int n = str.length();

    //Odd target finding
    for(int i = 0;i<n;i++){
        int mid_ind = i;
        string temp = "";
        temp+=str[i];
        int k=1;
        while(mid_ind-k>=0&&mid_ind+k<n){
            if(str[mid_ind-k]==str[mid_ind+k]) {
                temp = str[mid_ind-k]+temp+str[mid_ind+k];
                k++;
            }
            else break;
        }
        
        if(oddtarget.length()<temp.length()) oddtarget= temp;
    }

    //Even target finding
    for(int i = 0;i<n;i++){
        //take it as left mid. 
        int mid_ind = i;
        string temp = "";
        int k=1;
        while(mid_ind-k+1>=0&&mid_ind+k<n){
            if(str[mid_ind-k+1]==str[mid_ind+k]) {
                temp = str[mid_ind-k+1]+temp+str[mid_ind+k];
                k++;
            }
            else break;
        }
        
        if(eventarget.length()<temp.length()) eventarget= temp;
    }

    if(eventarget.length()>oddtarget.length()) return eventarget;
    return oddtarget;

}