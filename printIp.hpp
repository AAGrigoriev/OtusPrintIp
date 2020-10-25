#pragma once

#include <array>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <initializer_list>
#include "my_ctype.hpp"

template <std::size_t N>
std::istream &operator>>(std::istream &os, std::array<uint32_t, N> &array);

namespace printIP
{
    template <std::size_t N>
    class IP_Pool
    {

    private:
        std::vector<std::array<uint32_t, N>> vect_ip_octets;

        friend std::istream &operator>><>(std::istream &os, std::array<uint32_t, N> &array);

    protected:
    public:
        /* friend std::ostream operator<<(std::ostream &os, const std::vector<std::array<uint8_t, N>> &vect_ip)
        {
            for (std::size_t i = 0; i < vect_ip.size(); ++i)
            {
                if (i != 0)
                    os << ".";
                os << vect_ip[i];
            }
            return os;
        }
*/
        void read_from_stream(std::istream &stream)
        {
            auto locale_prev = stream.imbue(std::locale(stream.getloc(), new printf_white_space));

            std::array<uint32_t, N> addreses{};

            while (stream >> addreses)
            {
                vect_ip_octets.push_back(std::move(addreses));

                stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            stream.imbue(locale_prev);
        }

        void sort_reverse()
        {
            std::sort(vect_ip_octets.begin(), vect_ip_octets.end(), [](std::array<uint32_t, N> &left, std::array<uint32_t, N> &right) {
                for (std::size_t i = 0; i < N; ++i)
                {
                    if (left[i] != right[i])
                      return left[i] > right[i];
                }
                return false;
            });
        }

        std::vector<std::array<uint8_t, N>> filter(std::initializer_list<uint8_t> values)
        {
        }

        void print()
        {
            for (std::size_t i = 0; i < vect_ip_octets.size(); ++i)
            {
                for (std::size_t j = 0; j < N; ++j)
                {
                    if (j != 0)
                        std::cout << ".";
                    std::cout << vect_ip_octets[i][j];
                }
                std::cout << std::endl;
            }
        }

        //void sort_reverse();

        /*  template <uint8_t... Args>
        IP_Pool<IP_V> filter(Args &&... octets);

        IP_Pool<IP_V> filter_any(uint8_t octet);
    
    */
    };

    template <std::size_t N>
    std::istream &operator>>(std::istream &os, std::array<uint32_t, N> &array)
    {
        for (uint32_t &octet : array)
        {
            if (!(os >> octet))
                return os;
        }
        return os;
    }

} // namespace printIP