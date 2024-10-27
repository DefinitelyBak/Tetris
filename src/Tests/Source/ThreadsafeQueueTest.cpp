#include <gtest/gtest.h>

#include "Precompile.h"

#include "Data/ThreadsafeQueue.h"


namespace Tetris::Tests
{

    class ThreadSafeQueueTest : public ::testing::Test 
    {
    protected:
        Data::ThreadsafeQueue<int> queue_;
    };

    TEST_F(ThreadSafeQueueTest, PushPopSingleElement)
    {
        queue_.push(42);
        std::shared_ptr<int> value = queue_.try_pop();
        bool isEmpty(value);

        ASSERT_TRUE(isEmpty);
        EXPECT_EQ(*value, 42);
    }

    TEST_F(ThreadSafeQueueTest, PopEmptyQueue)
    {
        std::shared_ptr<int> value = queue_.try_pop();
        bool isEmpty(value);

        ASSERT_FALSE(isEmpty);
    }

    TEST_F(ThreadSafeQueueTest, PopMultipleElements)
    {
        for (int i = 0; i < 10; ++i) {
            queue_.push(i);
        }
        
        for (int i = 0; i < 10; ++i) {
            std::shared_ptr<int> value = queue_.try_pop();
            bool isEmpty(value);

            ASSERT_TRUE(isEmpty);
            EXPECT_EQ(*value, i);
        }
    }

    TEST_F(ThreadSafeQueueTest, ConcurrentPushPop)
    {
        const int num_threads = 10;
        const int num_elements_per_thread = 100;
        std::atomic<int> total_enqueued(0);
        std::atomic<int> total_dequeued(0);
    
        auto enqueue_task = [this, &total_enqueued](int start)
        {
            int _start = start;
            for (int i = 0; i < num_elements_per_thread; ++i)
            {
                queue_.push(_start + i);
                total_enqueued++;
            }
        };

        auto dequeue_task = [this, &total_dequeued]()
        {
            for (int i = 0; i < num_threads * num_elements_per_thread; ++i) 
            {
                auto value = queue_.try_pop();
                total_dequeued++;
            }
        };

        std::vector<std::thread> threads;
        
        for (int i = 0; i < num_threads; ++i)
            threads.emplace_back(enqueue_task, i * num_elements_per_thread);

        threads.emplace_back(dequeue_task);

        for (auto& thread : threads)
            thread.join();

        EXPECT_EQ(total_enqueued.load(), total_dequeued.load());
    }

    TEST_F(ThreadSafeQueueTest, PopFromEmptyQueueInThread)
    {
        std::thread t([this](){
            std::shared_ptr<int> value = queue_.try_pop();
            bool isEmpty(value);

            ASSERT_FALSE(isEmpty);
        });
        
        t.join();
    }

} // namespace