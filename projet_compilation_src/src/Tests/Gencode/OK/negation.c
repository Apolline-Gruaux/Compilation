void main() {
	bool f = true != true;
	bool t = true;
	f = f != t;
	t = t != true;
	f = true != f;
}