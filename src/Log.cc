#include "Log.hh"

#include <cstring>
#include <iostream>
#include <chrono>
#include <iomanip>

namespace Abdillah::Ellog {
    const char* Log::TAG_INFO   = "[  INFO]";
    const char* Log::TAG_NOTICE = "[NOTICE]";
    const char* Log::TAG_WARN   = "[  WARN]";
    const char* Log::TAG_ERROR  = "[ ERROR]";

    Log::Log (const char* channel_name)
        : channel_name (channel_name)
    {}

    void
    Log::log (const char* tag, const char* msg)
    {
        char* currtime = this->now();
        // Formatter
        std::printf("%s %s: %s\n", currtime, tag, msg);
        std::cout.flush();

        delete currtime;
    }

    char*
    Log::now ()
    {
        std::chrono::time_point<std::chrono::system_clock> current_time = std::chrono::system_clock::now();
        std::time_t current_time_t = std::chrono::system_clock::to_time_t (current_time);

        char* time_ = (char*) malloc(sizeof (char) * (21));
        std::strftime (time_, 21, "%b %d %H:%M:%S %Y", std::localtime(&current_time_t));
        return time_;
    }
}
