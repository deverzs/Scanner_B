#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* 
INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.
  e.g. You can copy scanner.cpp here by:
		  cp ../ScannerFiles/scanner.cpp .
	   and then append the two files into one:
		  cat scanner.cpp parser.cpp > myparser.cpp
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;



//=====================================================                                                                                                                                                     
// File scanner.cpp written by: Group Number: 18                                                                                                                                                            
//Alaa Ahmed                                                                                                                                                                                                
//Maria Baranova                                                                                                                                                                                            
//Zsuzsanna Dianovics                                                                                                                                                                                       
//=====================================================                                                                                                                                                     

// --------- Two DFAs ---------------------------------                                                                                                                                                     

// WORD DFA                                                                                                                                                                                                 
// Done by: Alaa                                                                                                                                                                                            
// RE:  (vowel | vowel n | consonant vowel | consonant vowel n | consonant-pair vowel | consonant-pair vowel n)^+                                                                                           
// Comments by Maria                                                                                                                                                                                        
bool word(string s) //boolian function that has to check if word is valid or not                                                                                                                            
{
	string state = "q0"; //string that we will be comparing                                                                                                                                                   
	int charpos = 0;
	//replace the following todo the word dfa  DONE                                                                                                                                                           
	while (s[charpos] != '\0') //while loop will work if we have a word                                                                                                                                       
	{
		//in all of those if and else statements we will be checking orders of letters in word and by the 
		//roles we have we will be able to identify if it is a valid word or not                              
		if (state == "q0" && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' ||
			s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'n'))
			state = "qy"; //bmkhprgn                                                                                                                                                                            
		else if (state == "q0" && s[charpos] == 'c')
			state = "qc"; //c                                                                                                                                                                                   
		else if (state == "q0" && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u'
			|| s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
			state = "q0q1"; //vowel                                                                                                                                                                             
		else if (state == "q0" && s[charpos] == 't')
			state = "qt"; //t                                                                                                                                                                                   
		else
			if (state == "q0" && s[charpos] == 's')
				state = "qs"; //s                                                                                                                                                                                 
			else
				if (state == "q0" && (s[charpos] == 'd' || s[charpos] == 'w' ||
					s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
					state = "qsa"; //dwzyj                                                                                                                                                                          

				else if (state == "qy" && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
					s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
					state = "q0q1"; //vowel                                                                                                                                                                         
				else
					if (state == "qy" && s[charpos] == 'y')
						state = "qsa"; //y                                                                                                                                                                            
					else
						if (state == "qc" && s[charpos] == 'h')
							state = "qsa"; //h                                                                                                                                                                          
						else
							if (state == "q0qy" && s[charpos] == 'c')
								state = "qc"; //c                                                                                                                                                                         
							else
								if (state == "q0qy" && s[charpos] == 't')
									state = "qt"; //t                                                                                                                                                                       
								else
									if (state == "q0qy" && s[charpos] == 's')
										state = "qs"; //s                                                                                                                                                                     
									else
										if (state == "q0qy" && (s[charpos] == 'd' || s[charpos] == 'w' ||
											s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
											state = "qsa"; //dwzyj                                                                                                                                                              
										else
											if (state == "q0qy" && (s[charpos] == 'a' || s[charpos] == 'i' ||
												s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' ||
												s[charpos] == 'I' || s[charpos] == 'E'))
												state = "q0q1"; //vowel                                                                                                                                                           
											else
												if (state == "q0qy" && (s[charpos] == 'b' || s[charpos] == 'm' ||
													s[charpos] == 'k' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' ||
													s[charpos] == 'g' || s[charpos] == 'n'))
													state = "qy"; //bmkhprgn                                                                                                                                                        

												else
													if (state == "qt" && s[charpos] == 's')
														state = "qsa"; //s                                                                                                                                                            
													else
														if (state == "qt" && (s[charpos] == 'a' || s[charpos] == 'i' ||
															s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' ||
															s[charpos] == 'I' || s[charpos] == 'E'))
															state = "q0q1"; //vowel                                                                                                                                                     
														else
															if (state == "qs" && (s[charpos] == 'a' || s[charpos] == 'i' ||
																s[charpos] == 'u' || s[charpos] == 'e' ||
																s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
																state = "q0q1"; //vowel                                                                                                                                                   
															else
																if (state == "qs" && s[charpos] == 'h')
																	state = "qsa"; //h                                                                                                                                                      
																else
																	if (state == "qsa" && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
																		s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
																		state = "q0q1"; //vowel                                                                                                                                               


																	else
																		if (state == "q0q1" && (s[charpos] == 'b' || s[charpos] == 'm' ||
																			s[charpos] == 'k' || s[charpos] == 'h' ||
																			s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g'))
																			state = "qy"; //bmkhprg                                                                                                                                             
																		else
																			if (state == "q0q1" && s[charpos] == 'c')
																				state = "qc"; //c                                                                                                                                                 
																			else
																				if (state == "q0q1" && s[charpos] == 'n')
																					state = "q0qy"; //n                                                                                                                                             
																				else
																					if (state == "q0q1" && s[charpos] == 't')
																						state = "qt"; //t                                                                                                                                             
																					else
																						if (state == "q0q1" && s[charpos] == 's')
																							state = "qs"; //s                                                                                                                                           
																						else
																							if (state == "q0q1" && (s[charpos] == 'd' || s[charpos] == 'w' ||
																								s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
																								state = "qsa"; //dwzyj                                                                                                                                    
																							else
																								if (state == "q0q1" && (s[charpos] == 'a' || s[charpos] == 'i' ||
																									s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' ||
																									s[charpos] == 'I' || s[charpos] == 'E'))//                                                                                        
																									state = "q0q1"; //vowel                                                                                                                                 

																								else
																									return(false); //we exit if non of the rules were aplyed                                                                                                
		charpos++; //have more charectors                                                                                                                                                                     
	}//end of while                                                                                                                                                                                         

  // where did I end up????                                                                                                                                                                                 
	if (state == "q0" || state == "q0qy" || state == "q0q1") return(true);  // end in a final state                                                                                                           
	else return(false);

}

// PERIOD DFA                                                                                                                                                                                               
// Done by: Maria       
// RE: (.)                                                                                                                                                                                   
// Comment by: Maria         
//checks if the period is the last char before accept state                                                                                                                                                                               
bool period(string s)
{  // complete this **                                                                                                                                                                                      
	if (s == ".") { return true; }
	else { false; }
}

// ------ Three  Tables -------------------------------------                                                                                                                                               

// TABLES Done by: Alaa                                                                                                                                                                                     

// Tokentype enum                                                                                                                                                                                           
enum tokentype { ERROR, WORD1, WORD2, PERIOD, EOFM, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR };

string enum_value(tokentype tt)
{
	string type;

	switch (tt)
	{
	case 0:
		type = "ERROR";
		break;
	case 1:
		type = "WORD1";
		break;
	case 2:
		type = "WORD2";
		break;
	case 3:
		type = "PERIOD";
		break;
	case 4:
		type = "EOFM";
		break;
	case 5:
		type = "VERB";
		break;
	case 6:
		type = "VERBNEG";
		break;
	case 7:
		type = "VERBPAST";
		break;
	case 8:
		type = "VERBPASTNEG";
		break;
	case 9:
		type = "IS";
		break;
	case 10:
		type = "WAS";
		break;
	case 11:
		type = "OBJECT";
		break;
	case 12:
		type = "SUBJECT";
		break;
	case 13:
		type = "DESTINATION";
		break;
	case 14:
		type = "PRONOUN";
		break;
	case 15:
		type = "CONNECTOR";
		break;
	default:
		type = "ERROR in default";
		break;
	}

	return type;
}

// TokenName                                                                                                                                                                                                
string tokenName[30] = { "ERROR", "WORD1", "WORD2", "PERIOD", "EOFM", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR" };

// Reserved Words                                                                                                                                                                                           
string reservedWords[19] = { "masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "kanojo", "sore", "mata", "soshite", "shikashi", "dakara", "eofm" \
};

//check for reserved word prototype                                                                                                                                                                         
bool reserved(std::string& w, tokentype& tt);

// ------------ Scanner and Driver -----------------------      
ifstream fin;  // global stream for reading from the input file                                                                                                                                             

// Scanner processes only one word each time it is called                                                                                                                                                   
// Gives back the token type and the word itself                                                                                                                                                            
// Done by: Alaa and Zsuzsanna                                                                                                                                                                             
// Comment by Maria and Zsuzsanna                                                                                                                                                                           
//                                                                                                                                                                                                          
/*Algorithm:
  0. reads next word
  1. If it is eofm, return right now
  2. Else if it is a word
  if reserved word, set the tt reference
  if last character of w is a|e|i|o|u|n
  tt = WORD1
  if last character is I|E
  tt = WORD2
  3. Else if it is a period
  4. Else if it is an error
  5. return the token type
*/
int scanner(tokentype& tt, string& w)
{
	// Grab the next word from the file via fin                                                                                                                                                               
	fin >> w;

	// 1. If it is eofm, return right now.                                                                                                                                                                    
	if (w == "eofm")
	{
		tt = EOFM;
	}
	//2. Else if it is a word                                                                                                                                                                                 
	else if (word(w) == true)
	{
		char lastCh = w[w.size() - 1];

		//if reserved word, set the tt                                                                                                                                                                        
		if (reserved(w, tt)) {}

		//WORD1                                                                                                                                                                                               
		//if last character of w is a|e|i|o|u|n                                                                                                                                                               
		else if (lastCh == 'a' || lastCh == 'o' || lastCh == 'n' ||
			lastCh == 'e' || lastCh == 'i' || lastCh == 'u')
		{
			tt = WORD1;
		}
		//WORD2                                                                                                                                                                                               
		//if last character is I|E                                                                                                                                                                            
		else if (lastCh == 'I' || lastCh == 'E')
		{
			tt = WORD2;
		}

	}
	//3. Else if it is a period                                                                                                                                                                               
	else if (period(w) == true)
	{
		tt = PERIOD;
	}
	//4. Else if it is an error                                                                                                                                                                               
	else
	{
		cout << ">>>>>Lexical Error: The string is not in my language\n";
		tt = ERROR;
	}

	//return the token type                                                                                                                                                                                   
	return tt;

}//the end of scanner                                                                                                                                                                                       


                                                                                                                                                                                            

// Reserved checks the word for being reserved                                                                                                                                                              
// Returns true or false and sets the tokenType                                                                                                                                                             
// Done by: Alaa and Maria                                                                                                                                                                              
//Comment by: Maria            
// checks if the w is a reserved word by going through the reservedWord array                                                                                                                                                                             
bool reserved(std::string& w, tokentype& tt)
{
	//check reserved words                                                                                                                                                                                    
	string reservedWord;
	bool foundIt = false; //making boolean statement to be false   

   //set foundIt for reserved word                                                                                                                                                                           
	for (int i = 0; i < 19; i++) //go in to loop and check for other conditions in it until we reach 19 words                                                                                                 
	{
		//we are cheking in those if and else statments wat tipe of word that is                                                                                                                              
		if (w == reservedWords[i])
		{
			reservedWord = reservedWords[i];
			if (reservedWord == "masu") {
				tt = VERB;
				foundIt = true;
			}
			else if (reservedWord == "masen") {
				tt = VERBNEG;
				foundIt = true;
			}
			else if (reservedWord == "mashita") {
				tt = VERBPAST;
				foundIt = true;
			}
			else if (reservedWord == "masendeshita") {
				tt = VERBPASTNEG;
				foundIt = true;
			}
			else if (reservedWord == "desu") {
				tt = IS;
				foundIt = true;
			}
			else if (reservedWord == "deshita") {
				tt = WAS;
				foundIt = true;
			}
			else if (reservedWord == "o") {
				tt = OBJECT;
				foundIt = true;
			}
			else if (reservedWord == "wa") {
				tt = SUBJECT;
				foundIt = true;
			}
			else if (reservedWord == "ni") {
				tt = DESTINATION;
				foundIt = true;
			}
			else if (reservedWord == "watashi" || reservedWord == "anata" || reservedWord == "kare" || reservedWord == "kanojo" || reservedWord == "sore") {
				tt = PRONOUN;
				foundIt = true;
			}
			else if (reservedWord == "mata" || reservedWord == "soshite" || reservedWord == "shikashi" || reservedWord == "dakara") {
				tt = CONNECTOR;
				foundIt = true;
			}
		}
	}// end set foundIt                                                                                                                                                                                     

	return foundIt;
}



//=================================================
// File parser.cpp written by Group Number: 18
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

//  Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

tokentype saved_token;
string saved_lexeme;
bool token_available;

// Type of error: match_fails
// Done by: Maria 
void syntaxerror1(tokentype e, string w) 
{ 
	cout << "SYNTAX ERROR : Expected " << enum_value(e) << " but found " << w << endl;
	exit(1);
}


// Type of error: switch_default
// Done by: Maria
void syntaxerror2(string w, string f)
{
	cout << "SYNTAX ERROR : Unexpected " << w << " found in " << f << endl;
	exit(1);
}


// Need the updated match and next_token with 2 global vars

// Purpose:Looks ahead to see what token comes next from the scanner
// Done by: Zsuzsanna
tokentype next_token() 
{
	if (!token_available)
	{
		scanner(saved_token, saved_lexeme);
		cout << "Scanner called using word: " << saved_lexeme << endl;
		token_available = true;
	}
	return saved_token;

}

// Purpose: Checks and eats up the expected token
// Done by: Zsuzsanna
bool match(tokentype expected) 
{
	if (next_token() != expected)
	{
		syntaxerror1(expected, saved_lexeme);
		exit(1);
	}
	else
	{
		cout << "Matched " << enum_value(saved_token) << endl;
		token_available = false;
		return true;
	}
	return true;
}

// ----- RDP functions - one per non-term -------------------
void story();
void s();
void after_subject();
void after_noun();
void after_object();
void noun();
void verb();
void be();
void tense();

// Make each non-terminal into a function here
// Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: <story> := <s> { <s> }
// Done by: Zsuzsanna

void story()
{
	//process an s
	cout << "\n\nProcessing <story>\n\n";
	s();

	//repeat for {}
	while (true)
	{
		switch (next_token())
		{
			case CONNECTOR: //optional
			case WORD1:     //from noun
			case PRONOUN:   //from noun
				s();
				break;
			default:
				syntaxerror2(saved_lexeme, "<story>");
		}
	}
}

// Grammar: <s> := [CONNECTOR] <noun> SUBJECT <after subject>
// Done by: **
void s()
{
	//process an s
	cout << "Processing <s>\n";

	switch (next_token())
	{
		case CONNECTOR: //15
			match(CONNECTOR);
			noun();
			break;
		case WORD1:
			noun();
			break;
		case PRONOUN:  //14
			noun();
			break;
		default:
			syntaxerror2(saved_lexeme, "<s>");
	}

	match(SUBJECT);
	after_subject();
}

// Grammar: <after subject> := <verb> <tense> PERIOD | <noun> <after noun>
// Done by: **
void after_subject()
{
	cout << "Processing <after subject>\n";
	switch (next_token())
	{
		case WORD2:
			verb();
			tense();
			match(PERIOD);
			break;
		case WORD1:
			noun();
			after_noun();
			break;
		case PRONOUN:
			noun();
			break;
		default:
			syntaxerror2(saved_lexeme, "<after subject>");
	}
}


// Grammar: <after noun> ::= <be> PERIOD | DESTINATION <verb> <tense> PERIOD | OBJECT <after object> 
// Done by: **
void after_noun()
{
	cout << "Processing <after noun>\n";

	switch (next_token())
	{
		case IS:
			be();
			match(PERIOD);
			break;
		case WAS:
			be();
			match(PERIOD);
			break;
		case DESTINATION:
			match(DESTINATION);
			verb();
			tense();
			match(PERIOD);
			break;
		case OBJECT:
			match(OBJECT);
			after_object();
			break;
		default:
			syntaxerror2(saved_lexeme, "<after subject>");

	}
}


// Grammar: <after object> ::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
// Done by: **
void after_object()
{
	cout << "Processing <after object>\n";

	switch (next_token())
	{
	case WORD2:
		verb();
		tense();
		match(PERIOD);
		break;
	case WORD1:
		noun();
		match(DESTINATION);
		verb();
		tense();
		match(PERIOD);
		break;
	case PRONOUN:
		noun();;
		verb();
		tense();
		match(PERIOD);
		break;
	case OBJECT:
		match(OBJECT);
		after_object();
		break;
	default:
		syntaxerror2(saved_lexeme, "<after object>");

	}
}


// Grammar: <noun> ::= WORD1 | PRONOUN 
// Done by: **
void noun()
{
	cout << "Processing <noun>\n";
	switch (next_token())
	{
		case WORD1:
			match(WORD1);
			break;
		case PRONOUN:
			match(PRONOUN);
			break;
		default:
			syntaxerror2(saved_lexeme, "<noun>");
	}
}


// Grammar: <verb> ::= WORD2
// Done by: **
void verb()
{
	cout << "Processing <verb>\n";
	next_token();
	match(WORD2);
	
}


// Grammar: <be> ::=   IS | WAS
// Done by: **
void be()
{
	cout << "Processing <be>\n";
	switch (next_token())
	{
		case IS:
			match(IS);
			break;
		case WAS:
			match(WAS);
			break;
		default:
			syntaxerror2(saved_lexeme, "<be>");
	}

}


// Grammar:  <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
// Done by: **
void tense()
{
	cout << "Processing <tense>\n";

	
	switch (next_token())
	{
		case VERBPAST:
			match(VERBPAST);
			break;
		case VERBPASTNEG:
			match(VERBPASTNEG);
			break;
		case VERB:
			match(VERB);
			break;
		case VERBNEG:
			match(VERBNEG);
			break;

		default:
			syntaxerror2(saved_lexeme, "<tense>");
	}
	
}

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  Alaa
int main()
{
	string filename;
	cout << "Enter the input file name: ";
	cin >> filename;
	fin.open(filename.c_str());

	token_available = false;

	// calls the <story> to start parsing
	story();

	// closes the input file 
	fin.close();
	cout << "\n\nSuccessfully parsed <story>.\n";

}// end
// require no other input files!

