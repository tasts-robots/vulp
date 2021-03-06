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

#include "vulp/utils/realtime.h"

#include "gtest/gtest.h"

namespace vulp::utils {

TEST(Realtime, ConfigureCPU) { ASSERT_NO_THROW(configure_cpu(0)); }

TEST(Realtime, ConfigureScheduler) {
  constexpr int priority = 10;
  ASSERT_THROW(configure_scheduler(priority), std::runtime_error);
}

}  // namespace vulp::utils
