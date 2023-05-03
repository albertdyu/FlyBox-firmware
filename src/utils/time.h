#ifndef time_h
#define time_h

typedef struct Time {
  int day;
  int hour;
  int min;
};

Time* initTime();
Time* setTimeStruct(unsigned int day, unsigned int hour, unsigned int min);
void updateCurrentTime();
RTC_DS3231 initRTC();
void addGlobalMinuteOffset();
void addGlobalHourOffset();
void dispTime(Time* time, int x, int y);


#endif