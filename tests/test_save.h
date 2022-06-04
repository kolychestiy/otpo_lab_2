#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <fstream>

using namespace std;

#define MAXLINE 255

extern "C"{
#include "text.h"
#include "_text.h"
#include "common.h"
}

TEST(save, positive){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    save(txt, INPUTDIR "save.txt");

    FILE *f1 = fopen(INPUTDIR "test.txt", "r");
    FILE *f2 = fopen(INPUTDIR "save.txt", "r");

    char c = '0';
    char d = '0';

    while (c != EOF && d != EOF){
        c = getc(f1);
        d = getc(f2);
        if (c == EOF && d == '\n'){
            d = getc(f2);
        }
        EXPECT_EQ(c, d);
    }
}

TEST(save, error){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    testing::internal::CaptureStdout();
    save(txt, INPUTDIR);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "The file " INPUTDIR " cannot be opened\n");
}

