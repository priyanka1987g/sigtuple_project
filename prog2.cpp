// Problem2Sol.cpp : Defines the entry point for the console application.
//


#include<iostream>
#include <unordered_map>

using namespace std;
int main()
{
	int num;
	cin>>num;
	int *arr = new int[num];
	for(int i = 0; i < num; i++)
		cin>>arr[i];

    //int num = 5;
	//int arr[5] = {0,0,1,1,1};//{1,2,3,4,5};
	unordered_map<int, int> umap;
	for(int i = 0; i < num; i++)
	{
		umap[arr[i]] = i;
	}

	//take 2 int and check there sum exist in map or not
	int count = 0;
	for(int i = 0; i < num; i++)
		for(int j = i+1; j < num; j++)
		{
			int sum = arr[i]+arr[j];
			if(umap.find(sum)!=umap.end() && umap[sum]!=i && umap[sum]!=j)
			{
				count++;
			}
		}
	cout<<count;
	delete arr;
	return 0;
}

