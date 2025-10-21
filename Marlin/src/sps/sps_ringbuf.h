#pragma once
#include <stddef.h>
template<typename T,size_t C>struct RingBuf{T b[C];volatile size_t r=0,w=0;bool push(const T&v){size_t n=(w+1)%C; if(n==r) return false; b[w]=v; w=n; return true;}bool pop(T&out){if(r==w) return false; out=b[r]; r=(r+1)%C; return true;}size_t size()const{return (w+C-r)%C;}void clear(){r=w=0;}};
