#include<iostream>
using namespace std;

//1.找出数组中重复的数字
//{2,3,1,0,2,5,3}-->2,3
size_t GetNextPrimeNum(size_t num)//解决哈希冲突，采用随机数表
{
	const int _PrimeSize = 28;
	static const unsigned long _PrimeList[] =
	{
		53ul,97ul,193ul,389ul,769ul,1543ul,3079ul,
		6151ul,12289ul,24593ul,49157ul,98317ul,196613ul,393241ul,
		786433ul,1572869ul,3145739ul,6291469ul,12582917ul, 25165843ul,
		50331653ul,100663319ul,201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (size_t i = 0; i < _PrimeSize; i++)
	{
		if (_PrimeList[i] > num)
			return _PrimeList[i];
	}
}
int HashFunc(int key,size_t num)//哈希方法
{
	return key % num;
}
void Test1()
{
	int arr[] = { 2,3,1,0,2,5,3,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* Arr = (int*)malloc(len*(sizeof (int)));
	memset(Arr,sizeof(Arr)/sizeof(Arr[0]),0 );
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		index = HashFunc(arr[i], len);
		if (Arr[index] != arr[i])//如果哈希表没有这个数字，则入表，如果有，则说明这个数字是重复的，输出
		{
			Arr[index] = arr[i];
		}	
		else
			printf("%d ", arr[i]);
	}
	printf("\n");
}
