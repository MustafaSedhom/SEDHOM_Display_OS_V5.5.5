//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
#pragma once
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
#include "SEDHOM_Display_Settings.h"
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
class SEDHOM_Time
{
    private:
        static constexpr double TIME_UNIT_FACTORS_SEC[ Time_Unit_Count ] = {
            0.000001,       // Micros
            0.001,           // Millis
            1.0,             // Second
            60.0,            // Minute
            3600.0,          // Hour
            86400.0,         // Day
            604800.0,        // Week
            2592000.0,       // Month
            31536000.0       // Year
        };
    public:
        // ==========================================
        // Time Conversion
        // ==========================================
        double Convert_Time(double value,Time_Unit_t Unit,Time_Unit_t Return_Unit = Time_Unit_Millis_Second);
        // ==========================================
        // Delay
        // ==========================================
        void Wait(double time,Time_Unit_t unit = Time_Unit_Millis_Second);
        void Stop_Display(double time,Time_Unit_t unit = Time_Unit_Millis_Second);
        // ==========================================
        // Time
        // ==========================================
        unsigned long Now_Time(Time_Unit_t return_time = Time_Unit_Millis_Second);
};
// =================================================
// Functions
// =================================================
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
double SEDHOM_Time::Convert_Time(double value,Time_Unit_t Unit,Time_Unit_t Return_Unit = Time_Unit_Millis_Second)
{
    if (
        Unit >= Time_Unit_Count ||
        Return_Unit >= Time_Unit_Count
    )
    {
        return 0.0;
    }

    double seconds =
        value *
        TIME_UNIT_FACTORS_SEC[Unit];

    return
        seconds /
        TIME_UNIT_FACTORS_SEC[Return_Unit];
}
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
void SEDHOM_Time::Wait(double time, Time_Unit_t unit)
{
    unsigned long wait_duration_us = (unsigned long)Convert_Time(time, unit, Time_Unit_Micros_Second);    
    if (wait_duration_us == 0) return;
    unsigned long start_us = Now_Time(Time_Unit_Micros_Second);
    while ((Now_Time(Time_Unit_Micros_Second) - start_us) < wait_duration_us)
    {
        #if defined(ESP32) || defined(ESP8266)
            yield();
        #endif
    }
}
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
void SEDHOM_Time::Stop_Display(double time,Time_Unit_t unit)
{
    Wait(time, unit);
}
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
unsigned long SEDHOM_Time::Now_Time(Time_Unit_t return_time)
{
    unsigned long micros_time = API_Micros_Function();

    return (unsigned long)Convert_Time(
        micros_time,
        Time_Unit_Micros_Second,
        return_time
    );
}
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''