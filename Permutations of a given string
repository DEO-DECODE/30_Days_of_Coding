class Solution
{
	public:
	 vector<string> ans;
 void perm(string &str, int ind, int len){
     if(ind==len) {
        ans.push_back(str);
        return;
     }
     for(int j=ind; j<str.length(); j++){
         swap(str[j], str[ind]);
         perm(str,ind+1,str.length());
         swap(str[j], str[ind]);
     }

 }
		vector<string>find_permutation(string str)
		{
		    // Code here there
		     perm(str, 0, str.length());
            sort(ans.begin(), ans.end());
            return ans;
		}
};

