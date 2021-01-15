//
// Created by montgomery anderson on 14/12/16.
//

#include <string>
#include <ios>
#include <fstream>
#include <iostream>

namespace filelib {

    using std::string;
    using std::iostream;


    string readFile(const char *filePath) {
//        string content;
//        std::ifstream fileStream(filePath, std::ios::in);
//
//        if (!fileStream.is_open()) {
//            std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
//            return "";
//        }
//
//        string line = "";
//        while (!fileStream.eof()) {
//            getline(fileStream, line);
//            content.append(line + "\n");
//        }
//
//        fileStream.close();
//        return content;

//        std::ifstream stream(filePath);
//        std::string content((std::istreambuf_iterator<char>(stream)), (std::istreambuf_iterator<char>(stream)));
//        return content;

        string content = "";
        std::ifstream file(filePath, std::ios::in);

        char fullpath[512];
        realpath(filePath, fullpath);

        if (!file.is_open()) {
            std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
            return content;
        }

        string line;
        while(file.good()) {
            getline(file, line);
            content += line;
        }

        return content;
    }
}