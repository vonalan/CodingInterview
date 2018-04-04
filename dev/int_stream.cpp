#include <random> 
#include <iostream>
#include <fstream> 

// using namespace std; 

int main(int argc, char **argv){
    if(argc < 3){
        std::cout << "Parameter error: IntStream -N -O" << std::endl; 
        throw; 
    }
    
    int N = atoi(argv[1]); 
    std::string file_path(argv[2]); 
    std::cout << N << std::endl; 
    std::cout << file_path << std::endl; 

    std::ofstream ofs(file_path, std::ios::out); 
    if(ofs.is_open()){
        std::random_device rd; 
        std::uniform_int_distribution<int> dist(0, 0x7FFFFFFF); 
        for(int i = 0; i < N; ++i){
            // std::cout << dist(rd) << std::endl; 
            // std::cout << dist(rd) << " "; 
            ofs << dist(rd) << " "; 
        }
        // std::cout << std::endl; 
        ofs.close(); 
    } else {
        std::cerr << "Fail! " << std::endl; 
    }

    return 0; 
}
