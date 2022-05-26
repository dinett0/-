#include <list>
#include <algorithm>
#include <iostream>

struct Item
{
    unsigned weight = 0, cost = 0;

    static Item guardian()
    {
        return { std::numeric_limits<unsigned>::max(), std::numeric_limits<unsigned>::max() };
    }

    bool is_guardian() const
    {
        return weight == std::numeric_limits<unsigned>::max();
    }

    Item& operator +=(const Item& rhs)
    {
        weight += rhs.weight;
        cost += rhs.cost;
        return *this;
    }

    Item& operator -=(const Item& rhs)
    {
        weight -= rhs.weight;
        cost -= rhs.cost;
        return *this;
    }

    bool is_better_than(const Item& rhs) const
    {
        return cost > rhs.cost;
    }

    friend std::ostream& operator <<(std::ostream& strm, const Item& item)
    {
        strm << "{ w = " << item.weight << ", c = " << item.cost << " }";
        return strm;
    }
};

class Items
{
public:
    using Container = std::list<Item>;

    Items(unsigned max_weight) : max_weight(max_weight)
    {}

    Item find_best(Container source)
    {
        source.push_back(Item::guardian());
        items.clear();
        Items current(max_weight);
        find_best(current, source.begin());
        return total;
    }

    friend std::ostream& operator <<(std::ostream& strm, const Items& items)
    {
        strm << items.total << ": ";
        for (const Item& item : items.items)
            strm << item << " ";
        return strm;
    }

private:
    Container items;
    Item total;
    unsigned max_weight;

    void pop_back()
    {
        Item item = std::move(items.back());
        items.pop_back();
        total -= item;
    }

    bool push_back(Item item)
    {
        if (total.weight + item.weight > max_weight)
            return false;

        total += item;
        items.push_back(std::move(item));

        return true;
    }

    void find_best(Items& current, Container::const_iterator it_remaining)
    {
        if (it_remaining->is_guardian())
        {
            std::cout << "Leaf: " << current << std::endl;
            if (current.total.is_better_than(total))
                *this = current;
            return;
        }

        find_best(current, std::next(it_remaining));

        if (current.push_back(*it_remaining))
        {
            find_best(current, std::next(it_remaining));
            current.pop_back();
        }
    }
};

int main()
{
    Items backpack(1500);
    backpack.find_best({ { 200, 40 }, { 314, 50 }, { 198, 100 }, { 500, 60 }, { 300, 30 }, { 400, 45 } });
    std::cout << std::endl << "Best: " << backpack << std::endl;
}