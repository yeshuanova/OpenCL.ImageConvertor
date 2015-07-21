//
//  ConvertState.h
//  OpenCLImageConvertor
//
//  Created by Peter.Li on 2015/7/21.
//  Copyright (c) 2015年 Peter.Li. All rights reserved.
//

#ifndef __OpenCLImageConvertor__ConvertState__
#define __OpenCLImageConvertor__ConvertState__

#include <stdio.h>
#include <string>
#include <vector>

class ConvertState
{
public:
    enum ConvertType {
        NORMAL,
        GRAY_SCALE
    };
    
    ConvertState();
    ConvertState(const std::vector<std::string>& argv_list);
    
    ConvertType getConvertType();
    
    std::string get_source_path();
    std::string get_dest_path();
    
    bool parser_input_list(const std::vector<std::string>& argv_list);
    
private:
    ConvertType type;
    std::string source_path;
    std::string dest_path;
    
};

#endif /* defined(__OpenCLImageConvertor__ConvertState__) */
