#include "namespaces.hpp"

template<typename Handler>
struct IRouter {
    virtual Handler route(http::verb method, std::string url) = 0;
};
