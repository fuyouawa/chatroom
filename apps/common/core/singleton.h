#pragma once

namespace chatroom
{
template<class T>
class Singleton
{
public:
    static T& instance()
    {
        static T inst;
        return inst;
    }

    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

protected:
    Singleton() = default;
};

template<class T>
class ThreadSingleton
{
public:
    static T& instance()
    {
        thread_local static T inst;
        return inst;
    }

    ~ThreadSingleton() = default;

    ThreadSingleton(const ThreadSingleton&) = delete;
    ThreadSingleton(ThreadSingleton&&) = delete;
    ThreadSingleton& operator=(const ThreadSingleton&) = delete;
    ThreadSingleton& operator=(ThreadSingleton&&) = delete;

protected:
    ThreadSingleton() = default;
};
}