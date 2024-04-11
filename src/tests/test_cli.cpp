/**
 * @file test_cli.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/cli.hpp"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

void create_temp_file(const std::string &filename, const std::string &content) {
    std::ofstream tmp_file(filename);
    tmp_file << content;
    tmp_file.close();
}

void remove_temp_file(const std::string &filename) {
    std::remove(filename.c_str());
}

Test(args_in, test) {
    std::string expected = "hola";
    create_temp_file("ifile.s", expected);
    const char *argv[] = {"", "ifile.s"};
    struct cli::assembler::Files files = cli::assembler::parse_args(2, argv);
    std::string result;
    files.ifile >> result;
    remove_temp_file("ifile.s");
    remove_temp_file("out_ifile.s");
    cr_assert_eq(result, expected);
}

Test(args_in_out, test) {
    std::string expected = "hola";
    create_temp_file("ifile.s", expected);
    const char *argv[] = {"", "ifile.s", "-o", "ofile.s"};
    struct cli::assembler::Files files = cli::assembler::parse_args(4, argv);
    std::string result;
    files.ifile >> result;
    remove_temp_file("ifile.s");
    remove_temp_file("ofile.s");
    cr_assert_eq(result, expected);
}

Test(args_out_in, test) {
    std::string expected = "hola";
    create_temp_file("ifile.s", expected);
    const char *argv[] = {"", "-o", "ofile.s", "ifile.s"};
    struct cli::assembler::Files files = cli::assembler::parse_args(4, argv);
    std::string result;
    files.ifile >> result;
    remove_temp_file("ifile.s");
    remove_temp_file("ofile.s");
    cr_assert_eq(result, expected);
}

Test(no_args, test) {
    bool exception = false;
    const char *argv[] = {""};
    try {
        struct cli::assembler::Files files = cli::assembler::parse_args(1, argv);
    } catch (cli::NoInFile) {
        exception = true;
    }
    cr_assert(exception);
}

Test(too_many_args, test) {
    bool exception = false;
    const char *argv[] = {"", "-o", "ofile.s", "ifile.s", "extra_file"};
    try {
        struct cli::assembler::Files files = cli::assembler::parse_args(5, argv);
    } catch (cli::TooManyArgs) {
        exception = true;
    }
    cr_assert(exception);
}

Test(bad_o_use, test) {
    bool exception = false;
    const char *argv[] = {"", "-o"};
    try {
        struct cli::assembler::Files files = cli::assembler::parse_args(2, argv);
    } catch (cli::BadOUse) {
        exception = true;
    }
    cr_assert(exception);
}

Test(fail_to_open_ifile, test) {
    bool exception = false;
    const char *argv[] = {"", "ifile.s"};
    try {
        struct cli::assembler::Files files = cli::assembler::parse_args(2, argv);
    } catch (cli::FailToOpenInFile) {
        exception = true;
    }
    cr_assert(exception);
}

Test(doesnt_need_help, test) {
    const char *argv[] = {"", "ifile.s"};
    bool result = cli::needs_help(2, argv);
    bool expected = false;
    cr_assert_eq(result, expected);
}

Test(needs_help, test) {
    const char *argv[] = {"", "-h"};
    bool result = cli::needs_help(2, argv);
    bool expected = true;
    cr_assert_eq(result, expected);
}
