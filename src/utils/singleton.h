#pragma once

template <typename T>
class singleton
{
    public:

        static T& instance()
        {
            static T instance;
            return instance;
        }

        singleton(const singleton&) = delete;
        singleton& operator=(const singleton&) = delete;

    protected:
        singleton() = default;
        virtual ~singleton() = default;
};