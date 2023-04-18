#pragma once

#include <string>
#include <memory>

namespace diamant
{
    class file_not_found_exception: public std::exception 
    { 
    public:
        file_not_found_exception(const std::string& file_path) 
        {
            message = std::make_unique<std::string>("File not found: " + file_path);
        }

        virtual const char* what() const noexcept override {
            return message->c_str();
        }
    private:
        std::unique_ptr<std::string> message;
    };
}