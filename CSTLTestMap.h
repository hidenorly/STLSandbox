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

#ifndef TEST1_CSTLTESTMAP_H
#define TEST1_CSTLTESTMAP_H


#include "ISTLTest.h"

class CSTLTestMap : public ISTLTest {
public:
	CSTLTestMap(void){};
	virtual ~CSTLTestMap(){};
	virtual void setup(void);
	virtual void test(void);
	virtual void cleanup(void);
};


#endif //TEST1_CSTLTESTMAP_H
