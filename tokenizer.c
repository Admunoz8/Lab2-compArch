#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
 
/* Return true (non-zero) if c is a whitespace characer
 ('\t' or ' ').
 Zero terminators are not printable (therefore false) */
bool delim_character(char c){
 if(c == ' ' || c == '\0') 
 return true;
 else 
 return false;
}
 
/* Return true (non-zero) if c is a non-whitespace
 character (not tab or space).
 Zero terminators are not printable (therefore false) */
bool non_delim_character(char c){
 if(c == ' ' || c == '\0') 
 return false;
 else 
 return true;
}
 
/* Returns a pointer to the first character of the next
 space-separated word*/
 //making a copy node

char *word_start(char* str){
 char *copy;
 //if node str is tab return the copy of it 
 if(*str == '\0') {
 return copy;
 }
 //while loop that will go  through the white spaces
 while(delim_character(*str)) {
//if statement that will see if its a non white spac it will retturn the node
 if(non_delim_character(*str)) {
 copy = str;
 return copy;
 }
 //increment until whitespace reach
 str++;
 }
 //once while loop satisfied we return thee copy 
 copy = str;
 return copy;
}
 
/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str){
 while(non_delim_character(*str)) {
 str++;
 }
 return str;
}
// counts the number of words or tokens
int count_tokens(char* str){
int num_words;
 int past_char;
 
 num_words = 0;
 past_char = 0;
 
 while(*str != '\0') {
 if(non_delim_character(*str)) {
 if(past_char == 0) {
 num_words += 1;
 past_char = 1;
 }
 past_char = 1;
 } else {
 past_char = 0;
 }
 str++;
 }
 printf("\n");
 return num_words;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
 space-separated tokens from zero-terminated str.
 For example, tokenize("hello world string") would result in:
 tokens[0] = "hello"
 tokens[1] = "world"
 tokens[2] = "string"
 tokens[3] = 0
*/
 //we use the malloc 
char *copy_str(char *inStr, short len){
 char *copy = (char *)malloc(len);
 for(int i=0; i<len ; i++){
 *(copy+i) = *(inStr+i);
 }
 *(copy+len) = '\n';
 return copy;
 
}
 
char** tokenize(char* str){
 char tokens = count_tokens(str)+1;
 char** array = (char **)malloc(sizeof(char *) * (tokens+1));
 int i=0;
 array[i] = strtok(str, " ");
 for(i=1; i < tokens;i++){
 array[i] = strtok(NULL, " ");
 }
 array[i++] = 0;
 return array;
 
 
 //int i;
 //for(i=0; inStr[i] != '\0'; ++i);
 //printf("%d", i);
 
 //copy_str(inStr, 0);
}
 
void print_all_tokens(char** tokens){
 int c = 0;
 while(tokens[c] != NULL){
 printf("Token[%d] = %s \n", c, tokens[c]);
 c++;
 }
 return;
}

//main where thee code runs
int main() {
  char inStr[max];
  printf("Please enter the input string: \n");
  fgets(inStr, max, stdin);

  char** tokens = tokenize(inStr);
  print_all_tokens(tokens);

  return 0;
}
