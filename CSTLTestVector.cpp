//
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

#include "CSTLTestVector.h"
#include <iostream>

CSTLTestVector::CSTLTestVector(void) {

}

CSTLTestVector::~CSTLTestVector() {

}

void CSTLTestVector::setup(void) {
    setup(10);
}

void CSTLTestVector::setup(int nSize)
{
    for(int i=0; i<nSize; i++){
        mContainer.push_back(i);
    }
}

void CSTLTestVector::cleanup(void) {

}

void CSTLTestVector::test(void) {
    // get size
    std::cout << "size = " << mContainer.size() << std::endl;

    // iterator with explicit type define
    for(std::vector<int>::iterator it=mContainer.begin(); it!=mContainer.end(); it++){
        std::cout << *it << std::endl;
    }

    // iterator with auto
    for(auto it = mContainer.begin(); it!=mContainer.end(); it++) {
        std::cout << *it << std::endl;
    }
}

