#ifndef R1E_H
#define R1E_H

#include "all_tests.h"

TEST(r1e, first_empty)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            append_line(txt, "");
        } else {
            append_line(txt, "r1e test " + std::to_string(i));
            output_text += "r1e test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    r1e(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(r1e, center_empty)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            append_line(txt, "");
        } else {
            append_line(txt, "r1e test " + std::to_string(i));
            output_text += "r1e test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    r1e(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(r1e, last_empty)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            append_line(txt, "");
        } else {
            append_line(txt, "r1e test " + std::to_string(i));
            output_text += "r1e test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    r1e(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(r1e, no_empty)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "r1e test " + std::to_string(i));
        output_text += "r1e test " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    r1e(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(r1e, one_str)
{
    std::string output_text = "\n";

    text txt = create_text();
    append_line(txt, "");

    testing::internal::CaptureStdout();

    r1e(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(r1e, nothing)
{
    std::string output_text = "";

    text txt = create_text();

    testing::internal::CaptureStdout();

    r1e(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}


#endif // R1E_H
