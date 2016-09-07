#include <iostream>
#include <map>

using namespace std;

bool isValid(string data)
{
	//if data is a single char then it is always valid
	if(data.size() == 1)
		return true;

	//if data is empty then assume false?
	if(!data.size())
		return false;

	//go through the string and map the count of each char
	map<char,int> charCount;
	for(int i = 0; i < data.size(); i++)
	{
		charCount[data[i]]++;
	}
	auto it = charCount.begin();

	//find the min and max val of map
	int minVal = charCount.at(data[0]);
	int maxVal = charCount.at(data[0]);
	for(it; it != charCount.end(); it++)
	{
		if(it->second > maxVal)
			maxVal = it->second;
		if(it->second < minVal)
			minVal = it->second;
	}

	//if the minVal is the same as the maxVal then all chars appear the same number of times and thus is valid
	if(minVal == maxVal)
		return true;

	//find the frequency of the min and max count in the map
	int minFreq = 0;
	int maxFreq = 0;
	for(it = charCount.begin(); it != charCount.end(); it++)
	{
		if(it->second == minVal)
			minFreq++;
		if(it->second == maxVal)
			maxFreq++;
	}

	//if minFreq == maxFreq then the string is not valid || if the maxFreq and minFreq are both greater than 1 then invalid
	//else if minVal or maxVal is off by a factor of 1 then string is valid
	//else if min/max Frequency is off by 1 of the map size then a single char can be cut out to make the string valid
	if((minFreq == maxFreq) || (maxFreq != 1 && minFreq != 1))
		return false;
	else if(maxFreq == charCount.size()-1 || minFreq == charCount.size()-1)
		return true;
	else if(minVal-1 == maxVal || minVal == maxVal-1)
		return true;
	else
		return false;
}

int main()
{
	string data;
	getline(cin,data);
	bool valid = isValid(data);
	if(valid)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}