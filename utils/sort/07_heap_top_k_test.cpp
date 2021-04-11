// #include <random> 
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>

#include "heap.hpp"

// using namespace std; 

int main(int argc, char **argv){
    if(argc < 3){
        std::cout << "Parameter error: HeapTopK -K -I" << std::endl; 
        throw; 
    }
    
    int K = atoi(argv[1]); 
    std::string file_path(argv[2]); 
    std::cout << K << std::endl; 
    std::cout << file_path << std::endl; 

    std::ifstream ifs(file_path); 
    if(ifs.is_open()){
        int temp; 
        std::vector<int> result; 
        while(ifs >> temp){
            std::cout << temp << std::endl; 
            PushTopKHeap(result, 0, result.size(), K, temp); 
            for(int &j : result) std::cout << j << " ";
            std::cout << std::endl; 
            sleep(1); 
        }
        ifs.close(); 
    } else {
        std::cerr << "Fail! " << std::endl; 
    }

    return 0; 
}
