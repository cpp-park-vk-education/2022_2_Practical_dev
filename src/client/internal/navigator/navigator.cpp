#include "navigator.hpp"

Navigator::Navigator(QStackedWidget* _container, ScreensFactory* _factory) : container(_container), factory(_factory) {
    BaseFragment* start = createStart();
    deque.push_back(start);
    container->addWidget(deque.back());
    container->setCurrentIndex(0);
}

BaseFragment* Navigator::createStart() {
    return createAndConnect(factory->getStart());
}

void Navigator::connectFragment(BaseFragment* fragment) {
    connect(fragment, &BaseFragment::back, this, &Navigator::back);
    connect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    connect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    connect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
}

void Navigator::disconnectFragment(BaseFragment* fragment) {
    disconnect(fragment, &BaseFragment::back, this, &Navigator::back);
    disconnect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    disconnect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    disconnect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
}

BaseFragment* Navigator::createAndConnect(QString tag) {
    BaseFragment* fragment = factory->create(tag);
    connectFragment(fragment);
    return fragment;
}

void Navigator::navigateTo(QString tag) {
    BaseFragment* fragment = factory->create(tag);
    disconnectFragment(deque.back());
    connectFragment(fragment);
    deque.push_back(fragment);
    container->addWidget(fragment);
    container->setCurrentWidget(fragment);
}
