//
// Created by jacopo on 09/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_CHRONO_H
#define LAB_PROGRAMMAZIONE_CHRONO_H

#include<wx/wx.h>
#include "ChronoType.h"
class Chrono: public wxPanel{
public:

    Chrono(wxWindow* parent);
    virtual ~Chrono();

    ChronoType *getType() const;

private:
    wxBoxSizer* mainS=nullptr;
    wxBoxSizer* choiceS=nullptr;
    wxBoxSizer* contS=nullptr;

    wxButton* clockB=nullptr;
    wxButton* timerB=nullptr;
    wxButton* chronoB=nullptr;
    wxButton* start=nullptr;
    wxButton* toZero=nullptr;

    wxTextCtrl* box=nullptr;
    wxTextCtrl* t_box=nullptr;

    ChronoType* type=nullptr;

wxDECLARE_EVENT_TABLE();

    void timerOn(wxTimerEvent&);
    void chronoOn(wxCommandEvent&);
    void chronoZero(wxCommandEvent&);
};


#endif //LAB_PROGRAMMAZIONE_CHRONO_H
