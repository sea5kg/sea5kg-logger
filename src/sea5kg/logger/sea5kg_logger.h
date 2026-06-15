/*
 * MIT License
 *
 * Copyright (c) 2019-2026 Evgenii Sopov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

// original source-code: https://github.com/sea5kg/sea5kg-logger

#ifndef SEA5KG_LOGGER_H
#define SEA5KG_LOGGER_H

#define SEA5KG_LOGGER_VER "1.0.1"
#define SEA5KG_LOGGER_VER_MAJOR "1"
#define SEA5KG_LOGGER_VER_MINOR "0"
#define SEA5KG_LOGGER_VER_BUILD "1"
#define SEA5KG_LOGGER_VER_1
#define SEA5KG_LOGGER_VER_1_0
#define SEA5KG_LOGGER_VER_1_0_1

#include <string>
#include <vector>
// #include <map>
#include <mutex>
#include <deque>

namespace sea5kg {

class Config {
public:
  Config();
  void doLogRotateUpdateFilename(bool bForce = false);
  std::mutex logMutex;
  std::string logDir;
  std::string logPrefixFile;
  std::string logFile;
  bool enableLogFile;
  long logStartTime;
  long logRotationPeriodInSeconds;
  std::deque<std::string> logLastMessages;
};

class Global {
public:
  Global();
  std::vector<Config *> logs;
private:
  int m_logVectorSize;
};

class Log {
public:
  static Global g_GLOBAL;

  static void debug(const std::string &sTag, const std::string &sMessage);
  static void info(const std::string &sTag, const std::string &sMessage);
  static void err(const std::string &sTag, const std::string &sMessage);
  static void throw_err(const std::string &sTag, const std::string &sMessage);
  static void warn(const std::string &sTag, const std::string &sMessage);
  static void ok(const std::string &sTag, const std::string &sMessage);
  static std::vector<std::string> getLastLogMessages();
  static void setLogDirectory(const std::string &sDirectoryPath);
  static void setPrefixLogFile(const std::string &sPrefixLogFile);
  static void setEnableLogFile(bool bEnable);
  static void setRotationPeriodInSec(long nRotationPeriodInSec);
};

} // namespace sea5kg


#endif // SEA5KG_LOGGER_H
