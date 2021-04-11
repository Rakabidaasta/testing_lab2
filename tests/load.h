#ifndef LOAD_H
#define LOAD_H

#include "all_tests.h"

TEST(load, initial)
{
    text txt = create_text();
    append_line(txt, "test_load");

    save(txt, test_file_1.toStdString());

    load(txt, test_file_1.toStdString());

    remove_all(txt);
}

#endif // LOAD_H
