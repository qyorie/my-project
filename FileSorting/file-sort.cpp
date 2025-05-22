#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::filesystem;

void sortFile(const path &p, const string ext);
void createDirectory(const path& p);
int main(){

   path p = current_path();
   
   sortFile(p, ".txt");
   
   return 0;
}

void sortFile(const path& p, const string ext){
   for (auto const& dir_entry : directory_iterator{p}){
      if (dir_entry.path().extension() == ext){
         createDirectory(p);
         copy_file(dir_entry.path(), p/"text/filetext.txt");
      }
   }
}

void createDirectory(const path& p){

}