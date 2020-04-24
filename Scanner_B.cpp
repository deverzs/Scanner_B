#include<iostream>
#include<fstream>
#include<string>
#include <iterator> 
#include <map>
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

//  Enums
enum tokentype { ERROR, WORD1, WORD2, PERIOD, EOFM, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR };
enum line_type { CONNECTOR_LT , ACTOR, OBJECT_LT, TO, ACTION, DESCRIPTION, TENSE };

// Tables                                                                                                                                                                                               
string tokenName[30] = { "ERROR", "WORD1", "WORD2", "PERIOD", "EOFM", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR" };
string lineName[7] = { "CONNECTOR: " , "ACTOR: " , "OBJECT: ", "TO: ", "ACTION: ", "DESCRIPTION: ", "TENSE: " };

// Reserved Words                                                                                                                                                                                           
string reservedWords[19] = { "masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi", "anata", "kare", "kanojo", "sore", "mata", "soshite", "shikashi", "dakara", "eofm" \
};

//check for reserved word prototype                                                                                                                                                                         
bool reserved(std::string& w, tokentype& tt);

// ------------ Scanner and Driver -----------------------      
ifstream fin;  // global stream for reading from the input file  
ofstream translateFile;

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

tokentype saved_token;			//saved token decided by scanner
string saved_lexeme;			//saved word just read
bool token_available;			//if a token has been determined
string saved_E_word;			//translated word

// Type of error: match_fails
// Done by: Maria 
void syntaxerror1(tokentype e, string w)
{
	cout << "SYNTAX ERROR : Expected " << tokenName[e] << " but found " << w << endl;
	exit(1);
}


// Type of error: switch_default
// Done by: Maria
void syntaxerror2(string w, string f)
{
	cout << "SYNTAX ERROR : Unexpected " << w << " found in " << f << endl;
	exit(1);
}



// Purpose:Looks ahead to see what token comes next from the scanner
// Done by: Zsuzsanna
tokentype next_token()
{
	//if there is no token that has been determined
	if (!token_available)
	{
		//read the next word and save it
		scanner(saved_token, saved_lexeme);

		//tracer for user
		cout << "Scanner called using word: " << saved_lexeme << endl;

		//flag that we have a token
		token_available = true;
	}

	//return the token found
	return saved_token;

}

// Purpose: Checks and eats up the expected token
// Done by: Zsuzsanna
bool match(tokentype expected)
{
	//if the next token is not what sent to match()
	if (next_token() != expected)
	{
		//trace the syntax error
		syntaxerror1(expected, saved_lexeme);

		//exit the scanner/parser
		exit(1);
	}
	else	//otherwise we have a match
	{
		//tracer to user
		cout << "Matched " << tokenName[saved_token] << endl;
		//reset the saved token to find the next token
		token_available = false;
		//return that we have a match successful
		return true;
	}
	//satistfy the compiler
	return true;
}

// ----- RDP functions - one per non-term -------------------

//Proototypes
void story();
void s();
void after_subject();
void after_noun();
void after_object();
void noun();
void verb();
void be();
void tense();
void gen(int line_type);
void getEword();

// Make each non-terminal into a function here
// Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: <story> := <s> { <s> }
// Done by: Zsuzsanna

void story()
{
	//process a story tracer
	cout << "\n\nProcessing <story>\n\n";
	//process an s() 
	s();

	//repeat for {}
	while (true)
	{
		//check which token was found
		switch (next_token())
		{
			//the optional connector found
		case CONNECTOR:
			//fall through to continue
		//case from noun found
		case WORD1:
			//fall through to continue
		//case from noun found
		case PRONOUN:
			//call s() again
			s();
			break;
			//end of file marker found
		case EOFM:
			//it's the end
			return;
			//unexpected word found
		default:
			syntaxerror2(saved_lexeme, "<story>");
		}
	}
}


// Grammar: <s> := [CONNECTOR] <noun> SUBJECT <after subject>
// Done by: Zsuzsanna
void s()
{
	//process an s tracer
	cout << "Processing <s>\n";

	//check which token was found
	switch (next_token())
	{
		//connector found
	case CONNECTOR:
		//check for the match of Connector
		match(CONNECTOR);
		getEword();
		gen(CONNECTOR_LT);
		//call noun() as next RDP function
		noun();
		getEword();
		break;
		//WORD1 found 
	case WORD1:
		//call noun() as next RDP function
		noun();
		getEword();
		break;
		//pronoun found 
	case PRONOUN:
		//call noun() as next RDP function
		noun();
		getEword();
		break;
		//unexpected word found
	default:
		syntaxerror2(saved_lexeme, "<s>");
	}

	match(SUBJECT);
	gen(ACTOR);
	after_subject();
}

// Grammar: <after subject> := <verb> <tense> PERIOD | <noun> <after noun>
// Done by: Zsuzsanna
void after_subject()
{
	//process an after_subject tracer
	cout << "Processing <after subject>\n";

	//check which token was found
	switch (next_token())
	{
		//WORD2 found
	case WORD2:
		//call verb() as next RDP function
		verb();
		getEword();
		gen(ACTION);
		//call tense() as next RDP function
		tense();
		gen(TENSE);
		//check if period is next
		match(PERIOD);
	
		break;
		//WORD1 found
	case WORD1:
		//call noun() as next RDP function
		noun();
		getEword();
		
		//call after_noun() as next RDP function
		after_noun();
		break;
		//Pronoun found
	case PRONOUN:
		//call noun() as next RDP function
		noun();
		getEword();
		
		break;
		//unexpected word found
	default:
		syntaxerror2(saved_lexeme, "<after subject>");
	}
}

// Grammar: <after noun> ::= <be> PERIOD | DESTINATION <verb> <tense> PERIOD | OBJECT <after object>
// Done by: Alaa
void after_noun() // Print processing message for after noun sentence
{
	cout << "Processing <after noun>\n";

	switch (next_token())
	{
	case IS: // Processing if the token matches with IS Case
		be(); // Call be Method to process verb to be and see if the verb IS or WAS
		gen(DESCRIPTION);
		gen(TENSE);
		match(PERIOD); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting one
		break;
	case WAS: // Processing if the token matches with WAS Case
		be();
		gen(DESCRIPTION);
		gen(TENSE);
		match(PERIOD); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting one
		
		break;
	case DESTINATION: // Processing if the token matches with DESTINATION Case
		match(DESTINATION); // Call match and send DESTINATION Type and print Matched message if it's equal to the expecting one
		gen(TO);
		verb(); // Call the Verb Method to process verb
		getEword();
		gen(ACTION);
		tense(); // Call the Tense Method to process tense by check the next token and put it with the right tense Case to process
		gen(TENSE);
		match(PERIOD); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting one
	
		break;
	case OBJECT: // Processing if the token matches with OBJECT Case
		match(OBJECT); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting on
		gen(OBJECT_LT);
		after_object(); // Call the after object Method again in case the next token is OBJECT
		break;
	default:
		syntaxerror2(saved_lexeme, "<after subject>"); //Otherwise (default case) Call the Syntax error 2 Method to print Syntax error message

	}
}


// Grammar: <after object> ::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
// Done by: Alaa
void after_object()
{
	cout << "Processing <after object>\n"; // Print processing message for after object sentence

	switch (next_token())
	{
	case WORD2: // Processing if the token matches with WORD2 Case
		verb(); // Call the Verb Method to process verb
		getEword();
		gen(ACTION);
		tense(); // Call the Tense Method to process tense by check the next token and put it with the right tense Case to process
		gen(TENSE);
		match(PERIOD); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting one
		
		break;
	case WORD1: // Processing if the token matches with WORD1 Case
		noun(); // Call the noun Method and start processing noun
		getEword();
		match(DESTINATION); // Call match and send DESTINATION Type and print Matched message if it's equal to the expecting one
		gen(TO);
		verb(); // Call the Verb Method to process verb
		getEword();
		gen(ACTION);
		tense(); // Call the Tense Method to process tense by check the next token and put it with the right tense Case to process
		gen(TENSE);
		match(PERIOD); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting one
		
		break;
	case PRONOUN: // Processing if the token matches with PRONOUN Case
		noun(); // Call the noun Method and start processing noun
		getEword();
		verb(); // Call the Verb Method to process verb
		getEword();
		gen(ACTION);
		tense(); // Call the Tense Method to process tense by check the next token and put it with the right tense Case to process
		gen(TENSE);
		match(PERIOD); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting one
	
		break;
	case OBJECT: // Processing if the token matches with Object Case
		match(OBJECT); // Call match and send PERIOD Type and print Matched message if it's equal to the expecting one
		after_object(); // Call the after object Method again in case the next token is OBJECT
		break;
	default:
		syntaxerror2(saved_lexeme, "<after object>"); //Otherwise (default case) Call the Syntax error 2 Method to print Syntax error message

	}
}

// Grammar: <noun> ::= WORD1 | PRONOUN
// Done by: Alaa
void noun()
{
	cout << "Processing <noun>\n"; // Print processing message
	switch (next_token())
	{
	case WORD1:
		match(WORD1); // If the word (token) is WORD1, Call match Method and send WORD1 Type
		//gen(ACTOR);
		break;
	case PRONOUN:
		match(PRONOUN); // If the word (token) is PRONOUN, Call match Method and send PRONOUN Type
		//gen(ACTOR);
		break;
	default:
		syntaxerror2(saved_lexeme, "<noun>"); // Otherwise (default case) Call the Syntax error 2 Method to print Syntax error message
	}
}


// Grammar: <verb> ::= WORD2
// Done by: Maria
void verb()
{
	cout << "Processing <verb>\n";
	next_token();
	match(WORD2);

}


// Grammar: <be> ::=   IS | WAS
// Done by: Maria
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
// Done by: Maria
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


//=================================================
// File translator.cpp written by Group Number: 18
//=================================================

// ----- Additions to the parser.cpp ---------------------

// Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
map<string, string> Lexicon;

// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt 
//  Done by: ** 
void readLexicon()
{
	ifstream finLixi;
	string english_w, japanese_w;

	finLixi.open("C:\\Users\\dever\\Desktop\\Spring2020\\TheoryComp\\cs421files\\CS421Progs\\TranslatorFiles\\lexicon.txt");
	//fin2.open("lexicon.txt");
	
	while(finLixi >>japanese_w)
	{
		finLixi >> english_w;
		Lexicon[japanese_w] = english_w;		
	}
	finLixi.close();
}

// ** Additions to parser.cpp here:
//    getEword() - using the current saved_lexeme, look up the English word
//                 in Lexicon if it is there -- save the result   
//                 in saved_E_word
//  Done by: ** 
void getEword()
{
	saved_E_word = Lexicon[saved_lexeme];
	if (saved_E_word == "")
	{
		saved_E_word = saved_lexeme;
	}
}

//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
//  Done by: ** 
void gen(int lt)
{
	if (saved_token == EOFM)
	{
		return;
	}
	if (lt == 6)
	{
		translateFile << lineName[lt] << tokenName[saved_token] << endl << endl;;
	}
	else
	{
		
		translateFile << lineName[lt] << saved_E_word << endl;
		
	}

	
}
// ----- Changes to the parser.cpp content ---------------------

// ** Comment update: Be sure to put the corresponding grammar 
//    rule with semantic routine calls
//    above each non-terminal function 

// ** Each non-terminal function should be calling
//    getEword and/or gen now.




// ---------------- Driver ---------------------------

// The final test driver to start the translator
// Done by:  **

int main()
{
	//create dictionary of translations
	readLexicon();
	//opens the output file translated.txt
	//translateFile.open("translate.txt");
	translateFile.open("C:\\Users\\dever\\Desktop\\Spring2020\\TheoryComp\\cs421files\\CS421Progs\\ParserFiles\\translate.txt");
	
	string filename;
	cout << "Enter the input file name: ";
	//cin >> filename;
	filename = "C:\\Users\\dever\\Desktop\\Spring2020\\TheoryComp\\cs421files\\CS421Progs\\TranslatorFiles\\partCtest1";
	fin.open(filename.c_str());

	token_available = false;

	// calls the <story> to start parsing
	story();

	// closes the input file 
	fin.close();
	cout << "\n\nSuccessfully parsed <story>.\n";


	//closes traslated.txt
	translateFile.close();

}// end
// require no other input files!

