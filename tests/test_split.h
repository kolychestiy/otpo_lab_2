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

TEST(split, middle){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 3, 3);

    split(txt);

    testing::internal::CaptureStdout();
    show(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "first line (:\n"
            "12345\n"
            "a0|\n"
            "z9-;`\n"
            "-*6^  kj	j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp\n";

    EXPECT_STREQ(buf.c_str(), s.c_str());
}

TEST(split, begin){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 3, 1);

    split(txt);

    testing::internal::CaptureStdout();
    show(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "first line (:\n"
            "12345\n"
            "|\n"
            "a0z9-;`\n"
            "-*6^  kj	j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp\n";

    EXPECT_STREQ(buf.c_str(), s.c_str());
}

TEST(split, end){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 3, 100);

    split(txt);

    testing::internal::CaptureStdout();
    show(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "first line (:\n"
            "12345\n"
            "a0z9-;`|\n"
            "\n"
            "-*6^  kj	j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp\n";

    EXPECT_STREQ(buf.c_str(), s.c_str());
}

TEST(split, no_cursor_line){
    text txt = create_text();

    testing::internal::CaptureStdout();
    split(txt);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "cursor no set\n");
}
