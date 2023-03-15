//
// Created by jacopo on 09/08/22.
//

#include "../headers_/Chrono.h"

wxBEGIN_EVENT_TABLE(Chrono, wxPanel)
EVT_BUTTON(12, Chrono::chronoOn)
EVT_BUTTON(13, Chrono::chronoZero)
EVT_TIMER(14, Chrono::timerOn)
wxEND_EVENT_TABLE()

Chrono::Chrono(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(720,250)) {
    mainS=new wxBoxSizer(wxVERTICAL);
    choiceS=new wxBoxSizer(wxHORIZONTAL);
    contS=new wxBoxSizer(wxHORIZONTAL);

    wxFont main_font=wxFont(20, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    wxFont font=wxFont(17, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL);

    box=new wxTextCtrl(this, wxID_ANY,"00:00:00,00", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE| wxTE_READONLY | wxTE_RICH2 | wxTE_CENTER | wxBORDER);
    box->SetFont(main_font);

    clockB=new wxButton(this,10,"Clock", wxDefaultPosition,wxSize(227,50));
    clockB->SetFont(font);

    timerB=new wxButton(this, 11, "Timer", wxDefaultPosition, wxSize(227,50));
    timerB->SetFont(font);

    chronoB=new wxButton(this, 12, "Chronometer", wxDefaultPosition, wxSize(227,50));
    chronoB->SetFont(font);
    chronoB->Enable(false);
    chronoB->SetBackgroundColour(*wxLIGHT_GREY);

    start=new wxButton(this, 12, "Start", wxDefaultPosition, wxSize(345,40));
    start->SetFont(font);
    start->SetBackgroundColour(*wxGREEN);

    toZero=new wxButton(this, 13, "Reset", wxDefaultPosition, wxSize(345,40));
    toZero->SetFont(font);
    toZero->SetBackgroundColour(*wxRED);

    choiceS->Add(clockB, 0, wxEXPAND| wxALL, 5);
    choiceS->Add(timerB, 0, wxEXPAND| wxALL, 5);
    choiceS->Add(chronoB, 0, wxEXPAND| wxALL, 5);

    contS->Add(start,0,wxEXPAND|wxALL,5);
    contS->Add(toZero,0,wxEXPAND|wxALL,5);

    mainS->Add(choiceS,0,wxEXPAND|wxALL,0);
    mainS->Add(contS,0,wxEXPAND|wxALL,0);
    mainS->Add(box,1,wxEXPAND|wxALL,5);

    SetSizerAndFit(mainS);
    SetAutoLayout(true);

    type=new ChronoType(this);
}

Chrono::~Chrono() {
    delete type;
}

void Chrono::timerOn(wxTimerEvent &) {
    type->computeTime();
    type->time();
    std::string t=type->getcurrenTime();
    box->SetValue(t);
}

void Chrono::chronoOn(wxCommandEvent &){
    if(type->isOff()){
        type->start();
        start->SetLabel("Stop");
        start->SetBackgroundColour(*wxYELLOW);
    }
    else{
        type->stop();
        start->SetLabel("Start");
        start->SetBackgroundColour(*wxGREEN);
    }
}

void Chrono::chronoZero(wxCommandEvent &){
    type->turn_zero();
    std::string t=type->getcurrenTime();
    box->SetValue(t);
    start->SetLabel("Start");
    start->SetBackgroundColour(*wxGREEN);
}

ChronoType *Chrono::getType() const {
    return type;
}
