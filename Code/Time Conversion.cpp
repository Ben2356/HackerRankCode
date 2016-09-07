#include <iostream>
#include <string>

using namespace std;

int main()
{
	string data;
	getline(cin,data);
	bool isDone = false;	

	int end = data.find(":");
	string hour = data.substr(0,end);
	
    if(data.find("AM") != -1 && atoi(hour.c_str()) == 12)
    {
        data = data.substr(end+1);
		int hourAdj = atoi(hour.c_str())-12;
		string strHour = to_string(hourAdj) + "0:";
		int cutTimePoint = data.find("A") == -1 ? data.find("P") : data.find("A");
		data = data.substr(0,cutTimePoint);
		data.insert(0,strHour);
    }
	else if(data.find("AM") != -1 || (data.find("PM") && atoi(hour.c_str()) == 12))
	{
		//hour doesn't need to be adjusted and AM/PM needs to be cut out
		int cutTimePoint = data.find("A") == -1 ? data.find("P") : data.find("A");
		data = data.substr(0,cutTimePoint);
	}
	//else the hour will need to be adjusted 
	else
	{
		data = data.substr(end+1);
		int hourAdj = atoi(hour.c_str())+12;
		string strHour = to_string(hourAdj) + ":";
		int cutTimePoint = data.find("A") == -1 ? data.find("P") : data.find("A");
		data = data.substr(0,cutTimePoint);
		data.insert(0,strHour);
	}
	cout << data << endl;
	return 0;
}