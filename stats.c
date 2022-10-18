#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    double TotalCount;
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

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
