#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <chrono>
#include <ctime>
#include <cstdio>
#include <cstring>

class Timestamp {
public:
    Timestamp() {
        update();
    }

    void update() {
        auto now = std::chrono::system_clock::now();
        auto nowMs = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        auto value = nowMs.time_since_epoch().count();

        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::strftime(timestampStr_, sizeof(timestampStr_), "[%Y-%m-%d %H:%M:%S.", std::localtime(&currentTime));

        snprintf(timestampStr_ + strlen(timestampStr_), sizeof(timestampStr_) - strlen(timestampStr_), "%03lld]", static_cast<long long>(value % 1000));
    }

    const char* get() const {
        return timestampStr_;
    }

private:
    char timestampStr_[32];
};

#endif
