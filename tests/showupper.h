#ifndef SHOWUPPER_H
#define SHOWUPPER_H

#include "all_tests.h"

TEST(showupper, lower_ints)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "showupper " + std::to_string(i));
        output_text += "SHOWUPPER " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showupper, upper_ints)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "SHOWUPPER " + std::to_string(i));
        output_text += "SHOWUPPER " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showupper, ints)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, " " + std::to_string(i));
        output_text += " " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showupper, lower_upper)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "lOwer aNd UpPER " + std::to_string(i));
        output_text += "LOWER AND UPPER " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showupper, nothing)
{
    std::string output_text = "";
    text txt = create_text();

    testing::internal::CaptureStdout();

    showupper(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}



#endif // SHOWUPPER_H
