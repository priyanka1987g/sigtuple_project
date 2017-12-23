// Problem1Sol.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int get_min_index(vector<int> arr,int low,int high)
{
	int min_val = 1000000;
	int min_index = 0;
	for(int i = low; i <= high; i++)
	{
		if(arr[i] >= 0 && arr[i] < min_val)
		{
			min_val = arr[i];
			min_index = i;
		}
	}
	//cout<<"min_val::"<<min_val<<endl;
	return min_index;
}

int get_max_index(vector<int> arr,int low,int high)
{
	int max_val = -1;
	int max_index = 0;
	for(int i = low; i <= high; i++)
	{
		if(arr[i] >= 0 && arr[i] > max_val)
		{
			max_val = arr[i];
			max_index = i;
		}
	}
	//cout<<"min_val::"<<min_val<<endl;
	return max_index;
}

int get_max_reward(vector<int> arr,int count)
{
	int min_index;
	int reward;
	int curr_reward = 0;
	int low,high;
	int flag = 0;
	if(arr[0] > arr[1])
		flag  = 1;
	for(int i = 1; i < count-1; i++)
	{
		if(flag)
			min_index = get_min_index(arr,1,count-2);
		else
			min_index = get_max_index(arr,1,count-2);
		reward = arr[min_index];
        //cout<<"min_index::"<<arr[min_index];
		arr[min_index] = -1;
		low = max(0,min_index - 1);
		high = min(min_index+1,count-1);
		while(low > -1)
		{
			if(arr[low] != -1)
			{
				reward *= arr[low]; 
				low = -1;
			}
			low--;
		}
		while(high < count)
		{
			if(arr[high] != -1)
			{
				reward *= arr[high]; 
				high = count;
			}
			high++;
		}
		curr_reward += reward;
		//cout<<"rewatd::"<<reward<<"curr_reward::"<<curr_reward<<endl;
	}
	
    curr_reward += arr[0]*arr[count-1]+arr[count-1];
	return curr_reward;
}

int main()
{
	//int arr[4] = {4,2,6,8};
    //int arr[17] = {44, 53, 36, 42, 40, 48, 54, 50, 45, 54, 45, 38, 35, 45, 45, 54, 38};
	ifstream myfile;
	string line;
	vector<int> arr;
	
    myfile.open ("input.txt");
	
	if (myfile.is_open())
    {


	while(myfile)
	{
		string s;
		if(!getline(myfile,s)) break;
		istringstream ss(s);
		while(ss)
		{
			string s;
			if(!getline(ss,s,',')) break;
			int x = 0;
			stringstream sx(s);
			sx >> x;
			arr.push_back(x);
		}
	}
    myfile.close();
  }
	int count = arr.size();
 
	int reward = get_max_reward(arr,count);
	cout<<reward;
	
	return 0;
}

