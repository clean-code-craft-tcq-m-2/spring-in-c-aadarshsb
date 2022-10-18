#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    double TotalCount;
    if(0 == setlength || 0 == numberset)
    {
        s.average = 0.0/0.0;
        s.min = 0.0/0.0;
        s.max = 0.0/0.0;
        return s;
    }
   
    for( int iterator = 0; iterator < setlength; iterator++)
    {        
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
    s.average = (float) ( TotalCount / setlength );
    return s;
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
