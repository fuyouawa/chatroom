#pragma once

namespace chatroom
{
enum UserState
{
    kOnline,
    kOffline
};

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
}