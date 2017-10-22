//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_PAGEGROUP_HPP
#define TEST_CLIMATE_PAGEGROUP_HPP


#include "PageBase.hpp"

class PageGroup : public PageBase {
    PageBase **pages;
    byte size;
    int current = 0;
public:
    PageGroup(PageBase **pages, byte size);
    PageGroup(const char * name, PageBase **pages, byte size);

    // void add(PageBase *pBase);
    const PageBase *getCurrentPage() {
        return pages[current];
    }
    const char *getRender() const override {
        return pages[current]->getName();
    }


    void up() override;

    void down() override;

    PageBase *enter() override;

private:
    //  void render(const Display *dispay) override;

};


#endif //TEST_CLIMATE_PAGEGROUP_HPP
