class Solution {
    private:
    void fun(string s,int i,int j,int &start,int &maxlen){
    //int cnt=0;
    int len=0;
while(i>=0 && j<s.size()&&s[i]==s[j]){
 len=j-i+1;
 if(len>maxlen){
    maxlen=len;
    start=i;
   // maxlen=len;
 }
 i--;
 j++;
}
//return cnt;
    }
public:
    string longestPalindrome(string s) {
          int start=0;
          int maxlen=0;
          //string temp="";
    for(int i=0;i<s.size();i++){ 
    fun(s,i,i,start,maxlen);
    fun(s,i,i+1,start,maxlen);
    }    
  return s.substr(start,maxlen);
    }
};