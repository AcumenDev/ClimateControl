//
// Created by vst on 10/15/17.
//

#include "Menu.hpp"

Menu::Menu(int interval, PageGroup *pageGroup) : IntervalWorkerBase(interval) {
    this->currentPage = pageGroup;
}

void Menu::work(Values *values, unsigned long currentMillis) {
    //  currentPage->render(nullptr);
}

void Menu::up() {
    currentPage->up();
}

void Menu::down() {
    currentPage->down();
}

void Menu::enter() {
    PageBase *newCur = currentPage->enter();
    if (newCur != nullptr) {
        previousPage = currentPage;
        currentPage = newCur;
    }
}