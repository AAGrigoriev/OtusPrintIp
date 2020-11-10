#pragma once

#include <array>
#include <vector>
#include <limits>
#include <algorithm>
#include <initializer_list>
#include <assert.h>

#include "my_ctype.hpp"

template <std::size_t N>
std::istream &operator>>(std::istream &os, std::array<uint32_t, N> &array);

template <std::size_t N>
std::ostream &operator<<(std::ostream &os, const std::vector<std::array<uint32_t, N>> &vect_ip);

namespace otusPrint
{
    template <std::size_t N>
    class IP_Pool
    {

    private:
        std::vector<std::array<uint32_t, N>> vect_ip_octets;

    protected:

    public:
    
        friend std::istream &operator>><>(std::istream &os, std::array<uint32_t, N> &array);

        friend std::ostream &operator<<<>(std::ostream &os, const std::vector<std::array<uint32_t, N>> &vect_ip);

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

        template <typename... Args>
        std::vector<std::array<uint32_t, N>> filter(Args... args) const
        {
            static_assert(sizeof...(args) <= N);

            std::array<uint32_t, sizeof...(args)> array_to_lamda = {args...};

            auto lamda_find = [&array_to_lamda](const std::array<uint32_t, N> &array_in_vec) {
                for (std::size_t i = 0; i < array_to_lamda.size(); ++i)
                {
                    if (array_in_vec[i] != array_to_lamda[i])
                        return false;
                }
                return true;
            };

            auto iterBegin = std::find_if(vect_ip_octets.begin(), vect_ip_octets.end(), lamda_find);

            auto iterEnd = std::find_if_not(iterBegin, vect_ip_octets.end(), lamda_find);

            return std::vector<std::array<uint32_t, N>>(iterBegin, iterEnd);
        }

        std::vector<std::array<uint32_t, N>> fileter_any(uint32_t arg) const
        {
            std::vector<std::array<uint32_t, N>> out;

            auto lamda_find = [arg, &out](const std::array<uint32_t, N> &array) {
                for (auto iterBeg = array.cbegin(); iterBeg != array.cend(); ++iterBeg)
                {
                    if ((*iterBeg) == arg)
                        out.push_back(array);
                }
            };

            std::for_each(vect_ip_octets.begin(), vect_ip_octets.end(), lamda_find);

            return out;
        }

        /*   void print() const
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
        */
    };
} // namespace otusPrint

template <std::size_t N>
std::ostream &operator<<(std::ostream &os, const std::vector<std::array<uint32_t, N>> &vect_ip)
{
    for (auto vec_begin = vect_ip.begin(); vec_begin != vect_ip.end(); ++vec_begin)
    {
        for (auto array_begin = (*vec_begin).begin(); array_begin != (*vec_begin).end(); ++array_begin)
        {
            os << (*array_begin);
            if (array_begin < (*vec_begin).end() - 1)
                os << ".";
        }
        os << std::endl;
    }
    return os;
}

template <std::size_t N>
std::istream &operator>>(std::istream &os, std::array<uint32_t, N> &array)
{
    for (uint32_t &octet : array)
    {
        if (!(os >> octet))
            assert(octet > 0 && octet <= 255 && "invalid param");
            return os;
    }
    return os;
}
