//
// Created by jacopo on 01/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_TIMER_H
#define LAB_PROGRAMMAZIONE_TIMER_H
#include <wx/wx.h>
#include "TimerType.h"

class Timer: public wxPanel{
public:
    Timer(wxWindow* parent);
    virtual ~Timer();

    TimerType *getType() const; //ottengo il puntatore al tipo di Timer impostato come costante;
    wxDECLARE_EVENT_TABLE();
    void TimerOn(wxTimerEvent&); //riferimento all'evento invocato;
    void ONclick(wxCommandEvent&); //
    void Reset(wxCommandEvent&);

private:
    wxBoxSizer* mainS=nullptr;
    wxBoxSizer* choiceS=nullptr;
    wxBoxSizer* sizeIns=nullptr;

    wxTextCtrl* HoursBox=nullptr;
    wxTextCtrl* SepABox=nullptr;
    wxTextCtrl* MinutesBox=nullptr;
    wxTextCtrl* SepBBox=nullptr;
    wxTextCtrl* SecondsBox=nullptr;
    wxTextCtrl* Box=nullptr;

    wxButton* ClockB=nullptr;
    wxButton* TimerB=nullptr;
    wxButton* ChronoB=nullptr;
    wxButton* StartB=nullptr;
    wxButton* ResetB=nullptr;

    TimerType* type=nullptr;

};
#endif //LAB_PROGRAMMAZIONE_TIMER_H
