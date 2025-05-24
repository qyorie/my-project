#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

void sortFile(const path& p, const string& ext, const string& dirName);
void createDirectory(const path& p, const string dirName);
void transferFile(const path& src, const path& target);
bool confirmation();

int main(){

   path p = current_path();

   string ext[5] = {".txt", ".jpeg", ".jpg", ".png", ".pdf"};
   string dirName[5] = {"text", "jpeg", "jpeg", "png", "pdf"};
   int size = sizeof(dirName) / sizeof(dirName[0]);

   if (confirmation()){
      for (int i = 0; i < size; i++){
         cout << "SORTING " << dirName[i] << endl;
         sortFile(p, ext[i], dirName[i]);
      }
   }
   
   system("pause");
   return 0;
}

bool confirmation(){
   

   while(true){
      char c;
      cout << "Are you sure you want to sort your files? [Y/N]: ";
      cin >> c;
      cin.ignore();
      if (c == 'y' || c == 'Y'){
         return true;
      }else if (c == 'n' || c == 'N'){
         return false;
      }else{
         cout << "Invalid input!\n";
      }

   }
   
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
      string fileName = src.filename().string();
      copy_file(src, target);
      remove(src);
      cout << fileName + " transferred to >> " << target.parent_path().string() << endl;
   } catch (filesystem_error const& ec){
      cout << ec.what() << endl;
   }
}