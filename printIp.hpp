#pragma once

#include <array>
#include <vector>
#include "my_ctype.hpp"
#include <iostream>
#include <limits>

namespace printIP
{
    template <std::size_t N>
    class IP_Pool
    {

    private:
        std::vector<std::array<uint8_t, N>> vect_ip_octets;

    protected:
    public:
        void read_from_stream(std::istream &stream)
        {
            auto locale_prev = stream.imbue(std::locale(stream.getloc(), new printf_white_space()));

            while (stream)
            {
                for (auto &array : vect_ip_octets)
                {
                    for (uint8_t elem : array)
                    {
                        stream >> elem;
                    }
                    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            stream.imbue(locale_prev);
        }

        void sort_reverse()
        {
            
        }

        void print()
        {
        }

        void find()
        {
        }

        void find_first()
        {
        }

        //void sort_reverse();

        /*  template <uint8_t... Args>
        IP_Pool<IP_V> filter(Args &&... octets);

        IP_Pool<IP_V> filter_any(uint8_t octet);
    
    */
    };

} // namespace printIP