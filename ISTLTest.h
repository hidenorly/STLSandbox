/*
 Copyright (C) 2016 hidenorly

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef ITEST1_STLTEST_H
#define ITEST1_STLTEST_H

#include <string>

class ISTLTest {
public:
    ISTLTest(void){};
    virtual ~ISTLTest(){};
    virtual void setup(void)=0;
    virtual void test(void)=0;
    virtual void cleanup(void)=0;

protected:
    void puts(const std::string& str);
	void puts(const int val);
};

#endif //ITEST1_STLTEST_H
