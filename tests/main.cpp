#include "test_load.h"
#include "test_move.h"
#include "test_plb.h"
#include "test_save.h"
#include "test_show.h"
#include "test_showcl.h"
#include "test_split.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
