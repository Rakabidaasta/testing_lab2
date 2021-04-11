#ifndef ALL_H
#define ALL_H

#include <QString>
#include <QDir>
#include <QFile>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../app/common.h"
#include "../app/text/text.h"
#include "../app/text/_text.h"

QString test_file_1 = "test_file_1.txt";
QString test_file_2 = "test_file_2.txt";

void removeFiles() {
    QDir dir(".");
    dir.remove(test_file_1);
    dir.remove(test_file_2);
}


#endif // TEST_SQ_EQ_H
