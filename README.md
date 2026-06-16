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

## Logger (sea5kg::log)

* Output will be colored for console, but color will be missing for files.
* Functions are safe thread.
* Logger supports a log rotation (every 51000 seconds / every day)
* sea5kg::log::throw_err - will be generate `throw std::runtime_error(sMessage);`
* `std::vector<std::string> sea5kg::log::getLastLogMessages()` - last 50 records from log

To init logger first and enable.

```
#include <sea5kg_logger.h>

int main(int argc, char* argv[]) {
  const std::string TAG = "MAIN";
  sea5kg::log::set_rotation_period_in_seconds(60*5); // every 5 minutes
  sea5kg::log::set_log_level_console_output(sea5kg::log_level::INFO);
  sea5kg::log::set_log_dirpath(".logs/%Y/%m/%d");
  sea5kg::log::set_log_filename_prefix("main_");
  sea5kg::log::set_enable_log_file(true);
  sea5kg::log::set_runtime_history_size(50);
  sea5kg::log::debug(TAG, "Hello info");
  sea5kg::log::info(TAG, "Hello info");
  sea5kg::log::success(TAG, "Hello ok");
  sea5kg::log::error(TAG, "Hello err");
  sea5kg::log::warning(TAG, "Hello warn");
  return 0;
}
```

Example console output:
```
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [INFO] MAIN: Hello info
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [SUCCESS] MAIN: Hello ok
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [ERROR] MAIN: Hello err
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [WARNING] MAIN: Hello warn
```

Example file output:
```
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [DEBUG] MAIN: Hello info
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [INFO] MAIN: Hello info
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [SUCCESS] MAIN: Hello ok
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [ERROR] MAIN: Hello err
2026-06-16 12:58:56.634, 0x00007b1d23e94740 [WARNING] MAIN: Hello warn
```
