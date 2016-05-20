#include <iostream>
#include <string>
#include <vector>
using namespace std;

string STRCONSTDAYS[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void CalcWeeklyCalendar(const int iDates, const int iMonths, const string strDays, vector<int>& vecResults);

int main()
{
	int iNumOfTestCase;

	vector<int> arrDates;
	vector<int> arrMonths;
	vector<string> arrDays;
	vector<int> arrResults;
	cin >> iNumOfTestCase;

	for(int i = 0; i < iNumOfTestCase; i++)
	{
		int iDate, iMonth;
		string strDays;
		cin >> iMonth >> iDate >> strDays;
		arrMonths.push_back(iMonth);
		arrDates.push_back(iDate);
		arrDays.push_back(strDays);
	}

	for(int i = 0; i < iNumOfTestCase; i++)
	{
		CalcWeeklyCalendar(arrDates[i], arrMonths[i], arrDays[i], arrResults);
		for(int j = 0; j < 7; j++)
		{
			cout << arrResults[j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void CalcWeeklyCalendar(const int iDates, const int iMonths, const string strDays, vector<int>& vecResults)
{
	vecResults.clear();
	vecResults.resize(7, -1);
	int iCurDay = -1;
	for(int i = 0; i < 7; i++)
	{
		if(strDays.compare(STRCONSTDAYS[i]) == 0)
		{
			iCurDay = i;
			vecResults[i] = iDates;
		}
	}

	int iCurLastDay, iPreLastDay;
	switch(iMonths)
	{
	case 1:
	case 8:
		iPreLastDay = 31;
		iCurLastDay = 31;
		break;
	case 2:
		iPreLastDay = 31;
		iCurLastDay = 28;
		break;
	case 3:
		iPreLastDay = 28;
		iCurLastDay = 31;
	case 4:	case 6:	case 9:	case 11:
		iPreLastDay = 31;
		iCurLastDay = 30;
		break;
	default:
		iPreLastDay = 30;
		iCurLastDay = 31;
		break;
	}

	int iDecVal = 1;
	for(int i = 1; iCurDay - i >= 0; i++)
	{
		int date = iDates - i;
		if(date< 1)
		{
			date += iPreLastDay;
		}
		vecResults[iCurDay - i] = date;
	}

	for(int i = 1; iCurDay + i < 7; i++)
	{
		int date = iDates + i;
		if(date > iCurLastDay)
		{
			date -= iCurLastDay;
		}
		vecResults[iCurDay + i] = date;
	}
	return;
}