/*
Purpose: Avoid multiple instantiations of the same template across different translation units (source files).
Normally, every .cpp file that uses std::vector<X> generates its own instantiation → increases compile time and binary size.
With extern template, you tell the compiler:
“Don’t instantiate this template here; it’s already instantiated elsewhere.”


MySource.cpp explicitly instantiates std::vector<int>.
Other.cpp uses std::vector<int> but doesn’t instantiate it again (thanks to extern template).
Result: Reduced compile time and smaller binary.

extern template class std::vector<X>; tells the compiler “don’t generate code here, it’s already done elsewhere.”
This reduces redundant template instantiations and speeds up compilation.
*/

#include <vector>

// Forward declaration using extern template
extern template class std::vector<int>;  // Avoids re-instantiation in every .cpp
