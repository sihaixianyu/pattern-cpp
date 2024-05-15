#include <chrono>
#include <thread>
#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>

#include "singleton.h"

namespace singleton {
using fmt::format;
using std::string;
using std::thread;
using std::vector;

namespace tests {
class SingletonTest : public testing::Test {};

TEST_F(SingletonTest, test_case_0) {
    auto threads = vector<thread*>();

    for (auto i = 0; i < 10; i++) {
        auto get_singleton_value = [&]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            Singleton* singleton = Singleton::get_instance(format("Func: {}", i));
            std::cout << singleton->get_value() << "\n";
        };

        auto t = new thread(get_singleton_value);
        threads.push_back(t);
    }

    for (auto t : threads) {
        t->join();
    }
}
} // namespace tests
} // namespace singleton
