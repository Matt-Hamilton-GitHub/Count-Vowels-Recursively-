

#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

bool is_vowel(char single_vowel); //a boolen functiuon that determines whether a character is a vowel and returns true or false
string substr(string str_input); //substr function that removes all the vowels from the passed string
int num_of_vowels(string word, int num, int index, vector<char>& vec);
void display(vector<char>& vec, string word, int num);



int main() {

  string user_input {""}; //declare a variable that would hold a user's input
  vector<char> vowels;

  //below, the program asks user to input a string. Spaces are possible 
  cout << "Please enter your string: ";
  getline(cin, user_input);
 

 //output the results 
 display (vowels, user_input, num_of_vowels(user_input,0,0, vowels));


system("pause");

return 0;
}



bool is_vowel(char single_vowel){

//here we use cases to chack if a character is a vowel
  switch(tolower(single_vowel)){

    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
	case 'y':
       return true;
       
    default: 
       return false;
       
  }
};

 
int num_of_vowels(string word, int num, int index, vector<char>& vec){
	
	
	
	if(word.length() == 0){
		return 0;
	}else if(index == word.length()){
		return num; 
	}else{
		
		if(isalpha(word[index]) && is_vowel(word[index])){
			vec.push_back(word[index]);
			return num_of_vowels(word,num+1, index+1, vec);
		}else{
			return num_of_vowels(word,num, index+1, vec);
	} 
} 
}



void display(vector<char>& vec, string word, int num){
	
	if(vec.size() == 2){
		cout << word << " contains: " << num << " vowels: " ;
			for(int idx{0}; idx < vec.size() ;idx++){
				cout << " '" << vec[idx] << "' "; 
			}
 cout <<  "\n***************************" << endl;
	}else{
		for(int idx{0}; idx < vec.size();idx++){
			if(tolower(vec[idx]) == 'y'){
				num--;
			}
		}
		
 cout <<  "***************************" << endl;
 cout << word << " contains: " << num << " vowels: " ;
			for(int idx{0}; idx < vec.size() ;idx++){
				if(vec[idx] != 'y')
					cout << " '" << vec[idx] << "' "; 
			}
 cout <<  "\n***************************" << endl;

		
	}
}