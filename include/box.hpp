#include <cstdint>
#include <string>
#include <vector>

class Box {
  public:
    Box(size_t x, size_t y, size_t w, size_t h, std::string title,
        std::vector<std::string> content);
    void update_content(std::vector<std::string> new_content);
    void draw() const;

  private:
    static size_t displayed_length(const std::string &str);

    size_t x;
    size_t y;
    size_t w;
    size_t h;
    std::string title;
    std::vector<std::string> content;
};

class OpBox : public Box {
  public:
    using Box::Box;
    void update_content(uint32_t operation);
};
