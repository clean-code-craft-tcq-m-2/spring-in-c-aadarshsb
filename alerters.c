#include "alerters.h"
#include "stats.h"

alerter_funcptr emailAlerter = &emailAlerterfn;
alerter_funcptr ledAlerter = &ledAlerterfn;

void emailAlerterfn()
{
  emailAlertCallCount++;
}
void ledAlerterfn()
{
  ledAlertCallCount++;
}
