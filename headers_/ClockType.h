//
// Created by jacopo on 02/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_CLOCKTYPE_H
#define LAB_PROGRAMMAZIONE_CLOCKTYPE_H

#include<wx/wx.h>
enum class type{am_pm,normal,date};

class ClockType{
public:
    ClockType(wxEvtHandler* ev);
    virtual ~ClockType();
    wxTimer *getTimer() const;
    std::string toString(type t);
    void getCurrentTime();

    int getHours();
    void setHours(int h);

    int getMinutes();
    void setMinutes(int m);

    int getSeconds();
    void setSeconds(int s);

    int getDay();
    void setDay(int day);

    int getMonth();
    void setMonth(int month);

    int getYear();
    void setYear(int year);

private:
    int h;
    int m;
    int s;
    int day;
    int day_of_the_week;
    int month;
    int year;
    wxTimer* new_Timer=nullptr;
    static const int interval=1000;
};

#endif //LAB_PROGRAMMAZIONE_CLOCKTYPE_H
