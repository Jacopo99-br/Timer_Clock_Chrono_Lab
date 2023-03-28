//
// Created by jacopo on 27/03/23.
//

#include "../headers_/MainFrame.h"
#include "../headers_/Chrono.h"
#include <gtest/gtest.h>
class ChronoTest:public::testing::Test{
protected:
    virtual void SetUp();
    virtual void TearDown();

    MainFrame* mainFrame;
    Chrono* chrono;
};

void ChronoTest::SetUp() {
    mainFrame=new MainFrame();
    chrono=new Chrono(mainFrame);
}

void ChronoTest::TearDown() {
    delete mainFrame;
}

TEST_F(ChronoTest, CheckStart){  //controlla il corretto avvio del Cronometro
chrono->getType()->start();
bool flag=chrono->getType()->isOff();
ASSERT_TRUE(!flag);
}

TEST_F(ChronoTest, CheckStop){   //controlla il corretto stop del Cronometro
chrono->getType()->start();
chrono->getType()->stop();
ASSERT_TRUE(chrono->getType()->isOff());
}

TEST_F(ChronoTest, CheckAzz){    //controlla il corretto azzeramento dei campi
    for(int i=0;i<200;i++)
    chrono->getType()->computeTime();
    chrono->getType()->turn_zero();
    chrono->getType()->time();

    std::string tempoAt=chrono->getType()->getcurrenTime();
    ASSERT_TRUE(tempoAt.compare("00:00:00,00")==0);
}

