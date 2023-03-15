//
// Created by jacopo on 05/08/22.
//

#include "../headers_/Clock.h"
#include <ctime>

wxBEGIN_EVENT_TABLE(Clock,wxPanel)
EVT_TIMER(4,Clock::timerON)
wxEND_EVENT_TABLE()

Clock::Clock(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition,wxSize(720,250)){
    mainS=new wxBoxSizer(wxVERTICAL);
    choiceS=new wxBoxSizer(wxHORIZONTAL);

    wxFont main_font=wxFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD);
    wxFont font=wxFont(17,wxFONTFAMILY_ROMAN,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_NORMAL);

    box=new wxTextCtrl(this,wxID_ANY, wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER| wxBORDER_DEFAULT);
    box->SetFont(main_font);

    ap_box=new wxTextCtrl(this,wxID_ANY, wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER| wxBORDER_DEFAULT);
    ap_box->SetFont(main_font);

    date_box=new wxTextCtrl(this,wxID_ANY, wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER| wxBORDER_DEFAULT);
    date_box->SetFont(main_font);

    clockB=new wxButton(this,1,"Clock",wxDefaultPosition,wxSize(227,50));
    clockB->SetFont(font);
    clockB->Enable(false);
    clockB->SetBackgroundColour(*wxLIGHT_GREY);

    timerB=new wxButton(this,2,"Timer",wxDefaultPosition,wxSize(227,50));
    timerB->SetFont(font);

    chronoB=new wxButton(this,3,"Chronometer",wxDefaultPosition,wxSize(227,50));
    chronoB->SetFont(font);

    choiceS->Add(clockB,0,wxEXPAND| wxALL, 5);
    choiceS->Add(timerB,0,wxEXPAND| wxALL, 5);
    choiceS->Add(chronoB,0,wxEXPAND| wxALL, 5);

    mainS->Add(choiceS,0,wxEXPAND| wxALL, 0);
    mainS->Add(box,1,wxEXPAND| wxALL, 5);
    mainS->Add(ap_box,1,wxEXPAND| wxALL, 5);
    mainS->Add(date_box,1,wxEXPAND| wxALL, 5);

    SetSizerAndFit(mainS);
    SetAutoLayout(true);

    type=new ClockType(this);
}

Clock::~Clock(){
    delete type;
}

void Clock::timerON(wxTimerEvent &){
    type->getCurrentTime();
    box->SetValue(type->toString(type::normal));
    ap_box->SetValue(type->toString(type::am_pm));
    date_box->SetValue(type->toString(type::date));
}

ClockType *Clock::getType() const {
    return type;
}
