#pragma once

template<typename Type>
Type lerp(double t, const Type& a, const Type& b){
     return a + t * (b - a);
}