#include "Log.hh"

#include <cstring>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

namespace Abdillah::Ellog {
    const char* Log::TAG_INFO   = "[  INFO]";
    const char* Log::TAG_NOTICE = "[NOTICE]";
    const char* Log::TAG_WARN   = "[  WARN]";
    const char* Log::TAG_ERROR  = "[ ERROR]";

    std::vector<Channel> Log::channels;

    Log::Log (const char* channel_name)
    {
        char name[20];
        std::strcpy(name, channel_name);
        this->channel = Log::create_channel(name);
    }

    Log::~Log ()
    {
        Log::remove_channel (this->channel);
    }

    Channel
    Log::create_channel (char* name)
    {
        Channel ch = {
            .name = name,
            .is_active = true
        };
        Log::channels.push_back(ch);
        return ch;
    }

    void
    Log::remove_channel (Channel ch)
    {
        // `std::vector<Channel>::iterator` is the type
        // but `auto` is preferred
        auto rem_iter = std::remove_if (Log::channels.begin(),
                                        Log::channels.end(),
                                        [ch](Channel const& item) {
                                            return !std::strcmp(item.name, ch.name);
                                        });
        Log::channels.erase (rem_iter, Log::channels.end());
        return;
    }

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
