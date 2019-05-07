// Copyright 2019 Open GEE Contributors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string>
#include <gtest/gtest.h>
#include "common/khxml/khxml.h"

SimpleMemoryManager SimpleMemoryManager::memoryManager;

class khXMLTest : public testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(khXMLTest, allocateTest) {
  for (int i = 0; i < 1000000; ++i) {
      SimpleMemoryManager::memoryManager.allocate(1000000);
  }

  SimpleMemoryManager::memoryManager.deallocateAll();
}

TEST_F(khXMLTest, lessTest) {
  std::string c = "c";
  std::string b = "b";
  std::string a = "a";
  
  std::map<unsigned long, int> testmap;
  testmap[reinterpret_cast<unsigned long>(c.c_str())] = 3;
  testmap[reinterpret_cast<unsigned long>(b.c_str())] = 2;
  testmap[reinterpret_cast<unsigned long>(a.c_str())] = 1;

  for (std::pair<unsigned long, int> item: testmap) {
    std::cout << item.first << std::endl;
  }

  std::map<unsigned char*, int> testmap2;
  testmap2[reinterpret_cast<unsigned char*>(const_cast<char *>(c.c_str()))] = 3;
  testmap2[reinterpret_cast<unsigned char*>(const_cast<char *>(b.c_str()))] = 2;
  testmap2[reinterpret_cast<unsigned char*>(const_cast<char *>(a.c_str()))] = 1;

  for (std::pair<unsigned char*, int> item: testmap2) {
    std::cout << item.first << std::endl;
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
