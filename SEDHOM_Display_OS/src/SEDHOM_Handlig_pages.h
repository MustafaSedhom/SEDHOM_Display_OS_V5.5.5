#ifndef SEDHOM_PAGES_HANDLIG_H_
#define SEDHOM_PAGES_HANDLIG_H_

#include "SEDHOM_Data_Structure.h"

constexpr int MAX_PAGES = 50;   
#define SEDHOM_List_of_pages                void (*pages[])(void)
#define SEDHOM_Handling_pages_paramters     pages,sizeof(pages)/sizeof(pages[0])

class SEDHOM_Handlig_Pages
{
private:
    int current_page = -1;
    int pages_number = 0;
    void (**pages)(void) = nullptr;
    Stack<int> page;

public:
    SEDHOM_Handlig_Pages() : page(MAX_PAGES) {}

    void Handle_all_pages(void (*pages_array[])(void), int size)
    {
        pages = pages_array;
        pages_number = size;

        current_page = 1;
        page.push(current_page);
        show_current_page();
    }
    void goto_page(int number)
    {
        if (number >= 1 && number <= pages_number)
        {
            current_page = number;
            page.push(pages_number);
            show_current_page();
        }
    }
    void push_page()
    {
        if (current_page < pages_number)
        {
            current_page++;
            page.push(current_page);
            show_current_page();
        }
    }
    void pop_page()
    {
        if (!page.isEmpty())
        {
            page.pop();
            current_page = page.isEmpty() ? 1 : page.peek();
            show_current_page();
        }
    }
    void show_current_page()
    {
        if (pages && current_page >= 1 && current_page <= pages_number)
        {
            pages[current_page - 1]();
        }
    }
};



#endif
