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
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define __CL_ENABLE_EXCEPTIONS
#include "cl.hpp"


#include "ConvertState.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    try {
        
        vector<string> argv_list;
        for (int idx = 0; idx < argc; ++idx) {
            argv_list.push_back(string(argv[idx]));
        }
        
        ConvertState state(argv_list);
        
        switch (state.getConvertMode()) {
            case ConvertState::Grayscale:
                {
                    cout << "Run grayscale convert" << endl;
                    cout << "\t source path : " << state.get_source_path() << endl;
                    cout << "\t dest path : " << state.get_dest_path() << endl;
                    
                    cout << endl;
                    cv::Mat src_img = cv::imread(state.get_source_path());
                    cout << "Image Row : " << src_img.rows << ", Image Col : " << src_img.cols << endl;
                    
                }
                break;
            
            case ConvertState::Error:
            default:
                cout << "convert error" << endl;
                return 0;
        }
        
    } catch(cv::Exception& e) {
        cout << "OpenCV Exception : " << endl << e.what() << endl;
    } catch (cl::Error& e) {
        cout << "OpenCL Error : " << endl << e.what() << endl;
    } catch (exception& e) {
        cout << endl << "C++ Exception : " << endl << e.what() << endl;
    } catch (...) {
        cout << endl << "Unsupport Exception" << endl;
    }
    
    return 0;
}

