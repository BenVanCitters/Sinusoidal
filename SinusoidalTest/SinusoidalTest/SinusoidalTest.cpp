
#include "pch.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <chrono>
//#include <math.h>
#include <cmath>

using namespace std;
long long getMillis()
{
	// there are a few online resources out there that suggest to use
	// this class to retrieve time with c++
	// https://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()).count();
}

int main()
{
	
    cout << "Here is the output of the sin\n"; 
	while (true)
	{
		system("CLS");
		long long millis = getMillis();
		float fmillis = (float)millis;

		cout << "milliseconds as a long long:" << millis << "\t" << " sin(millis): " << sin(millis) << endl;
		cout << "milliseconds as a float:" << fmillis << "\t" << " sin(fmillis): " << sin(fmillis) << endl;

		unsigned int pi2000 = (unsigned int)(M_PI*2.0*1000);
		long long modulatedMillis = millis % pi2000;

		cout << "modulatedMillis:" << modulatedMillis << "\t" << " sin(modulatedMillis): " << sin(modulatedMillis) << endl;

	}
}