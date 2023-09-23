#include "Logger.h"
#include <iostream>
#include <cstring>

namespace mylog {

Logger::Logger(const char* file, int line, LogLevel level, const char* filename)
    : impl_(level, file, line, filename) {
}


Logger::~Logger() {
    impl_.finish();
    if (impl_.level_ == LogLevel::FATAL) {
        std::cerr << "Abort due to fatal log" << std::endl;
    }
}

Logger::Impl::Impl(LogLevel level, const char* file, int line, const char* logfile)
    : level_(level),
      logfile_(logfile),
      stream_(),
      time_() {
    formatTime();
    stream_ << "[" << LogLevelNames[static_cast<int>(level_)] << "] ";
    if (file) {
        stream_ << file << ":" << line << " - ";
    }
}

void Logger::Impl::formatTime() {
    stream_ << time_.get();
}

void Logger::Impl::finish() {
    stream_ << "\n";
    std::string& data = stream_.Buffer();
    logfile_.append(data);
    logfile_.flush();
}

}

