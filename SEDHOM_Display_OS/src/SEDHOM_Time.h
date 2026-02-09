#ifndef SEDHOM_TIME_H_
#define SEDHOM_TIME_H_
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#include "SEDHOM_Display_Settings.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SEDHOM_OS_Stop_Display(time)                        wait_time(time);
#define SEDHOM_OS_Wait(time)                                wait_time(time);
#define SEDHOM_OS_Calc_time_ms()                            millis_func();
#define SEDHOM_OS_Calc_time_us()                            milcros_func();
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
void SEDHOM_Time::Stop_Display(int time_ms)
{
    SEDHOM_OS_Stop_Display(time_ms);
}
void SEDHOM_Time::Wait(int time_ms)
{
    SEDHOM_OS_Wait(time_ms);
}
unsigned long SEDHOM_Time::Calc_time_ms()
{
    return SEDHOM_OS_Calc_time_ms();
}
unsigned long SEDHOM_Time::Calc_time_us()
{
    return SEDHOM_OS_Calc_time_us();
}
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#endif // !SEDHOM_TIME_H