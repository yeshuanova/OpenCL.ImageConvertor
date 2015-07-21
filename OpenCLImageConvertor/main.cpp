//
//  main.cpp
//  OpenCLImageConvertor
//
//  Created by Peter.Li on 2015/7/20.
//  Copyright (c) 2015年 Peter.Li. All rights reserved.
//

// Options:
//
// -g convert image to grayscale
//
//
// SYNOPSIS:
// ./<Product_Name> <Input_File_Path> <params> <Output_Path>
//
//
//

#include <iostream>
#include <string>
#include <vector>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define __CL_ENABLE_EXCEPTIONS
#include "cl.hpp"

using namespace std;




int main(int argc, const char * argv[]) {
    
    // Get Argv list
    vector<string> argv_list;
    for (int idx = 0; idx < argc; ++idx) {
        argv_list.push_back(string(argv[idx]));
    }
    
    try {
        
        
        string input_path;
        string output_path;
        string param;
        

        
        cout << endl << "Argv string list : " << endl << endl;
        for (auto& ele : argv_list) {
            cout << ele << endl;
        }
        cout << endl;
        
    } catch (cl::Error& e) {
        cout << "OpenCL Error : " << e.what() << endl;
    } catch (exception& e) {
        cout << endl << "C++ Exception : " << e.what() << endl;
    }
    
    return 0;
}
