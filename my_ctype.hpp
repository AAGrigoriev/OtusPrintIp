#pragma once

#include <locale>

namespace printIP
{
    struct printf_white_space : std::ctype<char>
    {
        typedef std::ctype<char> c_base;
        
        static const mask *make_table();
        
        printf_white_space(std::size_t refs = 0) : ctype(make_table(), false, refs) {}
    };

} // namespace printIP