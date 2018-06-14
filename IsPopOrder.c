class Solution {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		if(pushV.empty())
			return false;
		stack<int> temp;
		for(int i=0,j=0;i<pushV.size();i++)
		{
			temp.push(pushV[i]);
			while(j<popV.size()&&temp.top()==popV[j])//根据出队表来对我临时的栈做出队操作
			{
				temp.pop();
				j++;
			}
		}
		return temp.empty();
	}
};
int main()
{
	Solution so;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(3);
	v2.push_back(2);
	v2.push_back(1);
	
	cout<<so.IsPopOrder(v1,v2)<<endl;
	system("pause");
	return 0;
}
