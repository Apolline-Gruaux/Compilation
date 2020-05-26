int i;
int ii = 1;
int iii = 0xC;

bool b ;
bool bb = true;
bool bbb = false;

void main(){
	int iv;
	int v = 1;
	int vi = 0x5;
	i =0;
	iv = 3;

	bool bbbb;
	bool bbbbb = true;
	b = true;

	if (true) {
		print(i);
	}
	else if (false) {
		print(ii);
	}
	if (b) {
		print(b);
	}
	else if (bb) {
		print(bbb);
	}
	else {
		print("else");
	}

	while (i < 100) {
		v = v+i;
		v = v-2;
		v = v*1;
		v = v/1;
		v = v%2;

		vi = v|i;
		vi = v&i;
		vi = v^i;
		vi = ~v;

		iv > 2;
		iv >= 1;
		iv < 4;
		iv <= 1;
		iv << 5;
		iv >> 1;
		iv = i >>> 2;
	}

	do {

		b = bb;
		b = bb || false;
		b = bb && false;
		bbb!= b;
		
		
	} while (bbbbb);


	for (i = 0 ; i< iv ; i= i+1) {
		print(iii);
	}



}