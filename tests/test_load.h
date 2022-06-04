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

TEST(load, positive) {
    char *file_name = INPUTDIR "test.txt";
    text txt = create_text();

    load (txt, file_name);
    FILE *f = fopen(file_name, "r");

    if (f == NULL){
        FAIL();
    }

    char buf[MAXLINE + 1];

    node *cur = txt->begin;

    while(fgets(buf, MAXLINE, f) != NULL){
        if (strlen(buf) && buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = 0;
        }
        if (cur == NULL || strcmp(buf, cur->contents) != 0){
            FAIL();
        }
        cur = cur->next;
    }
}

TEST(load, no_file){
    char *file_name = INPUTDIR "this_file_no_exist.txt";
    text txt = create_text();

    testing::internal::CaptureStdout();
    load (txt, file_name);
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "The file " INPUTDIR
                 "this_file_no_exist.txt cannot be opened\n" );
}

