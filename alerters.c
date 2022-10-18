#include "alerters.h"
#include "stats.h"

emailAlerter = &emailAlerterfn;
ledAlerter = &ledAlerterfn;

void emailAlerterfn()
{
  emailAlertCallCount++;
}
void ledAlerterfn()
{
  ledAlertCallCount++;
}
