//
// Created by jacopo on 01/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_MAINFRAME_H
#define LAB_PROGRAMMAZIONE_MAINFRAME_H
#include<wx/wx.h>
#include "Clock.h"
#include "Chrono.h"
#include "Timer.h"


class MainFrame:public wxFrame{
public:
    MainFrame();
    virtual ~MainFrame();
    wxDECLARE_EVENT_TABLE();
private:
    wxPanel* currentPanel=nullptr;

    void buildTimer(wxCommandEvent&);
    void buildClock(wxCommandEvent&);
    void buildChronometer(wxCommandEvent&);

};
#endif //LAB_PROGRAMMAZIONE_MAINFRAME_H
