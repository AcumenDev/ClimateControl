//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_PAGE_VALUE_HPP
#define TEST_CLIMATE_PAGE_VALUE_HPP


#include "PageBase.hpp"
#include "Changer.hpp"

class PageValue : public PageBase {
private:
    Changer * changer;
public:
    PageValue(const char *name, Changer * changer) : PageBase(name) {
        this->changer = changer;
    }

    const char *getRender() const override {
        return changer->getChars();
    }

    void up() override {
        changer->up();
    }

    void down() override {
        changer->down();
    }

};


#endif //TEST_CLIMATE_PAGE_HPP
