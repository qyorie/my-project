#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::filesystem;

void sortFile(const path& p, const string& ext, const string& dirName);
void createDirectory(const path& p, const string dirName);
int main(){

   path p = current_path();
   
   sortFile(p, ".txt", "text");
   
   return 0;
}

void sortFile(const path& p, const string& ext, const string& dirName){

   //Iterate through the directory
   for (auto const& dir_entry : directory_iterator{p}){
      if (dir_entry.path().extension() == ext){
         createDirectory(p, "text");

         try{
            copy_file(dir_entry.path(), p/"text"/dir_entry.path().filename());
         } catch (filesystem_error const& ec){
            cout << ec.what() << endl;
         }
      }
   }
}

void createDirectory(const path& p, const string dirName){
   
   
   try{
      create_directory(p/dirName);
   }catch (filesystem_error const& ec){
      ec.what();
   }
}

void copyFile(const path& p, const string fileName){
   cout <<"copyfile";
}