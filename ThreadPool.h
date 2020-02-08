#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

// using namespace std;

class ThreadPool {
public:
    ThreadPool(size_t);
    ~ThreadPool();

private:
     // keep track of threads so we can add to or join more
    std::vector<std::thread> workers;
    // The task queue
    std::queue<std::function<void()>> tasks;
    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
    : stop(false)
{
    for (size_t i = 0; i < threads; ++i) {

    }
}