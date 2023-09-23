#include "Logger.h"
#include <chrono>
#include <thread>

int main() {
    
    //mylog::Logger::setLogLevel(mylog::LogLevel::FATAL);
    
    // Output various log levels
    LOG_TRACE << "This is a trace message.\n";
    LOG_DEBUG << "This is a debug message.\n";
    LOG_INFO << "This is an info message.\n";
    LOG_WARN << "This is a warning message.\n";
    LOG_ERROR << "This is an error message.\n";
    LOG_FATAL << "This is a fatal message.\n";
	//auto traceStream = std::move(mylog::Logger(__FILE__,__LINE__,mylog::LogLevel::TRACE, "TRACELOG").stream());
	mylog::Logger(__FILE__,__LINE__,mylog::LogLevel::TRACE, "TRACELOG").stream() << "testTRace\n";
    // Perform a time-consuming task and measure execution time
    auto startTime = std::chrono::system_clock::now();
 	for(int i = 0;i < 100000000;++i){
 		i += 0;
 	}
    auto endTime = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    LOG_INFO << "Time taken: " << duration.count() << " milliseconds.";
    return 0;
}
