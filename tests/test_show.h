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

TEST(show, end_cursor){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 100, 100);

    testing::internal::CaptureStdout();
    show(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "first line (:\n"
            "12345\n"
            "a0z9-;`\n"
            "-*6^  kj	j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp|\n";

    EXPECT_EQ(buf, s);
}

TEST(show, begin_cursor){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 1, 1);

    testing::internal::CaptureStdout();
    show(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "|first line (:\n"
            "12345\n"
            "a0z9-;`\n"
            "-*6^  kj	j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp\n";

    EXPECT_EQ(buf, s);
}

TEST(show, middle_cursor){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 4, 10);

    testing::internal::CaptureStdout();
    show(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "first line (:\n"
            "12345\n"
            "a0z9-;`\n"
            "-*6^  kj	|j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp\n";

    EXPECT_EQ(buf, s);
}

TEST(show, no_cursor){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    txt->cursor->line = NULL;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();
    show(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "first line (:\n"
            "12345\n"
            "a0z9-;`\n"
            "-*6^  kj	j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp\n";

    EXPECT_EQ(buf, s);
}
