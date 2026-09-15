#include "World/BloodstreamWorldTime.h"
void FBloodstreamWorldTime::Advance(double RealSeconds){ if(!bPaused && RealSeconds>0.0) AdvanceGameMinutes(RealSeconds*GameMinutesPerRealSecond); }
void FBloodstreamWorldTime::AdvanceGameMinutes(double Minutes){ if(Minutes<=0.0)return; double Days=DayFraction+Minutes/1440.0; const int32 Whole=FMath::FloorToInt(Days); DayIndex+=Whole; DayFraction=Days-Whole; }
