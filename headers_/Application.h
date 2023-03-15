//
// Created by jacopo on 01/08/22.
//

#ifndef LAB_PROGRAMMAZIONE_APPLICATION_H
#define LAB_PROGRAMMAZIONE_APPLICATION_H

#include <wx/wx.h>
#include "MainFrame.h"

class Application : public wxApp{
public:
    Application();
    ~Application();
    bool OnInit();

private:
    MainFrame* frame=nullptr;
};

#endif //LAB_PROGRAMMAZIONE_APPLICATION_H
