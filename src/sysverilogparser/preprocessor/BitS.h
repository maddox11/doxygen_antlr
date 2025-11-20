#ifndef BITS_H
#define BITS_H

#include <vector>
#include <cassert>
#include <algorithm>

namespace prepc
{
    class BitS
    {

   
    public:
        BitS(std::size_t size) { bs.resize(size, false); }
        BitS() { bs.resize(100, false); }

        std::size_t getSize() {return bs.size();}
        
        void set(std::size_t pos, bool v)
        {
            if (pos >= bs.size())
                bs.resize(bs.size() + (pos - bs.size() + 1));
            bs[pos] = v;
        }

        void setSize(std::size_t len)
        {
            bs.resize(len, false);
        }

        bool test(std::size_t pos)
        {
            assert(pos <= bs.size());
            return bs.at(pos);
        }

        void out()
        {
            std::for_each(bs.begin(), bs.end(), [](const size_t n)
                          { std::cout << n; });
            std::cout << '\n';
        }

    private:
        std::vector<bool> bs;

    };
}

#endif
