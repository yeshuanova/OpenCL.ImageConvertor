//
//  ConvertState.cpp
//  OpenCLImageConvertor
//
//  Created by Peter.Li on 2015/7/21.
//  Copyright (c) 2015年 Peter.Li. All rights reserved.
//

#include "ConvertState.h"
#include <iostream>
#include <fstream>
#include <exception>

class ConvertException : public std::exception {
    
    std::string _err_msg;
    
public:
    ConvertException(const char* ch) {
        _err_msg = std::string(ch);
    }
    
    ConvertException(const std::string& err_msg) {
        _err_msg = err_msg;
    }
    
    ConvertException(const ConvertException& rhs) {
        _err_msg = rhs._err_msg;
    }
    
    ConvertException(const ConvertException&& rhs) {
        _err_msg = std::move(rhs._err_msg);
    }
    
    virtual const char* what() const throw() {
        return _err_msg.c_str();
    }
};

ConvertState::ConvertState() {
    
}

ConvertState::ConvertState(const std::vector<std::string>& argv_list) {
    parse_input_list(argv_list);
}

bool ConvertState::is_success() {
    return ConvertState::Error == _run_mode;
}

ConvertState::Mode ConvertState::getConvertMode() {
    return _run_mode;
}

std::string ConvertState::get_source_path() {
    return _source_path;
}

std::string ConvertState::get_dest_path() {
    return _dest_path;
}

std::string ConvertState::get_error_msg() {
    return _err_msg;
}

void ConvertState::parse_input_list(const std::vector<std::string>& argv_list) noexcept {
    
    try {
        if (argv_list.size() != 4) {
            throw ConvertException("Input parameters error!");
        }

        parse_convert_type(argv_list[1]);
        parse_source_path(argv_list[2]);
        parse_dest_path(argv_list[3]);

    } catch (std::exception& e) {
        _run_mode = Error;
        _err_msg = e.what();
        std::cout << std::endl << _err_msg << std::endl;
    } catch (...) {
        _run_mode = Error;
        _err_msg = "Unsupport exception";
        std::cout << std::endl << _err_msg << std::endl;
    }
    
}


void ConvertState::parse_convert_type(const std::string& arg) {
    
    if (arg.empty()) {
        throw ConvertException("Convert argument is empty!");
    }
    
    if (arg.substr(0, 1) != "-") {
        throw ConvertException("Convert argument format error!");
    }
    
    if (arg == "-g") {
        _run_mode = Grayscale;
    } else {
        throw ConvertException("Convert argument doesn't support!");
    }
}

void ConvertState::parse_source_path(const std::string& path) {
    
    if (!check_file_exist(path)) {
        throw ConvertException("File not exist");
    }
    
    _source_path = path;
    
}

void ConvertState::parse_dest_path(const std::string& path) {
    
    if (check_file_exist(path)) {
        throw ConvertException("File has existed, please change file name!");
    }
    
    _dest_path = path;
}

bool ConvertState::check_file_exist(const std::string& path) {
    
    std::fstream fs;
    fs.open(path);
    
    if (fs.good()) {
        fs.close();
    } else {
        fs.close();
        return false;
    }

    return true;
}




