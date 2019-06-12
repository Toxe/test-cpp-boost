#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    typedef std::istream_iterator<int> in;

    std::for_each(in(std::cin), in(), std::cout << (boost::lambda::_1 * 3) << " ");
}
