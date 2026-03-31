#ifndef SEDHOM_TIME_H_
#define SEDHOM_TIME_H_
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#include "SEDHOM_Display_Settings.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
class SEDHOM_Time
{
  private:
    //
  public:
    void Stop_Display(int time);
    void Wait(int time);
    unsigned long Calc_time_ms();
    unsigned long Calc_time_us();
};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
// define all functions
void SEDHOM_Time::Wait(int time_ms)
{
    wait_time(time_ms);
}
void SEDHOM_Time::Stop_Display(int time_ms)
{
    Wait(time_ms);
}
unsigned long SEDHOM_Time::Calc_time_us()
{
    return micros_func();
}
unsigned long SEDHOM_Time::Calc_time_ms()
{
    return Calc_time_us() / 1000UL;
}
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#endif // !SEDHOM_TIME_H