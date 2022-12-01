class Solution {
public:
    bool halvesAreAlike(string s) {
        int i=0;
        int n=s.size();
        string s1,s2;
        while(i<n/2){
            s1+=s[i];
            i++;
        }
        while(i<n){
            s2+=s[i];
            i++;
        }
        
        int cnt1=0;
        int cnt2=0;
        for(int j=0;j<s1.size();j++){
            if(s1[j] =='a' || s1[j] =='e' || s1[j] =='i' || s1[j] =='o' || s1[j] =='u' || s1[j] =='A' || s1[j] =='E' || s1[j] =='I' || s1[j] =='O' || s1[j] =='U' ){
                cnt1++;
            }
        }
        
        for(int j=0;j<s2.size();j++){
            if(s2[j] =='a' || s2[j] =='e' || s2[j] =='i' || s2[j] =='o' || s2[j] =='u' || s2[j] =='A' || s2[j] =='E' || s2[j] =='I' || s2[j] =='O' || s2[j] =='U' ){
                cnt2++;
            }
        }
        
        if( cnt1 == cnt2){
            return true;
        }
        else{
            return false;
        }
        
    }
};
