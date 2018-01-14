#pragma once

#include<dsl/PrettyFunctionName.h>
#include<dsl/ValueToString.h>

namespace dsl{
  template<typename...ARGS,typename = std::enable_if<sizeof...(ARGS)!=0>>
    void printError(
        std::string const&    fceName,
        ARGS        const&... args   ){
      std::stringstream ss;
      ss << fceName << "(";
      std::vector<std::string>argStrings = {value2str(args)...};
      bool first=true;
      for(auto const&x:argStrings){
        if(first)first=false;
        else ss << ", ";
        ss << x;
      }
      ss << ")";
      return ss.str();
    }
}
