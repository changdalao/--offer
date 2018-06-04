class Solution {
public:
    bool match(char* str, char* pattern)
    {
	    if (*str == NULL && *pattern == NULL)
                return true;
            if (*str != NULL && *pattern == NULL)
                return false;
            if (*(pattern+1) != '*')
            {
                if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                    return match(str+1, pattern+1);
                else
		    return false;
            }
            else 
            {
                if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                    return match(str, pattern+2) || match(str+1, pattern);
                else
                    return match(str, pattern+2);
            }
    }
};
int main()
{
	Solution s;
	char* str="aaa";
	char* pat="aa*a";
	char* pt="ab*ac*a";
	cout<<s.match(str,pat)<<endl;
	system("pause");
	return 0;
}
