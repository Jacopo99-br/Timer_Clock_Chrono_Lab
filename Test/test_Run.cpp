//
// Created by jacopo on 29/09/22.
//
#include <wx/wx.h>
#include <gtest/gtest.h>

class AppTest: public wxApp{
public:
    virtual bool OnInit();
    virtual int OnRun();
};

bool AppTest::OnInit() {
    return true;
}

int AppTest::OnRun() {
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

wxIMPLEMENT_APP(AppTest);