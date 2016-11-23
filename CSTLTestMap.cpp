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

#include <string>
#include <map>
#include "CSTLTestMap.h"

void CSTLTestMap::setup(void)
{

}

void CSTLTestMap::test(void)
{
	std::map<std::string, std::string> m;

	m["key1"] = "hoge";
	m["key2"] = "hoge2";
	m.insert( std::map<std::string, std::string>::value_type( "key3", "hoge3" ) );

	// has_key?()
	if( m.find("key1")!=m.end() ){
		puts("\"key1\" is included. The value is "+m["key1"]);
	}

	// enumerate
	for(auto& anItem : m){
		puts(anItem.first + ":" + anItem.second);
	}

	// size
	puts("The number of stored data is " + std::to_string(m.size()) );

	// erase
/*
	for( std::map<std::string, std::string>::iterator it=m.begin(); it!=m.end(); it++){
		if( it->first == "key1" ){
			m.erase(it);
			break;
		}
	}
*/
	m.erase( m.find("key1") );
	puts("key1's data is erased.");
	for(auto& anItem : m){
		puts(anItem.first + ":" + anItem.second);
	}

	// clear all
	m.clear();
	puts("all data is cleared.");
	for(auto& anItem : m){
		puts(anItem.first + ":" + anItem.second);
	}

	// empty check
	puts( m.empty() ? "no data found" : "data is remained." );
}

void CSTLTestMap::cleanup(void)
{

}
