void main() {
	bool f = false || true;
	bool t = true;
	f = t || f;
	t = f || true;
	f = true || f;
}