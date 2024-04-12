/**
 * @file box.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief Header file for Box and OpBox classes for text-based UI.
 * @version 0.1
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cstdint>
#include <string>
#include <vector>

#define UNDERLINE "\033[4m"
#define RESET "\033[0m"
#define SAVE_CURSOR "\033[s"
#define RESTORE_CURSOR "\033[u"
#define MOVE_CURSOR "\033["
#define UP "A"
#define DOWN "B"
#define FORWARD "C"
#define BACKWARD "D"


/**
 * @brief Class representing a text box for the UI.
 */
class Box {
  public:

     /**
     * @brief Constructor for a Box.
     * @param x X-coordinate of the upper left corner.
     * @param y Y-coordinate of the upper left corner.
     * @param w Width of the box.
     * @param h Height of the box.
     * @param title Title displayed on the top of the box.
     * @param content Vector of strings representing the content.
     */
    Box(size_t x, size_t y, size_t w, size_t h, std::string title,
        std::vector<std::string> content);
    void update_content(std::vector<std::string> new_content);
    void draw() const;
	 std::vector<std::string> get_content()const;

  private:

    /**
     * @brief Calculates the displayed length of a string considering wrapping within the box.
     * @param str The string to calculate the length for.
     * @return The displayed length of the string.
     */
    static size_t displayed_length(const std::string &str);

    size_t x;
    size_t y;
    size_t w;
    size_t h;
    std::string title;
    std::vector<std::string> content;
};

/**
 * @brief Inherits from Box and provides functionality for an operation box.
 */
class OpBox : public Box {
  public:
    using Box::Box;
    void update_content(uint32_t operation);
};

class InvalidOperation : public std::exception {
    public:
        InvalidOperation() = default;
        ~InvalidOperation() = default;
        InvalidOperation(InvalidOperation &&) = default;
        InvalidOperation(const InvalidOperation &) = default;
        const char *what() const noexcept(true) override;

    private:
        const char *msg = "Invalid Operation: non existing operation";
    };
