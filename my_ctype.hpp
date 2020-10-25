#pragma once

#include <locale>

namespace printIP
{
    struct printf_white_space : std::ctype<char>
    {

        static const mask *make_table()
        {
            // make a copy of the "C" locale table
            static std::array<mask, table_size> v;

            std::copy(classic_table(), classic_table() + table_size, v.begin());

            v['.'] |= space; // comma will be classified as whitespace

            return v.data(); // &v[0]
        }

        printf_white_space(std::size_t refs = 0) : ctype(make_table(), false, refs) {}
    };

} // namespace printIP