struct IRouterPool {
    virtual void get_router() = 0;
    // static get instance
private:
    IRouterPool() = delete;
};
