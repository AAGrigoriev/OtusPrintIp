#include "my_ctype.hpp"
#include <vector>
#include <algorithm>

namespace printIP
{

const std::ctype<char>::mask* printf_white_space::make_table()
{
        // make a copy of the "C" locale table
        static std::array<c_base::mask,c_base::table_size> v;
        
        std::copy(c_base::classic_table(),c_base::classic_table() + c_base::table_size,v.begin());

        v['.'] |=  space;    // comma will be classified as whitespace
        
        return v.data(); // &v[0]
}

}