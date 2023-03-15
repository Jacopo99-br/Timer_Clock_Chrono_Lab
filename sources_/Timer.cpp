//
// Created by jacopo on 05/08/22.
//
#include "../headers_/Timer.h"

wxBEGIN_EVENT_TABLE(Timer, wxPanel)
                EVT_BUTTON(8, Timer::ONclick)
                EVT_BUTTON(9, Timer::Reset)
                EVT_TIMER(9, Timer::TimerOn)
wxEND_EVENT_TABLE()

Timer::Timer(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(720,250)) {
    mainS=new wxBoxSizer(wxVERTICAL);
    choiceS=new wxBoxSizer(wxHORIZONTAL);

    wxFont main_font=wxFont(20, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    wxFont font=wxFont(17, wxFONTFAMILY_ROMAN, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL);

    ClockB=new wxButton(this,5,"Clock", wxDefaultPosition, wxSize(227,50));
    ClockB->SetFont(font);

    TimerB=new wxButton(this, 6, "Timer",wxDefaultPosition, wxSize(227,50));
    TimerB->SetFont(font);
    TimerB->Enable(false);
    TimerB->SetBackgroundColour(*wxLIGHT_GREY);

    ChronoB=new wxButton(this, 7, "Chronometer",wxDefaultPosition,wxSize(227,50));
    ChronoB->SetFont(font);

    sizeIns=new wxBoxSizer(wxHORIZONTAL);
    HoursBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(200,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    HoursBox ->SetFont(main_font);
    SepABox = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(40,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    SepABox ->SetFont(main_font);
    MinutesBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(200,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    MinutesBox ->SetFont(main_font);
    SepBBox = new wxTextCtrl(this, wxID_ANY, ":", wxDefaultPosition, wxSize(40,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER | wxTE_READONLY | wxBORDER_NONE);
    SepBBox ->SetFont(main_font);
    SecondsBox = new wxTextCtrl(this, wxID_ANY, "00", wxDefaultPosition, wxSize(200,40), wxTE_MULTILINE | wxTE_RICH2 | wxTE_CENTER);
    SecondsBox ->SetFont(main_font);


    sizeIns->Add(HoursBox, 0, wxEXPAND | wxALL, 5);
    sizeIns->Add(SepABox, 0, wxEXPAND | wxALL, 0);
    sizeIns->Add(MinutesBox, 0, wxEXPAND | wxALL, 5);
    sizeIns->Add(SepBBox, 0, wxEXPAND | wxALL, 0);
    sizeIns->Add(SecondsBox, 0, wxEXPAND | wxALL, 5);

    StartB=new wxButton(this, 8, "Start", wxDefaultPosition, wxDefaultSize);
    StartB->SetFont(font);
    StartB->SetBackgroundColour(*wxGREEN);

    ResetB=new wxButton(this,9,"Reset",wxDefaultPosition,wxDefaultSize);
    ResetB->SetFont(font);
    ResetB->SetBackgroundColour(*wxLIGHT_GREY);
    ResetB->Enable(false);

    Box=new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2|wxTE_CENTER|wxBORDER_NONE);
    Box->SetFont(main_font);

    choiceS->Add(ClockB, 0, wxEXPAND| wxALL, 5);
    choiceS->Add(TimerB, 0, wxEXPAND| wxALL, 5);
    choiceS->Add(ChronoB, 0, wxEXPAND| wxALL, 5);

    mainS->Add(choiceS,0,wxEXPAND|wxALL,0);
    mainS->Add(sizeIns,0,wxEXPAND|wxALL,0);
    mainS->Add(StartB,0,wxEXPAND|wxALL,5);
    mainS->Add(Box,1,wxEXPAND|wxALL,5);
    mainS->Add(ResetB,0,wxEXPAND|wxALL,5);

    SetSizerAndFit(mainS);
    SetAutoLayout(true);

    type=new TimerType(this);
}

Timer::~Timer() {
    delete type;
}

void Timer::TimerOn(wxTimerEvent &) {
    type->computeTime();
    type->tempo();
    if(type->isOn() && type->getTimeLeft()=="00:00:00" /*&& StartB->GetLabel()!="Pause"*/) {
        StartB->SetLabel("Start");
        StartB->SetBackgroundColour(*wxGREEN);
    }
    std::string tempo=type->getTimeLeft();//con getTimeLeft ottengo il tempo impostato per far partire il cronometro
    Box->SetValue(tempo);
}
void Timer::Reset(wxCommandEvent &){
    if(ResetB->IsEnabled()){
        Box->SetValue("00:00:00");
        ResetB->Enable(false);
        StartB->SetLabel("Start");
        StartB->SetBackgroundColour(*wxGREEN);
        if(type->isOn()){
            type->setOn(false);
            type->stop();
        }
    }
}
void Timer::ONclick(wxCommandEvent &) {
    if(type->isOn()){
        StartB->SetLabel("Resume");
        StartB->SetBackgroundColour(*wxYELLOW);
        type->setOn(false);
        type->stop();
    }
    else{
        if(StartB->GetLabel()=="Resume"){ //ho clickato "resume"
            type->setOn(true);
            std::string time_left=Box->GetValue().ToStdString();
            std::string arr_time_left[3]={"","",""};
            for(int i=0,j=0;i<time_left.length();i++){
                if(time_left[i]==':'){
                    j++;
                }
                else{
                    arr_time_left[j].append(1,time_left[i]);
                }
            }


            type->setHleft(wxAtoi(arr_time_left[0]));
            type->setMleft(wxAtoi(arr_time_left[1]));
            type->setSleft(wxAtoi(arr_time_left[2]));

            HoursBox->SetValue("00");
            MinutesBox->SetValue("00");
            SecondsBox->SetValue("00");
            StartB->SetLabel("Pause");
            StartB->SetBackgroundColour(*wxRED);

            type->start();
        }
        else{
            type->setOn(true);
            type->setHleft(wxAtoi(HoursBox->GetValue()));
            type->setMleft(wxAtoi(MinutesBox->GetValue()));
            type->setSleft(wxAtoi(SecondsBox->GetValue()));

            HoursBox->SetValue("00");
            MinutesBox->SetValue("00");
            SecondsBox->SetValue("00");

            StartB->SetLabel("Pause");
            StartB->SetBackgroundColour(*wxRED);

            ResetB->Enable(true);

            type->start();
        }
    }
}

TimerType * Timer::getType() const {
    return type;
}
