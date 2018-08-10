class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0) return false;
        return verify(sequence);
    }
        bool verify(vector<int> sequence){
        if(sequence.size()==1||sequence.size()==0) return true;
        vector<int> left;
        vector<int> right;
        int n=sequence.size()-1;
        int i=0;
        int root=sequence[n];
        while(sequence[i]<root) left.push_back(sequence[i++]);
        while(sequence[i]>root) right.push_back(sequence[i++]);
        if(i<n) return false;
        return verify(left)&&verify(right);
    }
};
