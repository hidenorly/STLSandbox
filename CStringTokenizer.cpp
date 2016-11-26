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


#include "CStringTokenizer.h"

CStringTokenizer::CStringTokenizer(const std::string &str, const std::string &token):mBuffer(str), mToken(token), mCurrentPos(0)
{

}

CStringTokenizer::~CStringTokenizer(void)
{

}

bool CStringTokenizer::hasNext(void)
{
	return (mCurrentPos < mBuffer.size()) ? true : false;
}

std::string CStringTokenizer::getNext(void)
{
	unsigned long currentPos = mCurrentPos;
	unsigned long nextPos = mBuffer.find(mToken, currentPos);

	mCurrentPos = (nextPos!= std::string::npos) ? nextPos+1 : mBuffer.size()+1;
	return mBuffer.substr(currentPos, mCurrentPos-currentPos-1);
}

std::string CStringTokenizer::getNextWithTrim(void)
{
	std::string result = getNext();
	const static std::string trimCharacterList = " \t\v\r\n";

	unsigned long pos1 = result.find_first_not_of(trimCharacterList);
	if( pos1!=std::string::npos ){
		unsigned long pos2 = result.find_last_not_of(trimCharacterList);
		result = result.substr( pos1, pos2-pos1+1 );
	}

	return result;
}
