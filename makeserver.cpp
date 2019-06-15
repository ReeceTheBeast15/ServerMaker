#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <cstdlib>
#include <shlobj.h>
#include <sstream>
#include <tchar.h>
#include <cstring>

#ifdef UNICODE
	typedef std::string String;
#else 
	typedef std::wstring String;
#endif	

std::string addStr(std::string strings[15]){
std::string finalAr="";
for(int I=0;I<15;I++){
std::string SelStr;
SelStr=strings[I];
finalAr=finalAr+SelStr;

}
return finalAr;
}




int main(int argc, char const *argv[]){
system("cmd.exe /c dir c://");
std::string yorn;	
std::cout<<"A project by Reece McDorman(GitHub)"<<std::endl<<std::endl<<std::endl<<"Please do not use any white spaces for server criteria"<<std::endl<<std::endl<<"You are welcomed to contribute and debug this open-source utility."<<std::endl<<std::endl<<"Apologies for current performance issues. Have fun! "<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
std::string icon;
std::string port="3000";
std::string project_name;
std::cout << "project name:";
std::cin>>project_name;
std::string y="y";
std::string n="n";
char description [200];
std::string author;
std::cout<<"Author:";
std::cin>>author;
std::cout<<"Description:";
std::cin.ignore(256,'\n');
std::cin.getline(description,256);

TCHAR Desktop[MAX_PATH];
if(SUCCEEDED(SHGetFolderPath(
NULL,CSIDL_DESKTOPDIRECTORY|CSIDL_FLAG_CREATE,
NULL,SHGFP_TYPE_CURRENT,Desktop))){}


std::string desktop=Desktop;

std::string target_folder=desktop+"\\JS_server_maker\\JSservers";
std::string input_folder=desktop+"\\JS_server_maker\\skeleton";
std::string JSfolders [] = {"\\package.json","\\server.js","\\node_modules","\\index.html","\\lib","\\package-lock.json","\\Start.exe","\\Site.html"};
int lineNums [] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
std::string project=desktop+("\\\\JS_server_maker\\\\JSservers\\\\"+project_name).c_str();
std::string destination=desktop+("\\\\JS_server_maker\\\\JSservers\\\\"+project_name).c_str();

std::cout<<"Port:";

std::cin>>port;
std::cout <<"Destination folder(JSservers):";
std::string entry;




if(std::cin.get()!='\n'){
entry=std::cin.get();
destination=entry+"\\"+project_name;	
}






std::cin.ignore(256,'\n');
std::cout <<'\n'<< "Is this okay?(Y/N)";
std::string key;
std::cin>>key;
std::string Key;


while(key!="n"&key!="N"&key!="y"&key!="Y"&key!="\n"){
std::cin.clear();
std::cin.ignore(1000,'\n');
std::cout<<"Invalid response(reenter):";
std::cin>>key;
}
if((key=="y")||(key=="\n"||key=="Y")){




mkdir(destination.c_str());

std::cout <<" root directory: "<<project.c_str()<<std::endl;

for(int i=0;i<8;i++){

std::string path=destination+JSfolders[i];	
std::string command="robocopy /MIR "+input_folder+JSfolders[i]+" "+path;
std::string filetype=path.substr(path.find_last_of(".")+1);
std::cout << "filetype: " + filetype<< '\n';


if((filetype=="txt")||(filetype=="json")||(filetype=="js")||(filetype=="html")){

std::ifstream source{input_folder+JSfolders[i]};
std::ofstream file{path.c_str()};


std::cout << "Path for "+JSfolders[i]+" file: "+ path.c_str() <<std::endl<<std::endl;	
std::string line;

while(getline(source,line)){
lineNums[i]+=1;
if(lineNums[i]==9&JSfolders[i]=="\\server.js"){
line="server.listen(process.env.PORT || "+port+");";	
}
if(lineNums[i]==7&JSfolders[i]=="\\Site.html"){
line="window.location='http://localhost:"+port+"'";
}
if(lineNums[i]==2&JSfolders[i]=="\\package.json"){
std::string N01="   \"name\":";
std::string N02="\"";
std::string N1=	N01+N02;
std::string NAME=N1+project_name+"\""+",";		
line=NAME;

}
if(lineNums[i]==5&JSfolders[i]=="\\package.json"){
std::string A="   \"main\":\"";
std::string B="\\\\server.js\",";
line=A+destination+B;	
}
if(lineNums[i]==9&JSfolders[i]=="\\package.json"){
std::string C="   \"author\":\"";
std::string D="\",";
line=C+author+D;	

}

if(lineNums[i]==4&JSfolders[i]=="\\package.json"){
std::string E="   \"description\":\"";
std::string F="\",";
line=E+description+F;

}


if(lineNums[i]==6&JSfolders[i]=="\\index.html"){
line="<title>"+project_name+"</title>";


}







file << line << '\n';

}

file.close();

}
else if(filetype=="exe"){
	
std::string Src=input_folder+JSfolders[i];
system(("copy "+Src+" "+destination+"\\").c_str());
}
else{

mkdir(path.c_str());
system(command.c_str());
}
}


std::cout<<"Project created.Launch server on port "+port+"?(Y/N)";

std::cin>>key;

while(key!="n"&key!="N"&key!="y"&key!="Y"&key!="\n"){
std::cin.clear();
std::cin.ignore(1000,'\n');
std::cout<<"Invalid response(reenter):";
std::cin>>key;
}


std::ofstream medium;
medium.open(desktop+"\\\\JS_server_maker\\\\medium.txt",std::ofstream::out | std::ofstream::trunc);
medium<<destination<<std::endl;
medium.close();
if(key=="y"||(key=="\n"||key=="Y")){
system(("start "+destination+"\\Start.exe").c_str());
}
else{
std::cout<<"You can launch the server manually at "+destination+"."<<std::endl<<std::endl;	
std::cout<<"To do this, simply run Start.exe"<<std::endl<<std::endl;
std::cout<<"    Or, you can omit this step and:"<<std::endl<<std::endl<<"     1.Open git hub, navigate to "+destination+"(cd "+destination+")"<<std::endl<<std::endl<<"     2.Run the command 'node server'"<<std::endl<<std::endl<<"     3.Open a web browser, and search 'localhost:3000' in url bar"<<std::endl<<std::endl<<std::endl<<::std::endl<<"Thank you for using makeserver.exe!"<<std::endl;
}




}





else{
std::cout<<"aborted"<<std::endl;

}





};




