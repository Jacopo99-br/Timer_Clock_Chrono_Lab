//
// Created by jacopo on 05/08/22.
//
//
// Created by leonardo on 29/12/21.
//

#include "../headers_/TimerType.h"

TimerType::TimerType(wxEvtHandler *p) {
    timerN=new wxTimer(p,9);
}

TimerType::~TimerType() {
    delete timerN;
}

int TimerType::getSleft() const {
    return Sleft;
}

void TimerType::setSleft(int sleft) {
    Sleft = sleft;
}

int TimerType::getMleft() const {
    return Mleft;
}

void TimerType::setMleft(int mleft) {
    Mleft = mleft;
}

int TimerType::getHleft() const {
    return Hleft;
}

void TimerType::setHleft(int hleft) {
    Hleft = hleft;
}

bool TimerType::isOn() const {
    return state;
}

void TimerType::setOn(bool state) {
    TimerType::state = state;
}

const std::string &TimerType::getTimeLeft() const {
    return TimeLeft;
}

void TimerType::setTimeLeft(const std::string &TimeLeft) {
    TimerType::TimeLeft = TimeLeft;
}

void TimerType::tempo() {
    std::string time;
    std::string h=std::to_string(Hleft);
    std::string m=std::to_string(Mleft);
    std::string s=std::to_string(Sleft);
    if(Hleft>=10)
        time=time+h+":";
    else
        time=time+"0"+h+":";
    if(Mleft>=10)
        time=time+m+":";
    else
        time=time+"0"+m+":";
    if(Sleft>=10)
        time=time+s;
    else
        time=time+"0"+s;
    TimeLeft=time;
}

void TimerType::computeTime(){
    while(Sleft>59){
        Sleft-=60;
        Mleft++;
    }

    while(Mleft>59){
        Mleft-=60;
        Hleft++;
    }

    if(Sleft==0 && Mleft==0 && Hleft==0){
        timerN->Stop();
        state=false;
    }
    else{
        if(Sleft==0 && Mleft==0){
            Hleft--;
            Sleft=59;
            Mleft=59;
        }
        else{
            if(Sleft==0){
                Mleft--;
                Sleft=59;
            } else{
                Sleft--;
            }
        }
    }
}

void TimerType::start() {
    timerN->Start(interval);
    state=true;
}
void TimerType::timerN_start(int milliseconds){
    timerN->Start(milliseconds);
}
void TimerType::stop() {
    timerN->Stop();
    state=false;
}
void TimerType::reset() {
    state=false;
    this->stop();
    this->setSleft(0);
    this->setMleft(0);
    this->setHleft(0);
}

