# Algorithm

Should I document a member function in header file, source file, or both?
I prefer putting the API documentation (purpose, parameters, return values, pre/postconditions etc.) into the header, and implementation documentation (if there is any) into the source file. The latter I feel necessary only when e.g. a specific nontrivial algorithm is used, some performance tuning trick is applied, or the implementation is not straightforward for some other reason. (By default, clarity of code is paramount, thus there should be no need for implementation comments.)

At any rate, I strive to stick to the DRY principle, thus any piece of documentation should only have a single defining source.


In C++ we tend to define generic types based on other constraints other than "inherits from this class". 
http://stackoverflow.com/a/25216349



CMake structure with gtest
https://stackoverflow.com/a/37107097

Google Test Tutorial
https://github.com/google/googletest/blob/master/googletest/docs/Primer.md

Todo:
Skyline problem
Wildcard matching