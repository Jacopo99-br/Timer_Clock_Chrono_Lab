//
// Created by jacopo on 04/04/23.
//
#include "../headers_/MainFrame.h"
#include "../headers_/Timer.h"
#include <gtest/gtest.h>
#include <unistd.h>

class TimerTest: public ::testing::Test{
protected:
    virtual void SetUp();
    virtual void TeraDown();

    MainFrame* mainframe;
    Timer* timer;
};

void TimerTest::SetUp(){
    mainframe= new MainFrame();
    timer= new Timer(mainframe);
}

void TimerTest::TeraDown() {
    delete mainframe;
}

TEST_F(TimerTest,CheckStart){  //controlla il corretto avvio del Timer
    timer->getType()->setSleft(10); // 10 secondi
    timer->getType()->start();
    bool state=timer->getType()->isOn();
    ASSERT_TRUE(state);
}

TEST_F(TimerTest,CheckReset){
    timer->getType()->setTimeLeft("00:00:05"); // 5 secondi
    timer->getType()->tempo();
    timer->getType()->start();
    timer->getType()->reset();
    timer->getType()->tempo();
    std::string time=timer->getType()->getTimeLeft();
    ASSERT_EQ("00:00:00",time);
}