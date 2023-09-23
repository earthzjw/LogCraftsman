#ifndef MY_LOGGING_H
#define MY_LOGGING_H

namespace mylog{
    enum class LogLevel{
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NUM_LOG_LEVELS,
    };
    extern const char* LogLevelNames[];
}

#endif
