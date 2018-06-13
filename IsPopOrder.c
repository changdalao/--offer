class Solution {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		stack<int> s;
		vector<int>::iterator it=popV.begin();
		vector<int>::iterator itp=pushV.begin();
		while(!pushV.empty() || s.top()!=(*it)){
			if(itp < pushV.end()){
				s.push(*itp);
				itp++;
			}
			else
				;
			if(s.top()==*it&&!s.empty()){
				s.pop();
				it++;
			}
			if(pushV.empty()&&!popV.empty() || s.top()!=*it)
				return false;
		}
			return true;
	}
};
