void main(){

	bool a = false;
	bool b = false && false;
	a = b && true;
	b = true && false;
	b = a && true;
	a = a && b; 

}