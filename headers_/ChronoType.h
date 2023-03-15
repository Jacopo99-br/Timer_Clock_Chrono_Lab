//
// Created by jacopo on 08/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_CHRONOTYPE_H
#define LAB_PROGRAMMAZIONE_CHRONOTYPE_H

#include<wx/wx.h>

class ChronoType {
public:
    ChronoType(wxEvtHandler* p);

    virtual ~ChronoType();
    void start();
    void stop();
    void computeTime();
    void time();
    bool isOff() const;
    void turn_zero();
    const std::string &getcurrenTime() const;
private:
    wxTimer* new_Timer=nullptr;
    static const int interval=10;
    int h=0;
    int m=0;
    int s=0;
    int cent=0;
    std::string t="00:00:00,00";
    bool isStop=true;
};


#endif //LAB_PROGRAMMAZIONE_CHRONOTYPE_H
