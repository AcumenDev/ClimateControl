//
// Created by vst on 10/15/17.
//

#include "PageGroup.hpp"

PageGroup::PageGroup(PageBase **pages, byte size) {
    this->pages = pages;
    this->size = size;
}

PageGroup::PageGroup(const char *name, PageBase **pages, byte size) : PageBase(name) {
    this->pages = pages;
    this->size = size;
}

void PageGroup::up() {
    if (current >= size - 1) {
        current = 0;
    } else {
        current++;
    }
}

void PageGroup::down() {
    if (current <= 0) {
        current = size - 1;
    } else {
        current--;
    }
}

PageBase *PageGroup::enter() {
    return pages[current];
}

