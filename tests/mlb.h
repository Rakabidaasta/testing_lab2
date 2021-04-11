#ifndef MLB_H
#define MLB_H

#include "all_tests.h"

TEST(mlb, on_first_begin)
{
    std::string output_text = "|";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "mlb test " + std::to_string(i));
        output_text += "mlb test " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mlb, on_first)
{
    std::string output_text = "|";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "mlb test " + std::to_string(i));
        output_text += "mlb test " + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 10);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mlb, on_center_begin)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "mlb test " + std::to_string(i));
        if (i == 4) {
            output_text += "|mlb test " + std::to_string(i) + "\n";
        } else {
            output_text += "mlb test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 4, 0);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}


TEST(mlb, on_center)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "mlb test " + std::to_string(i));
        if (i == 4) {
            output_text += "|mlb test " + std::to_string(i) + "\n";
        } else {
            output_text += "mlb test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 4, 8);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mlb, on_last_begin)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "mlb test " + std::to_string(i));
        if (i == 9) {
            output_text += "|mlb test " + std::to_string(i) + "\n";
        } else {
            output_text += "mlb test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 9, 0);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mlb, on_last)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "mlb test " + std::to_string(i));
        if (i == 9) {
            output_text += "|mlb test " + std::to_string(i) + "\n";
        } else {
            output_text += "mlb test " + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 9, 8);
    mlb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif // MLB_H
