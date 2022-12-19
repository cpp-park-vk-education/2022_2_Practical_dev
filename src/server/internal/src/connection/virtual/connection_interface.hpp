#pragma once

struct IConnection {
    virtual void start() = 0;
    virtual void stop() = 0;
};
