#ifndef SAVE_H
#define SAVE_H

#include "all_tests.h"

TEST(save, without_empty_strs)
{
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "string " + std::to_string(i));
    }

    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();
        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str());
        line_text++;
    }

    removeFiles();
}

TEST(save, with_empty_strs)
{
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "string " + std::to_string(i));
        append_line(txt, "");
    }

    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, empty_strs)
{
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "");
    }

    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, one_str)
{
    text txt = create_text();
    append_line(txt, "");

    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, nothing)
{
    text txt = create_text();
    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

#endif // TEST_SQ_EQ_H
