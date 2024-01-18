#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>
#include <iostream>

namespace logger 
{

enum class LogType
{
    logInfo = 0,
    logWarning,
    logError,
    logFatal,
    logDebug,
};

static std::map<LogType, std::string> logTypeStr 
{
    {LogType::logInfo,    "[INF]"},
    {LogType::logWarning, "[WRN]"},
    {LogType::logError,   "[ERR]"},
    {LogType::logFatal,   "[FTL]"},
    {LogType::logDebug,   "[DBG]"},
};

class Logger
{
public:
    static Logger& getLogger()
    {
        static Logger logger;
        return logger;
    }

    static void print(LogType type, std::string&& text)
    {
#ifdef USE_LOGGER
        std::cout << logTypeStr[type] << " " << text << "\n";
#endif
    }

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger& logger) = delete;
    Logger(const Logger&& logger) = delete;
    const Logger& operator=(const Logger& logger) = delete;
    const Logger&& operator=(const Logger&& logger) = delete;
};

} // namespace logger

#endif // LOGGER_H