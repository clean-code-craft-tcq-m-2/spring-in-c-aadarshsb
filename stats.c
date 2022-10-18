#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    double TotalCount;
    uint8_t IsNaN = 0;
    for( int iterator = 0; iterator < setlength; iterator++)
    {
        //Check, in any case, there should not be NaN
        //If one NaN is found, then set the average, min and max as NaN and break out of the loop
        if(isnan(numberset[iterator]))
        {
            s.average = numberset[iterator];
            s.min = numberset[iterator];
            s.max = numberset[iterator];
            IsNaN = 1;
            break;
        }
        
        TotalCount += numberset[iterator];
        if( s.min > numberset[iterator] )
        {
            s.min = numberset[iterator]; 
        }
        if( s.max < numberset[iterator])
        {
            s.max = numberset[iterator];
        }
    }
    if(1 == IsNaN)
        return s;
    else
    {
        s.average = (float) ( TotalCount / setlength );
        return s;
    }
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    //todo-create a separate .c and .h for fnptr alerters function( email and LED).
    if(computedStats.max > maxThreshold)
    {
        //Here check the condition and call the email and led alerter
        //and modify the email and led alert count there in fn pointer
        alerters[0]();
        alerters[1]();
    }
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
