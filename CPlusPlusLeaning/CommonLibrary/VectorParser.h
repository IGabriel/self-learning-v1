#pragma once
#include <vector>

template<typename T>
class VectorParser
{
public:
    explicit VectorParser(const std::vector<T>& elements) : elements_(elements) {}
    std::vector<T> get_element() { return elements_; }
    void set_element(const std::vector<T>& new_value) { elements_ = new_value; }

private:
    std::vector<T> elements_;
};
