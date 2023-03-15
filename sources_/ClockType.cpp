//
// Created by jacopo on 02/08/22.
//

#include "../headers_/ClockType.h"
#include <ctime>

ClockType::ClockType(wxEvtHandler* ev) {
    new_Timer= new wxTimer(ev,4);
    new_Timer->Start(interval);
}

ClockType::~ClockType() {
    new_Timer->Stop();
    delete new_Timer;
}

std::string ClockType::toString(type t) {
    bool pm=false;
    if(t==type::am_pm){
        std::string am_pm_time="";

        if(h>12){
            pm=true;
            if(h-12<10)
                am_pm_time+="0"+std::to_string(h-12);
            else
                am_pm_time+=std::to_string(h-12);
        }else{
            if(h<10)
                am_pm_time+="0"+std::to_string(h);
            else
                am_pm_time+=std::to_string(h);
        }
        am_pm_time+=":";
        if(m>=10)
            am_pm_time+=std::to_string(m);
        else
            am_pm_time+="0"+std::to_string(m);
        am_pm_time+=":";
        if(s>=10)
            am_pm_time+=std::to_string(s);
        else
            am_pm_time+="0"+std::to_string(s);

        if(pm)
            am_pm_time+=" pm";
        else
            am_pm_time+=" am";
        return am_pm_time;
    }
    if(t==type::normal){
        std::string time="";
        if(h<10)
            time+="0"+std::to_string(h);
        else
            time+=std::to_string(h);
        if(m<10)
            time+=":0"+std::to_string(m);
        else
            time+=":"+std::to_string(m);
        if(s<10)
            time+=":0"+std::to_string(s);
        else
            time+=":"+std::to_string(s);
        return time;
    } // orario 24-h
    if(t==type::date){
        std::string SdayW;
        std::string Smonth;
        std::string Syear;
        std::string Sdate;

        if(day_of_the_week==0){SdayW="null";}
        if(day_of_the_week==1){SdayW="Monday";}
        if(day_of_the_week==2){SdayW="Tuesday";}
        if(day_of_the_week==3){SdayW="Wednesday";}
        if(day_of_the_week==4){SdayW="Thursday";}
        if(day_of_the_week==5){SdayW="Friday";}
        if(day_of_the_week==6){SdayW="Saturday";}
        if(day_of_the_week==7){SdayW="Sunday";}

        if(month==1){Smonth="January";}
        if(month==2){Smonth="February";}
        if(month==3){Smonth="March";}
        if(month==4){Smonth="April";}
        if(month==5){Smonth="May";}
        if(month==6){Smonth="June";}
        if(month==7){Smonth="July";}
        if(month==8){Smonth="August";}
        if(month==9){Smonth="September";}
        if(month==10){Smonth="October";}
        if(month==11){Smonth="November";}
        if(month==12){Smonth="December";}

        Syear=std::to_string(year);

        Sdate=SdayW+"    "+std::to_string(day)+"/"+Smonth+"/"+Syear;
        return Sdate;

    }// data europea
}

void ClockType::getCurrentTime() {
    std::time_t t=std::time(0);
    std::tm* currentTime=std::localtime(&t);
    h=currentTime->tm_hour;
    m=currentTime->tm_min;
    s=currentTime->tm_sec;
    day=currentTime->tm_mday;
    day_of_the_week=currentTime->tm_wday;
    month=currentTime->tm_mon+1;
    year=currentTime->tm_year+1900;
}


wxTimer *ClockType::getTimer() const {
    return new_Timer;
}

int ClockType::getHours() {
    return h;
}

void ClockType::setHours(int h) {
    ClockType::h=h;
}

int ClockType::getMinutes() {
    return m;
}

void ClockType::setMinutes(int m) {
    ClockType::m=m;
}

int ClockType::getSeconds() {
    return s;
}

void ClockType::setSeconds(int s) {
    ClockType::s=s;
}

int ClockType::getDay() {
    return day;
}

void ClockType::setDay(int day) {
    ClockType::day=day;
}

int ClockType::getMonth() {
    return month;
}

void ClockType::setMonth(int month) {
    ClockType::month=month;
}

int ClockType::getYear() {
    return year;
}

void ClockType::setYear(int year) {
    ClockType::year=year;
}