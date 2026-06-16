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

#include <string.h>
#include <iostream>
#include <algorithm>
#include "sea5kg_logger.h"

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
