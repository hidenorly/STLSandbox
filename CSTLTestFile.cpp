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

#include <fstream>
#include <iostream>
#include "CSTLTestFile.h"

CSTLTestFile::CSTLTestFile(void)
{

}

CSTLTestFile::~CSTLTestFile()
{

}

void CSTLTestFile::setup(void)
{

}

void CSTLTestFile::test(void)
{
	// text file write
	{
		std::ofstream ofs("temp.txt");
		if (ofs) {
			ofs << "Hello, world1" << std::endl;
			ofs << "Hello, world2" << std::endl;
		}
	}

	// text file read
	{
		std::ifstream ifs("temp.txt");
		if ( ifs ) {
			while (!ifs.eof()) {
				std::string buf;
				getline(ifs, buf);
				if( !buf.empty() ) {
					std::cout << buf << std::endl;
				}
			}
		}
	}

	// binary file write
	{
		std::ofstream ofs("temp.bin", std::ios_base::out | std::ios_base::binary);
		if( ofs ){
			int n = 1000;
			ofs.write( (const char*)&n, sizeof(n));
		}
	}

	// binary file read
	{
		std::ifstream ifs("temp.bin", std::ios_base::in | std::ios_base::binary);
		if( ifs ){
			int n=0;
			ifs.read((char*)&n,sizeof(n));
			std::cout << n << std::endl;
		}
	}
}

void CSTLTestFile::cleanup(void)
{
	std::remove("temp.txt");
	std::remove("temp.bin");
}
