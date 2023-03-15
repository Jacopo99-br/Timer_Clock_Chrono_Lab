//
// Created by jacopo on 01/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_TIMERTYPE_H
#define LAB_PROGRAMMAZIONE_TIMERTYPE_H
#include<wx/wx.h>

class TimerType{
public:
    TimerType(wxEvtHandler *p);
    ~TimerType();

    int getSleft() const;
    void setSleft(int Sleft);

    int getMleft() const;
    void setMleft(int Mleft);

    int getHleft() const;
    void setHleft(int Hleft);

    bool isOn() const;
    void setOn(bool state);

    const std::string &getTimeLeft() const;
    void setTimeLeft(const std::string &TimeLeft);

    void start();
    void stop();
    void reset();
    void computeTime();
    void tempo();

private:
    int Sleft;
    int Mleft;
    int Hleft;
    bool state=false;
    std::string TimeLeft;
    wxTimer* timerN=nullptr;
    static const int interval=1000;

};
#endif //LAB_PROGRAMMAZIONE_TIMERTYPE_H
