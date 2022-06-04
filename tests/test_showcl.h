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

TEST(showclassified, positive){
    text txt = create_text();
    load (txt, INPUTDIR "test.txt");
    move(txt, 2, 2);

    testing::internal::CaptureStdout();
    showclassified(txt);
    string buf = testing::internal::GetCapturedStdout();

    string s =
            "first line (:\n"
            "1|2345\n"
            "a0z9-;`\n"
            "-*6^  kj	j	5\n"
            "---++\n"
            "/\\\\//\\\n"
            "\n"
            "ggwp\n";

    if (s.size() != buf.size()){
        FAIL();
    }

    for (int i = 0; i < s.size(); i++){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            if (buf[i] != '*'){
                cout << i << ' ' << s[i] << ' ' << buf[i] << '\n';
                FAIL();
            }
        }else{
            EXPECT_EQ(s[i], buf[i]);
        }
    }
}
