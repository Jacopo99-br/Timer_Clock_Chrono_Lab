//
// Created by jacopo on 01/08/22.
//
#include "../headers_/MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
//in Timer
                EVT_BUTTON(5,MainFrame::buildClock)
                EVT_BUTTON(7,MainFrame::buildChronometer)
//in Chronometer
                EVT_BUTTON(10,MainFrame::buildClock)
                EVT_BUTTON(11,MainFrame::buildTimer)
//in Clock
                EVT_BUTTON(2,MainFrame::buildTimer)
                EVT_BUTTON(3,MainFrame::buildChronometer)
wxEND_EVENT_TABLE()

MainFrame::MainFrame():wxFrame(NULL,wxID_ANY,"Clock",wxDefaultPosition,wxSize(720,400)){
    currentPanel=new Clock(this);
}
MainFrame::~MainFrame() noexcept {}

void MainFrame::buildTimer(wxCommandEvent&) {
    this->SetTitle("Timer");
    currentPanel->Destroy();
    currentPanel = new Timer(this);  // se voglio mettere il timer tolgo l'orologio (default)
    // e lo sostituisco con un pannello per il timer
}

void MainFrame::buildClock(wxCommandEvent&) {
    this->SetTitle("Clock");
    currentPanel->Destroy();
    currentPanel = new Clock(this);  // se voglio mettere il timer tolgo l'orologio (default)
    // e lo sostituisco con un pannello per il timer
}

void MainFrame::buildChronometer(wxCommandEvent&) {
    this->SetTitle("Chronometer");
    currentPanel->Destroy();
    currentPanel = new Chrono(this);  // se voglio mettere il timer tolgo l'orologio (default)
    // e lo sostituisco con un pannello per il timer
}
