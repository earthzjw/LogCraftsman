#ifndef MY_FILEUTIL_H
#define MY_FILEUTIL_H
#include <string>
namespace mylog{
    namespace FileUtil{
    
        class AppendFile{
            public:
            explicit AppendFile(const std::string& fileName);
            
            ~AppendFile();

            void append(const std::string& content);

            void flush();

            off_t length();

            private:
            FILE* fp_;
            const int kBufferSize = 8192;
            char buffer_[8192];
            int bufferPos_;

        };
    }
}

#endif