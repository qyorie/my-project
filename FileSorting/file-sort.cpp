#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::filesystem;

int main(){

   path p = current_path();
   p = p /"jpeg";
   
   cout << p;
   return 0;
}