#ifndef _UTF8_XXX_H_
#define _UTF8_XXX_H_

#include <string>

inline size_t utf8_len(const std::string& _Str);

std::string utf8_sub(const std::string& _Str, const size_t _Off, const size_t _Count = std::string::npos);

size_t utf8_find(const std::string& _Str, const std::string& _Dst, const size_t _Off = 0);

size_t utf8_rfind(const std::string& _Str, const std::string& _Dst, const size_t _Off = std::string::npos)

std::string& utf8_insert(std::string& _Str, const size_t _Off, const std::string& _Ins);

#ifdef _UTF8_XXX_IMPLEMENTATION

size_t utf8_len(const std::string& _Str)
{
	size_t _idx = 0, _len = 0;
	while (_Str[_idx]) 
		_len += ((_Str[_idx++] & 0xc0) != 0x80);
	return _len;
}

std::string utf8_sub(const std::string& _Str, const size_t _Off, size_t _Count)
{
	size_t _idx_utf8 = 0, _idx_begin_raw = 0;
	while (_idx_utf8 < _Off && _Str[_idx_begin_raw])
		_idx_utf8 += ((_Str[_idx_begin_raw++] & 0xc0) != 0x80);
	if (_Count == std::string::npos)
		return _Str.substr(_idx_begin_raw);
	size_t _idx_end_raw = _idx_begin_raw;
	while (_idx_utf8 < _Off + _Count && _Str[_idx_end_raw])
		_idx_utf8 += ((_Str[_idx_end_raw++] & 0xc0) != 0x80);
	while ((_Str[_idx_end_raw] & 0xc0) == 0x80 && _Str[_idx_end_raw])
		_idx_end_raw++;
	return _Str.substr(_idx_begin_raw, _idx_end_raw - _idx_begin_raw);
}

size_t utf8_find(const std::string& _Str, const std::string& _Dst, const size_t _Off)
{
	size_t _idx_utf8 = 0, _idx_raw = 0;
	while (_idx_utf8 < _Off && _Str[_idx_raw])
		_idx_utf8 += ((_Str[_idx_raw++] & 0xc0) != 0x80);
	while ((_Str[_idx_raw] & 0xc0) == 0x80 && _Str[_idx_raw]) _idx_raw++;
	size_t _idx_dst_raw = _Str.find(_Dst, _idx_raw);
	if (_idx_dst_raw == std::string::npos) return std::string::npos;
	while (_idx_raw < _idx_dst_raw)
		_idx_utf8 += ((_Str[_idx_raw++] & 0xc0) != 0x80);
	return _idx_utf8;
}

size_t utf8_rfind(const std::string& _Str, const std::string& _Dst, const size_t _Off)
{
	size_t _idx_utf8 = 0, _idx_raw = 0;
	while (_idx_utf8 < _Off && _Str[_idx_raw])
		_idx_utf8 += ((_Str[_idx_raw++] & 0xc0) != 0x80);
	while ((_Str[_idx_raw] & 0xc0) == 0x80 && _Str[_idx_raw]) _idx_raw++;
	size_t _idx_dst_raw = _Str.rfind(_Dst, _idx_raw);
	if (_idx_dst_raw == std::string::npos) return std::string::npos;
	_idx_utf8 = 0, _idx_raw = 0;
	while (_idx_raw < _idx_dst_raw)
		_idx_utf8 += ((_Str[_idx_raw++] & 0xc0) != 0x80);
	return _idx_utf8;
}

std::string& utf8_insert(std::string& _Str, const size_t _Off, const std::string& _Ins)
{
	size_t _idx_utf8 = 0, _idx_raw = 0;
	while (_idx_utf8 < _Off && _Str[_idx_raw])
		_idx_utf8 += ((_Str[_idx_raw++] & 0xc0) != 0x80);
	while ((_Str[_idx_raw] & 0xc0) == 0x80 && _Str[_idx_raw]) _idx_raw++;
	return _Str.insert(_idx_raw, _Ins);
}

#endif  // _UTF8_XXX_IMPLEMENTATION

#endif  // !s_UTF8_XXX_H_