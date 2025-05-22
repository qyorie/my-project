#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::filesystem;

void sortFile(const path& p, const string& ext, const string& dirName);
void createDirectory(const path& p, const string dirName);
void transferFile(const path& src, const path& target);
int main(){


   path p = current_path();

   sortFile(p, ".txt", "text");
   
   system("pause");
   return 0;
}

void sortFile(const path& p, const string& ext, const string& dirName){

   //Iterate through the directory
   for (auto const& dir_entry : directory_iterator{p}){

      //cout << dir_entry.path();
      //checks for file extension name
      if (dir_entry.path().extension() == ext){
         createDirectory(p, dirName);
         transferFile(dir_entry.path(), p/dirName/dir_entry.path().filename());
      }
   }
}

void createDirectory(const path& p, const string dirName){
   
   //creates directory
   try{
      create_directory(p/dirName);
   }catch (filesystem_error const& ec){
      cout << ec.what() << endl;
   }
}

void transferFile(const path& src, const path& target){

   //transfers file to "target" directory
   try{
      copy_file(src, target);
      remove(src);

      cout << "File/s transferred to " << target.parent_path() << endl;
   } catch (filesystem_error const& ec){
      cout << ec.what() << endl;
   }
}