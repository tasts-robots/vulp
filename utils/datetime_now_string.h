/*
 * Copyright 2022 Stéphane Caron
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

namespace vulp::utils {

/*! Generate a date-time string for time of call.
 *
 * \return Date-time string at the time the function is called.
 */
inline std::string datetime_now_string() {
  auto time = std::time(nullptr);
  auto datetime = *std::localtime(&time);
  std::ostringstream output;
  output << std::put_time(&datetime, "%Y%m%d-%H%M%S");
  return output.str();
}

}  // namespace vulp::utils
