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

#include <iostream>
#include "ISTLTest.h"
#include "CSTLTestVector.h"
#include "CSTLTestArray.h"
#include "CSTLTestString.h"
#include "CSTLTestFile.h"
#include "CSTLTestMap.h"

int main() {
    std::cout << "STL Test" << std::endl;

    std::vector<ISTLTest*> mTests;

    mTests.push_back( new CSTLTestVector() );
    mTests.push_back( new CSTLTestArray() );
    mTests.push_back( new CSTLTestString() );
    mTests.push_back( new CSTLTestFile() );
	mTests.push_back( new CSTLTestMap() );

    for( std::vector<ISTLTest*>::iterator it=mTests.begin(); it<mTests.end(); it++) {
        ISTLTest* pTest=*it;
        pTest->setup();
        pTest->test();
        pTest->cleanup();
    }
    for( std::vector<ISTLTest*>::iterator pTest=mTests.begin(); pTest<mTests.end(); pTest++) {
        delete *pTest;
        *pTest=NULL;
    }
    mTests.clear();

    return 0;
}