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


#ifndef TEST1_CSTRINGTOKENIZER_H
#define TEST1_CSTRINGTOKENIZER_H

#include <string>

class CStringTokenizer {
public:
	CStringTokenizer(const std::string& str, const std::string& token);
	virtual ~CStringTokenizer(void);
	bool hasNext(void);
	std::string getNext(void);
	std::string getNextWithTrim(void);

protected:
	std::string mBuffer;
	std::string mToken;
	unsigned long mCurrentPos;
};


#endif //TEST1_CSTRINGTOKENIZER_H
