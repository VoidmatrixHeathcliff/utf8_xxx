# utf8_xxx

header-only UTF-8 string functions based on STL-string

+ size_t utf8_len(const std::string& _Str)

+ std::string utf8_sub(const std::string& _Str, const size_t _Off, const size_t _Count = std::string::npos)

+ size_t utf8_find(const std::string& _Str, const std::string& _Dst, const size_t _Off = 0)

+ size_t utf8_rfind(const std::string& _Str, const std::string& _Dst, const size_t _Off = std::string::npos)

+ std::string& utf8_insert(std::string& _Str, const size_t _Off, const std::string& _Ins)

**define _UTF8_XXX_IMPLEMENTATION to enable the function definitions**