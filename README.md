# sea5kg-logger

<p align="center">
    <a href="https://github.com/sea5kg/sea5kg-logger" alt="Activity">
        <img src="https://img.shields.io/github/commit-activity/m/sea5kg/sea5kg-logger" />
    </a>
</p>

[![Github Stars](https://img.shields.io/github/stars/sea5kg/sea5kg-logger.svg?label=github%20%E2%98%85)](https://github.com/sea5kg/sea5kg-logger/stargazers) [![Github Stars](https://img.shields.io/github/contributors/sea5kg/sea5kg-logger.svg)](https://github.com/sea5kg/sea5kg-logger/) [![Github Forks](https://img.shields.io/github/forks/sea5kg/sea5kg-logger.svg?label=github%20forks)](https://github.com/sea5kg/sea5kg-logger/network/members)

C++ Logger Implementation (Safe-Threading)

## Integrate to your project

```
$ wsjcpp install https://github.com/sea5kg/sea5kg-logger:master
```

Or include files:

* `src/sea5kg/logger/sea5kg_logger.h`
* `src/sea5kg/logger/sea5kg_logger.cpp`

## Logger (sea5kg::Log)

* Output will be colored for console, but color will be missing for files.
* Functions are safe thread.
* Logger supports a log rotation (every 51000 seconds / every day)
* sea5kg::Log::throw_err - will be generate `throw std::runtime_error(sMessage);`
* std::vector<std::string> sea5kg::Log::getLastLogMessages() - last 50 records from log

To init logger first and enable.

```
#include <wsjcpp_logger.h>

int main(int argc, char* argv[]) {
    std::string TAG = "MAIN";
    sea5kg::Log::setLogDirectory(".logs");
    sea5kg::Log::setPrefixLogFile("app");
    sea5kg::Log::setEnableLogFile(true);

    sea5kg::Log::debug(TAG, "Hello info");
    sea5kg::Log::info(TAG, "Hello info");
    sea5kg::Log::err(TAG, "Hello err");
    sea5kg::Log::warn(TAG, "Hello warn");
    sea5kg::Log::ok(TAG, "Hello ok");

    return 0;
}
```

Example output
```
2026-04-22 14:40:07.395, 0x00007aa3e8c98740 [DEBUG] MAIN: Hello info
2026-04-22 14:40:07.395, 0x00007aa3e8c98740 [INFO] MAIN: Hello info
2026-04-22 14:40:07.396, 0x00007aa3e8c98740 [ERR] MAIN: Hello err
2026-04-22 14:40:07.396, 0x00007aa3e8c98740 [WARN] MAIN: Hello warn
2026-04-22 14:40:07.396, 0x00007aa3e8c98740 [OK] MAIN: Hello ok
```
