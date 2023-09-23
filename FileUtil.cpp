#include "FileUtil.h"
#include <stdexcept>
#include <cassert>

namespace mylog {
namespace FileUtil {

AppendFile::AppendFile(const std::string& fileName) : fp_(nullptr), buffer_(), bufferPos_(0) {
    fp_ = fopen(fileName.c_str(), "a");  // Open file in append mode
    if (!fp_) {
        throw std::runtime_error("Failed to open file for appending");
    }
}

AppendFile::~AppendFile() {
    flush();  // Flush any remaining data before closing the file
    if (fp_) {
        fclose(fp_);
    }
}

void AppendFile::append(const std::string& content) {
    assert(fp_);
    
    if (bufferPos_ + content.size() > kBufferSize) {
        // Flush the buffer if adding this content exceeds the buffer size
        flush();
    }
    
    if (content.size() <= kBufferSize) {
        // If content fits in buffer, add it to buffer
        std::copy(content.begin(), content.end(), buffer_ + bufferPos_);
        bufferPos_ += content.size();
    }
    else {
        // If content is larger than buffer, flush buffer and write directly to file
        flush();
        fwrite(content.c_str(), 1, content.size(), fp_);
    }
}


off_t AppendFile::length() {
    assert(fp_);

    return ftell(fp_);
}

void AppendFile::flush() {
    assert(fp_);
    
    if (bufferPos_ > 0) {
        fwrite(buffer_, sizeof buffer_[0], bufferPos_, fp_);
        bufferPos_ = 0;
    }
    fflush(fp_);
}

} 
}

