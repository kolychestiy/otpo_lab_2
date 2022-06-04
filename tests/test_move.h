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

TEST(move, begin){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    move(txt, 1, 1);

    EXPECT_EQ(txt->begin, txt->cursor->line);
    EXPECT_EQ(0, txt->cursor->position);
}

TEST(move, end_all){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    move(txt, 1000, 1000);

    EXPECT_EQ(txt->end, txt->cursor->line);
    EXPECT_EQ(strlen(txt->end->contents), txt->cursor->position);
}

TEST(move, end_left){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    move(txt, 2, 1000);

    EXPECT_EQ(txt->begin->next, txt->cursor->line);
    EXPECT_EQ(strlen(txt->begin->next->contents), txt->cursor->position);
}

TEST(move, end_down){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    move(txt, 1000, 2);

    EXPECT_EQ(txt->end, txt->cursor->line);
    EXPECT_EQ(1, txt->cursor->position);
}

TEST(move, middle){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    move(txt, 3, 3);

    EXPECT_EQ(txt->begin->next->next, txt->cursor->line);
    EXPECT_EQ(2, txt->cursor->position);
}

TEST(move, no_positive_line){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    move(txt, -3, 2);

    EXPECT_EQ(txt->begin, txt->cursor->line);
    EXPECT_EQ(1, txt->cursor->position);
}

TEST(move, no_positive_row){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");

    move(txt, 2, -3);

    EXPECT_EQ(txt->begin->next, txt->cursor->line);
    EXPECT_EQ(0, txt->cursor->position);
}

TEST(move, empty_txt){
    text txt = create_text();

    testing::internal::CaptureStdout();
    move(txt, 1, 1);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "text is empty. you can't move\n" );
}


