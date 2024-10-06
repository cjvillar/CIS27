main() {
Receive Input 
control menu / drive operation of the program
}

My_String{
char array[size]--> Array can static [data holder]
My_String(){Use the constructor to “index input values into the array”
length(){
full traversal → Loop
start → index [0]
stop → count/stop at the index that contains the final char in the string
if(char[i] == null)
null value
}
isalpha(){ full traversal → Loop}
Uppercase                                                    Lowercase
if(char[i] >= 65 && char[i]  <= 90)    ||   (char[i] >= 97 && char[i] <=122)

}


toupper() full traversal → Loop
if  (char[i] >= 97 && char[i] <=122)
		subtract 32 → Upper
		char[i] -= 32;


tolower() full traversal → Loop
if(char[i] >= 65 && char[i]  <= 90)  
	add 32 → Lower
	char[i] += 32;


push_back() full traversal → Loop?
push value to tend of the string in the first available null pointer
}




