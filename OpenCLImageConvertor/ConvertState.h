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
    enum Mode {
        Error,
        Grayscale
    };
    
    ConvertState();
    ConvertState(const std::vector<std::string>& argv_list);
    
    Mode getConvertMode();
    
    bool is_success();
    std::string get_source_path();
    std::string get_dest_path();
    std::string get_error_msg();
    
    void parse_input_list(const std::vector<std::string>& argv_list) noexcept;
    
private:
    
    void parse_convert_type(const std::string& arg);
    void parse_source_path(const std::string& path);
    void parse_dest_path(const std::string& path);
    
    bool check_file_exist(const std::string& path);
    
    Mode _run_mode = Error;
    std::string _source_path;
    std::string _dest_path;
    std::string _err_msg;    // show parse error msg
};


#endif /* defined(__OpenCLImageConvertor__ConvertState__) */
