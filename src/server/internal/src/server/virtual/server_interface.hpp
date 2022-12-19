#pragma once

struct IServer {
    virtual void run() = 0;
    virtual void stop() = 0;
};
