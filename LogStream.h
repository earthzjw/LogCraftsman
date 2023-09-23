#ifndef MY_LOGSTREAM_H
#define MY_LOGSTREAM_H

#include<string>

namespace mylog{
const int smallBufferSize = 4096;
const int largeBufferSize = 8192;
template<int SIZE>
class FixedBuffer{
    public:
        FixedBuffer() : size_(SIZE), current_(){};
        ~FixedBuffer() = default;
        void append(const std::string &s){
            if(s.size() + length() < size_ ){
                current_ += s;
            }
        }
        std::string& current() { return current_;}
        int length() const { return current_.size();}
        int avail() const { return size_ - current_.size();}
        void reset() { current_.clear(); };
    private:
        int size_;
        std::string current_;
        std::string::const_iterator end(){ return current_.end(); }
};

class LogStream{
    public:
        LogStream() = default;
        ~LogStream() = default;
        LogStream(const LogStream&) = delete;
        void operator=(const LogStream&) = delete;
       
        LogStream& operator<<(const char* value) {
            buffer.append(value); 
            return *this;
        }
        template<typename T>
        LogStream& operator<<(const T& value){
            buffer.append(std::to_string(value));
            return *this;
        };
        std::string& Buffer() { return buffer.current();}
    private:
        FixedBuffer<smallBufferSize> buffer;  
};
}

#endif
