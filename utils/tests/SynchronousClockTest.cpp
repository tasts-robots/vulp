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

#include "gtest/gtest.h"
#include "vulp/utils/SynchronousClock.h"

namespace vulp::utils {

TEST(SynchronousClock, GetsSomeSleep) {
  SynchronousClock clock(10 /* Hz */);  // 100 ms loop
  ASSERT_DOUBLE_EQ(clock.slack(), 0.);
  for (unsigned i = 0; i < 10; ++i) {
    clock.wait_for_next_tick();
  }
  ASSERT_GT(clock.slack(), 0.01);  // 10% of 100 ms loop
}

TEST(SynchronousClock, NoMarginWhenSkippingCycles) {
  SynchronousClock clock(100 /* Hz */);  // 10 ms loop
  ASSERT_DOUBLE_EQ(clock.slack(), 0.);
  clock.wait_for_next_tick();
  ASSERT_GT(clock.slack(), 0.001);  // 10% of 10 ms loop
  std::this_thread::sleep_for(std::chrono::milliseconds(20));
  clock.wait_for_next_tick();
  ASSERT_DOUBLE_EQ(clock.slack(), 0.);
}

}  // namespace vulp::utils
