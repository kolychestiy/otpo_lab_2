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

TEST(plb, empty){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 1, 1);

    testing::internal::CaptureStdout();
    plb(txt);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "|\n");
}

TEST(plb, all){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 1, 100);

    testing::internal::CaptureStdout();
    plb(txt);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "first line (:|\n");
}

TEST(plb, middle){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 1, 8);

    testing::internal::CaptureStdout();
    plb(txt);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "first l|\n");
}

TEST(plb, no_cursor){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    txt->cursor->line = NULL;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();
    plb(txt);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "");
}

TEST(plb, empty_txt){
    text txt = create_text();

    testing::internal::CaptureStdout();
    plb(txt);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "");
}
