


//Write a recursive function, vowels, that returns the number of vowels in a word. A word is a string of arbitrary 
//length of letter of the alphabet. The function, isalpha, returns true if its character parameter is a letter of 
//the alphabet and false if its character parameter is not a letter of the alpha.
//
//Two kinds of vowels exist. A,E,I,O,U,a,e,i,o,u are normal vowels. 
//Y and y are abnormal vowels. If a word contains normal vowels, then abnormal vowels are not vowels. 
//If a word contains no normal vowels, then abnormal vowels are vowels.



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
	
	
	//first condition if the length of input string equals 0 then we return 0 - the string has no vowels
	if(word.length() == 0){
		return 0;
	//since index increases with each call of this function, the function returns THE number of vowels - num as index equals to the length of the string
	}else if(index == word.length()){
		return num; 
	}else{
		//hence if a character is an alphabetic letter and it is a vowel, the program doe the following
		//stores the vowel to the vector - to keep the track of them
		//recursively call the function again increasing the index and number of vowels found 
		if(isalpha(word[index]) && is_vowel(word[index])){
			vec.push_back(tolower(word[index]));
			return num_of_vowels(word,num+1, index+1, vec);
			//hence if the character is not an alphabetic letter, 
			//then the function recursively calls itself only increasing the index, number of vowels stays the same
		}else{
			return num_of_vowels(word,num, index+1, vec);
	} 
} 
}





void display(vector<char>& vec, string word, int num){
	
	//since the assignment tells us that: If a word contains normal vowels, then abnormal vowels are not vowels. 
	//If a word contains no normal vowels, then abnormal vowels are vowels.
	
	//hence if there are more than two vowels and at least one of them is y - then we do not display y.
	//in reality, the rules for y being a consonate is much more complicated, so I will stick with the one given in the assignment
	
	
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