/**
 * @file box.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief Box and OpBox classes for text-based UI.
 * @version 0.1
 * @date 2024-04-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../include/box.hpp"
#include "../include/Tokens.hpp"
#include "../include/int24.hpp"
#include <format>
#include <iostream>
#include <regex>

Box::Box(size_t _x, size_t _y, size_t _w, size_t _h, std::string _title,
         std::vector<std::string> _content)
    : x(_x), y(_y), title(_title), content(_content) {
    size_t longest_contet_line =
        _content.size() > 0
            ? displayed_length(
                  std::max_element(_content.begin(), _content.end(),
                                   [](std::string a, std::string b) {
                                       return displayed_length(a.data()) <
                                              displayed_length(b.data());
                                   })
                      ->data())
            : 0;
    this->w =
        std::max({_w, displayed_length(_title.data()), longest_contet_line});
    this->h = std::max(_h, _content.size());
}

void Box::update_content(std::vector<std::string> new_content) {
    content = new_content;
    size_t longest_contet_line =
        content.size() > 0
            ? displayed_length(
                  std::max_element(content.begin(), content.end(),
                                   [](std::string a, std::string b) {
                                       return displayed_length(a.data()) <
                                              displayed_length(b.data());
                                   })
                      ->data())
            : 0;
    this->w =
        std::max({w, displayed_length(title.data()), longest_contet_line});
    this->h = std::max(h, content.size());
}

void Box::draw() const {
    std::cout << SAVE_CURSOR;
    std::cout << MOVE_CURSOR << x << FORWARD;
    std::cout << MOVE_CURSOR << y + 1 << UP;
    std::cout << std::string(w + 2, ' ');
    std::cout << MOVE_CURSOR << w + 2 << BACKWARD;
    std::cout << MOVE_CURSOR << 1 << DOWN;
    std::cout << "╭" << title;
    for (size_t i = displayed_length(title.data()); i < w; ++i)
        std::cout << "─";
    std::cout << "╮";
    std::cout << MOVE_CURSOR << w + 2 << BACKWARD;
    std::cout << MOVE_CURSOR << 1 << DOWN;
    for (size_t i = 0; i < content.size(); ++i) {
        std::cout << "│" << content[i]
                  << std::string(w - displayed_length(content[i].data()), ' ')
                  << "│";
        std::cout << MOVE_CURSOR << w + 2 << BACKWARD;
        std::cout << MOVE_CURSOR << 1 << DOWN;
    }
    for (size_t i = content.size(); i < h; ++i) {
        std::cout << "│" << std::string(w, ' ') << "│";
        std::cout << MOVE_CURSOR << w + 2 << BACKWARD;
        std::cout << MOVE_CURSOR << 1 << DOWN;
    }
    std::cout << "╰";
    for (size_t i = 0; i < w; ++i)
        std::cout << "─";
    std::cout << "╯";
    std::cout << RESTORE_CURSOR;
}

size_t Box::displayed_length(const std::string &str) {
    // Regex pattern to match ANSI escape codes for color
    std::regex color_pattern("\033\\[[0-9;]+m");
    // Remove ANSI escape codes for color from the string
    std::string clean_str = std::regex_replace(str, color_pattern, "");
    // Count the number of graphemes
    size_t grapheme_count = 0;
    for (size_t i = 0; i < clean_str.length(); ++grapheme_count) {
        while ((i < clean_str.length()) && ((clean_str[i] & 0xC0) == 0x80)) {
            ++i;
        }
        ++i;
    }
    return grapheme_count;
}

std::vector<std::string> Box::get_content() const { return this->content; }

void OpBox::update_content(uint32_t operation) {
    std::string op_str;
    switch (operation & 0xFF000000) {
        case static_cast<uint32_t>(OperationValue::LOAD):
            op_str = "LOAD";
            break;
        case static_cast<uint32_t>(OperationValue::ADD):
            op_str = "ADD";
            break;
        case static_cast<uint32_t>(OperationValue::PRINT):
            op_str = "PRINT";
            break;
        default:
            InvalidOperation e;
            throw e;
    }
    op_str = std::format("{:<5}", op_str);
    op_str += std::format("{:>8}", from_int24(operation & 0x00FFFFFF));
    Box::update_content(
        {UNDERLINE "0x" + std::format("{:02X}", operation >> 24) +
             RESET " - " UNDERLINE +
             std::format("{:06X}", operation & 0x00FFFFFF) + RESET,
         "  ╱       ╲ ", op_str});
}

const char *InvalidOperation::what() const noexcept(true) { return msg; }
