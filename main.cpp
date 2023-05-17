#include <iostream>

// head
// node_number

// 7 -> 5 -> 1 -> 9 -> 2  2    size_list - value + 1
// 7 -> 9 -> 1 -> 5 -> 2

struct node
{
    node() : value_(0), next_(nullptr)
    {
    }
    
    node(int32_t value) : value_(value), next_(nullptr)
    {
    }

    int32_t value_;
    node* next_;
};

node* swap_list_values(node* head, int32_t node_number)
{
    if (!head)
    {
        return head;
    }

    auto start = head;

    int32_t size_list = 0;

    while (start)
    {   
        ++size_list;
        start = start->next_;
    }

    start = head;

    int32_t cur_node_number = 1;
    int32_t node_from_end_number = size_list - node_number + 1;

    node* temp_1 = nullptr;
    node* temp_2 = nullptr;

    while (start)
    {
        if (cur_node_number == node_number)
        {   
            temp_1 = start;
        }

        if (cur_node_number == node_from_end_number)
        {
            temp_2 = start;
        }

        ++cur_node_number;
        start = start->next_;
    }

    std::swap(temp_1->value_, temp_2->value_);

    return head;
}

void print_list(const node* head)
{
    while (head)
    {
        std::cout << head->value_ << " ";

        head = head->next_;
    }
    
    std::cout << "!\n";
}

int main(int argc, char** argv)
{
    node list[5];

    list[0].value_ = 7;
    list[0].next_ = &list[1];

    list[1].value_ = 5;
    list[1].next_ = &list[2];

    list[2].value_ = 1;
    list[2].next_ = &list[3];

    list[3].value_ = 9;
    list[3].next_ = &list[4];

    list[4].value_ = 2;

    print_list(list);

    print_list(swap_list_values(list, 1));

    return 0;
}
