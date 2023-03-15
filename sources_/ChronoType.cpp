//
// Created by jacopo on 09/08/22.
//
#include "../headers_/ChronoType.h"

ChronoType::ChronoType(wxEvtHandler* p) {
    new_Timer= new wxTimer(p, 14);
}

ChronoType::~ChronoType() {
    delete new_Timer;
}

void ChronoType::start() {
    new_Timer->Start(interval);
    isStop=false;
}

void ChronoType::stop() {
    new_Timer->Stop();
    isStop=true;
}

void ChronoType::time() {
    std::string time;
    std::string sH=std::to_string(h);
    std::string sM=std::to_string(m);
    std::string sS=std::to_string(s);
    std::string sC=std::to_string(cent);
    if(h>=10)
        time+=sH+":";
    else
        time+="0"+sH+":";
    if(m>=10)
        time+=sM+":";
    else
        time+="0"+sM+":";
    if(s>=10)
        time+=sS+",";
    else
        time+="0"+sS+",";
    if(cent>=10)
        time+=sC;
    else
        time+="0"+sC;
    t=time;
}

void ChronoType::computeTime() {
    if(m==59 && s==59 && cent==99){
        h++;
        s=0;
        m=0;
        cent=0;
    }
    else{
        if(s==59 && cent==99){
            m++;
            s=0;
            cent=0;
        }
        else{
            if(cent==99){
                s++;
                cent=0;
            } else{
                cent++;
            }
        }
    }
}

void ChronoType::turn_zero() {
    if(isStop==false) {
        new_Timer->Stop();
        isStop = true;
    }
    h=0;
    m=0;
    s=0;
    cent=0;
    t="00:00:00,00";
}

const std::string &ChronoType::getcurrenTime() const {
    return t;
}

bool ChronoType::isOff() const{
    return isStop;
}