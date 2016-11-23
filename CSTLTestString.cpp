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

#include "CSTLTestString.h"
#include <iostream>
#include <string>

CSTLTestString::CSTLTestString(void) {

}

CSTLTestString::~CSTLTestString() {

}

void CSTLTestString::setup(void) {

}

void CSTLTestString::test(void) {
	std::string s1 = "test";
	puts(s1);

	// length
	std::string s2 = "0123456789abcdef";
	std::cout << "length(\"" << s2 << "\") = " << s2.length() << " size(same)=" << s2.size() << std::endl;   // 16 16

	// similar of mid/slice(begin...end)
	std::string s3;
	s3.assign(&s2[5], &s2[10]);     // 56789
	puts(s3);

	// concat
	std::string s4 = s2+s3;
	puts(s4);

	// insert with iterator
	std::string hoge = "hoge";
	s4.insert(s4.begin(), hoge.begin(), hoge.end());
	puts(s4);

	// insert with index
	s4.insert(0, "???");
	puts(s4);

	// empty (better way to check whether empty or not)
	std::string s5;
	puts( s5.empty() ? "empty" : "not empty");

	// find
	std::string s6 = "0123456789abcdef5";
	puts( s6.find("5") );	// 5
	puts( s6.rfind("5") );	// 16

	// substring (slice)
	puts( s6.substr( s6.find("5")) );
	puts( s6.substr( s6.find("5"), 3) );	// begin_index,length

	/*
	std::string tmp;
	//tmp.insert( tmp.begin(), s6.begin()+s6.rfind("5"), s6.end() );
	tmp.assign(s6, s6.rfind("5"), s6.length()-s6.rfind("5"));
	puts(tmp);
	*/

	std::string::size_type index = s6.find("hoge");
	puts( index );
	puts( (index == std::string::npos) ? "not found" : "found" );

	// conversion
	int val=100;
	std::string s7 = std::to_string(val);	// it's not std::itos()....
	puts( s7 );

	int val2 = std::stoi(s7);	// it's not std::to_integer().....
	puts(val2);

	// utf8
	std::string utf8str = u8"日本語テスト";
	puts( utf8str );
	std::cout << "length() = "; puts( utf8str.length() );
	std::cout << "utf8Length() = "; puts( getUtf8Length(utf8str) );

	// copy to raw buffer
	char rawBuf[256];
	std::size_t len = s6.copy(rawBuf, sizeof(rawBuf)-1);
	rawBuf[len] = '\0';	// don't forget

	std::cout << rawBuf << std::endl;

}

void CSTLTestString::cleanup(void) {

}

std::string::size_type CSTLTestString::getUtf8Length(const std::string &str) {
	std::string::size_type len = 0;
	int pos;
	unsigned char lead;
	int char_size = 0;

	for (pos = 0; pos < str.size(); pos += char_size) {

		lead = str[pos];

		if (lead < 0x80) {
			char_size = 1;
		} else if (lead < 0xE0) {
			char_size = 2;
		} else if (lead < 0xF0) {
			char_size = 3;
		} else {
			char_size = 4;
		}

		len += 1;
	}

	return len;
}
