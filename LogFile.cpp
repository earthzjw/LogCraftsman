// LogFile.cpp

#include "LogFile.h"
#include "FileUtil.h"

namespace mylog {

LogFile::LogFile(const std::string& filename,
                 off_t rollsize,
                 bool threadSafe,
                 int flushInterval,
                 int checkEveryN)
    : fileName_(filename),
      rollSize_(rollsize),
      file_(new FileUtil::AppendFile(filename)) {
}

LogFile::LogFile(const char* filename,
                 off_t rollsize,
                 bool threadSafe,
                 int flushInterval,
                 int checkEveryN)
    : fileName_(std::string(filename)),
      rollSize_(rollsize),
      file_(new FileUtil::AppendFile(filename)) {
}

void LogFile::append(std::string& content) {
    if (file_) {
        file_->append(content);
        if (file_->length() > rollSize_) {
            rollFile();
        }
    }
}

void LogFile::append(const char* content) {
    if (file_) {
        file_->append(std::string(content));
        if (file_->length() > rollSize_) {
            rollFile();
        }
    }
}

void LogFile::flush() {
    if (file_) {
        file_->flush();
    }
}

bool LogFile::rollFile() {
    if (file_) {
        file_->flush();
        file_.reset();  // Close the current file
        
        // Generate a new file name, by appending ".old" as a suffix
        std::string newFileName = fileName_ + ".old"; 
        
        // Rename the old file to the new name
        if (rename(fileName_.c_str(), newFileName.c_str()) != 0) {
            // Handle error, e.g., log an error message
            return false;
        }
        
        // Open a new file
        file_.reset(new FileUtil::AppendFile(fileName_));
        return true;
    }
    return false;
}


}
