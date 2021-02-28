#include <iostream>
#include <chrono>
#include <random>

int rand_int_in_n(int max)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(1, max);

//    for( unsigned long j = 0; j < 100500; ++j )
//    {
//        std::cout << distrib(gen) << ' ';
//    }

//    std::cout << '\n';
    return distrib(gen);
}
