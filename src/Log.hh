#ifndef __LOG_HH__
#define __LOG_HH__

#include <vector>

namespace Abdillah::Ellog {
    struct Channel
    {
        char* name;
        bool is_active;
    };

    class Log {
    public:
        static const char* TAG_INFO;
        static const char* TAG_NOTICE;
        static const char* TAG_WARN;
        static const char* TAG_ERROR;

        static Channel create_channel (char* name);
        static void remove_channel (Channel ch);

        Log (const char* channel_name);
        void log (const char* tag, const char* msg);

    private:
        static std::vector<Channel> channels;
        Channel channel;

        char* now ();
    };
}

#endif
