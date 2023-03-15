//
// Created by jacopo on 02/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_CLOCK_H
#define LAB_PROGRAMMAZIONE_CLOCK_H
#include<wx/wx.h>
#include "ClockType.h"
class Clock:public wxPanel{
public:
    Clock(wxWindow* parent);
    virtual ~Clock();
    ClockType *getType() const;

wxDECLARE_EVENT_TABLE();

private:
    wxBoxSizer* mainS=nullptr;
    wxBoxSizer* choiceS=nullptr;

    wxTextCtrl* box=nullptr;
    wxTextCtrl* ap_box=nullptr;
    wxTextCtrl* date_box=nullptr;

    wxButton* clockB=nullptr;
    wxButton* timerB=nullptr;
    wxButton* chronoB=nullptr;

    ClockType* type=nullptr;

    void timerON(wxTimerEvent&);
};

#endif //LAB_PROGRAMMAZIONE_CLOCK_H
