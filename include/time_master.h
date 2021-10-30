#ifndef TIME_MASTER
#define TIME_MASTER

#include <iostream>
#include <chrono>

class time_master
{
public:
    time_master()
    {
        start_time = get_now_millis();
    }
    uint64_t millis_since_start()
    {
        return get_now_millis() - start_time;
    }
    void print_time()
    {
        std::cout << "(" << millis_since_start() << ") ";
    }

private:
    uint64_t get_now_millis()
    {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
    uint64_t start_time;
};

#endif /* TIME_MASTER */
