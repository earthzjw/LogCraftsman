#ifndef MY_LOGFILE_H
#define MY_LOGFILE_H
#include "LogStream.h"
#include "FileUtil.h"
#include <memory>
#include <string>
#include <cstdio>

namespace mylog{
    class LogFile{
        public:
            LogFile(const std::string& filename,
                    off_t rollsize = 1024 * 1024,
                    bool threadSafe = true,
                    int flushInterval = 3,
                    int checkEveryN = 1024);
            LogFile(const char* filename,
                    off_t rollsize = 1024 * 1024,
                    bool threadSafe = true,
                    int flushInterval = 3,
                    int checkEveryN = 1024);
            ~LogFile() = default;
            void append(std::string&);
            void append(const char*);
            void flush();
            bool rollFile();
            LogFile(const LogFile&) = delete;
            void operator=(const LogFile&) = delete; 
        private:
            const std::string& fileName_;
            const off_t rollSize_;
            std::unique_ptr<FileUtil::AppendFile> file_;
    }; 

}

#endif
