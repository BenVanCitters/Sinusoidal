
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

// fails horrendously when the exponent of the floating point variable becomes too large
// inevitably - floating point representations of 'time' become farther and farther apart
// causing time to have the character of a stepping slope
double naiveSin(long long time)
{
	double d_time = time * 1.0;
	return sin(time);
}



// using the 'fraction' technique 
// a*t+m; a is frequency, t is time, m is offset
double sin_frac(long long time_millis, float a, float offset_seconds)
{
	//we gotta use lots of digits so that there isn't a loss of precision 
	// when and if they become significant
	//these should probably be #defined
	const long long reallyBigTwoPI = (31415926535897 * 2);
	const long long reallyBigTwoPIDenom = 10000000000;

	//convert the floating point representation into int milliseconds
	long long a_ll_millis = a * 1000;
	long long cycleLength_millis = (reallyBigTwoPI * 1000) / (a_ll_millis*reallyBigTwoPIDenom);

	long long offset_ll_millis = offset_seconds * 1000;

	long long multed_time = (time_millis*a_ll_millis) / 1000;
	long long ll_time_with_offset = offset_ll_millis + time_millis;
	long long ll_modded_tm = multed_time % cycleLength_millis;

	//finally convert 'time' to floating point
	double float_time = ll_modded_tm / 1000.0;
	double sinVal = sin(float_time + offset_seconds);
	cout << "sinVal: " << sinVal << " float_time: " << float_time << " ll_modded_tm: " << ll_modded_tm << " cycleLength_millis: " << cycleLength_millis << endl;
	return sinVal;
}

// minimizing casts to float and operations that otherwise reduce accuracy
// a*t+m; a is frequency, t is time, m is offset
double sin_mod(long long time_millis, double a, double offset_seconds)
{	
	//hopefully this value doesn't blow out the floating pt math :(
	// this function will be more precise if more digits of pi can be preserved...
	double func_periodLengthSeconds = (2.0*M_PI) / a;
	long long func_periodLengthMilliseconds = long long(func_periodLengthSeconds*1000.0);
	long long period_mod_time = time_millis % func_periodLengthMilliseconds;
	
	//finally convert 'time' to floating point
	double float_time =  period_mod_time / 1000.0;
	double sinVal = sin(func_periodLengthSeconds*float_time+offset_seconds);
	cout << "sinVal: " << sinVal << " float_time: " << float_time << " ll_modded_tm: " << period_mod_time << " func_periodLengthMilliseconds: " << func_periodLengthMilliseconds << endl;
	return sinVal;
}

//takes a independent variable and loops it over on itself to help preserve
// it's floating point representation
long long getMillisForSin(long long time_millis, double a)
{
	//hopefully this value doesn't blow out the floating pt math :(
// this function will be more precise if more digits of pi can be preserved...
	double func_periodLengthSeconds = (2.0*M_PI) / a;
	long long func_periodLengthMilliseconds = long long(func_periodLengthSeconds*1000.0);
	long long period_mod_time = time_millis % func_periodLengthMilliseconds;
	return period_mod_time;
}

//example of using fractions for division
void fractionsExample()
{
	// a*t+m; a is frequency, t is time, m is offset
	long long time_milliseconds = getMillis();
	float a_float = 0.5;	
	float offset = 6.1;
	double sin_result = sin_mod(time_milliseconds, a_float, offset);
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

		long long top = 8889;
		long long bottom = 1000;
		float f_result = 10*(float(top) / float(bottom));
		long long ll_result1 = 10*(top / bottom);
		long long ll_result2 = (top*10) / bottom;
		cout << "l1: " << ll_result1 << " l2: " << ll_result2 << endl;
		fractionsExample();
	}
}