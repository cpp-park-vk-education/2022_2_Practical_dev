#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "utils/namespaces.hpp"

class ClientMock {
    std::string sd_;
    std::string ed_;
    std::string rd_;

 public:
    ClientMock(tcp::endpoint &ep, std::string send_data, std::string expect_data);
    MOCK_METHOD(void, send, (tcp::socket &sock));
    MOCK_METHOD(void, recieve, (tcp::socket &sock));
    bool check();
};
