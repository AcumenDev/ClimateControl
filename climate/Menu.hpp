//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_MENU_HPP
#define TEST_CLIMATE_MENU_HPP

#include "IntervalWorkerBase.hpp"
#include "PageBase.hpp"
#include "PageGroup.hpp"


class Menu : public IntervalWorkerBase {
    PageBase *currentPage = nullptr;
    PageBase *previousPage = nullptr;
public:
    Menu(int interval, PageGroup *pageGroup);

    void work(Values *values, unsigned long currentMillis) override;

    const PageBase *getCurrentPage() const {
        return currentPage;
    }

    void up();

    void down();

    void enter();
};

#endif //TEST_CLIMATE_MENU_HPP
