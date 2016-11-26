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


template <typename T>
class vector2dUtil
{
public:
	static std::vector<std::vector<T>> transpose(std::vector<std::vector<T>>& inData)
	{
		std::vector<std::vector<T>> outData;
		if(inData.size()!=0) {
			outData.assign(inData[0].size(), std::vector<T>(inData.size()));
			for (int x = 0; x < inData.size(); x++) {
				for (int y = 0; y < inData[x].size(); y++) {
					outData[y][x] = inData[x][y];
				}
			}
		}
		return outData;
	}
};


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

	// insert
	std::vector<int> v{0};
	std::vector<int> v2{503,502,501};
	v.insert(v.begin(), v2.begin(), v2.end()); // insert v2 for head of v.
	for( auto& item : v ){
		std::cout << item << std::endl; // 503,502,501,0
	}

	// sort
	std::sort( v.begin(), v.end()); // normal order
	for( auto& item : v ){ std::cout << item << std::endl;}
	std::sort( v.begin(), v.end(),std::greater<int>()); // reverse order
	for( auto& item : v ){ std::cout << item << std::endl;}
	// sort with rambda
	std::sort( v.begin(), v.end(),
			   [](const int& a, const int& b){
				   return (a < b);
			   }
	);
	for( auto& item : v ){ std::cout << item << std::endl;}

	// 2 dimensions vector [10][20] with 0 initial value
	std::vector< std::vector<int> > xyMap(10, std::vector<int>(20,0));
	for(int x=0; x<xyMap.size(); x++){
		for(int y=0; y<xyMap[0].size(); y++){
			xyMap[x][y]=y;
		}
	}
	for(auto& aLine : xyMap ){
		for(auto& aVal : aLine ) {
			std::cout << std::to_string(aVal) << ",";
		}
		std::cout << std::endl;
	}

	for(auto& aLine : vector2dUtil<int>::transpose(xyMap)){
		for(auto& aVal : aLine ) {
			std::cout << std::to_string(aVal) << ",";
		}
		std::cout << std::endl;
	}
}


