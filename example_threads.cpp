#include <iostream>
#include <random>
#include <vector>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

void do_something(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(300, 700);

    for (int i = 0; i < 10; ++i) {
        int ms = dist(gen);

        std::stringstream s;
        s << boost::this_thread::get_id() << " Thread #" << n << " sleeping for " << ms << " ms..." << std::endl;
        std::cout << s.str();

        boost::this_thread::sleep_for(boost::chrono::milliseconds{ms});
    }
}

int main()
{
    std::vector<boost::thread> threads;

    for (int i = 0; i < 10; ++i)
        threads.emplace_back(do_something, i);

    for (auto& t : threads)
        t.join();

    std::cout << "Done." << std::endl;
}
