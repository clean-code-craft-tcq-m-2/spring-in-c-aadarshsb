#ifndef ALETERS_H
#define ALETERS_H

#include "stats.h"

extern alerter_funcptr emailAlerter;
extern alerter_funcptr ledAlerter;

void emailAlerterfn();
void ledAlerterfn();

#endif //ALETERS_H
