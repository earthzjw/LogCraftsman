#ifndef LOGGER_H
#define LOGGER_H

#include "Logging.h"
#include "LogFile.h"
#include "LogStream.h"
#include "Timestamp.h"
#include <cassert>
namespace mylog {

class Logger {
public:
    Logger(const char* file, int line, LogLevel level, const char* logFile = "default.log");
    ~Logger();

    LogStream& stream() { return impl_.stream_; }

    //static void setLogLevel(LogLevel level);
    /*static void setDefaultLogFile(const char* filename) {
        assert(filename);
        defaultLogFile_ = filename;
    }*/

private:
    struct Impl {
        Impl(LogLevel level, const char* file, int line, const char * logFile);
        void formatTime();
        void finish();
        ~Impl() = default;
        LogFile logfile_;
        LogLevel level_;
        LogStream stream_;
        Timestamp time_;
    };
    //static std::string defaultLogFile_;
    Impl impl_;
};

//std::string Logger::defaultLogFile_ = "default.log";

#define LOG_TRACE \
    mylog::Logger(__FILE__, __LINE__, mylog::LogLevel::TRACE).stream()
#define LOG_DEBUG  \
    mylog::Logger(__FILE__, __LINE__, mylog::LogLevel::DEBUG).stream()

#define LOG_INFO \
    mylog::Logger(__FILE__, __LINE__, mylog::LogLevel::INFO).stream()

#define LOG_WARN mylog::Logger(__FILE__, __LINE__, mylog::LogLevel::WARN).stream()
#define LOG_ERROR mylog::Logger(__FILE__, __LINE__, mylog::LogLevel::ERROR).stream()
#define LOG_FATAL mylog::Logger(__FILE__, __LINE__, mylog::LogLevel::FATAL).stream()
//#define SET_DEFAULT_LOG_FILE(filename) mylog::Logger::setDefaultLogFile(filename)

}

#endif
