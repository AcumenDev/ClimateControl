//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_PAGE_BASE_HPP
#define TEST_CLIMATE_PAGE_BASE_HPP


#include "Display.hpp"

class PageBase {
private:
    const char *name;
public:
    PageBase() {}

    PageBase(const char *name) : name(name) {}

    //  virtual void render(const Display *dispay)= 0;

    //virtual void void changeEvent(T event) = 0;
    virtual const char *getName() const {
        return name;
    }


    virtual const char *getRender() const {
        return name;
    }

    virtual void up() {}

    virtual void down() {}

    virtual PageBase *enter() { return nullptr; }
};

#endif //TEST_CLIMATE_PAGE_HPP
