#include <string>

namespace singleton {

class Singleton {
public:
    static Singleton* get_instance(std::string value) {
        static auto instance = new Singleton(value);
        return instance;
    }

    std::string get_value() const {
        return value_;
    }

private:
    Singleton(const std::string value) : value_(value) {};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    ~Singleton() {};

private:
    const std::string value_;
};

} // namespace singleton
