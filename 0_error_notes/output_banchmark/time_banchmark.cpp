#include <iostream>
#include <chrono>
#include <cstdio>
int main() {

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    //------------------------cout + \n-------------------------------------
    //----------------------------------------------------------------------
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 50000000; i++)  std::cout << "1\n";
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration1 = end - start;
    std::cout<<std::endl;



    //---------------------------printf -----------------------------------
    //---------------------------------------------------------------------
    
    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 50000000; i++)   printf("1\n");
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end - start;

    std::cout<<std::endl;
    //----------------------------endl---------------------------------
    //-----------------------------------------------------------------


    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 50000000; i++)  std::cout << "1"<<std::endl;
    
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration3 = end - start;
    std::cout<<std::endl;
    
    
    //-----------------------print---------------------------------
    //-------------------------------------------------------------


    std::cout << "cout + \\n   : " << duration1.count() << "초\n";
    std::cout << "printf      : " << duration2.count() << "초\n";
    std::cout << "endl        : " << duration3.count() << "초\n";
    


    return 0;
}
