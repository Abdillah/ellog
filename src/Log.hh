#ifndef __LOG_HH__
#define __LOG_HH__

namespace Abdillah::Ellog {
    class Log {
    public:
        static const char* TAG_INFO;
        static const char* TAG_NOTICE;
        static const char* TAG_WARN;
        static const char* TAG_ERROR;

        Log (const char* channel_name);
        void log (const char* tag, const char* msg);

    private:
        const char* channel_name;

        char* now ();
    };
}

#endif
