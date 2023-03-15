//
// Created by jacopo on 01/08/22.
//
#include "../headers_/Application.h"
Application::Application() {}
Application::~Application() {}

bool Application::OnInit(){
    frame=new MainFrame();
    frame->Show();
    return true;
}