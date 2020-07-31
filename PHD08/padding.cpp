#include <bits/stdc++.h>
#define MAX 55
using namespace std;
char s[30];
char matrix[55][55];
int h, w;

FILE *in, *out;

int main() {
	in = fopen("gul.txt", "r");
	out = fopen("gul_pad.txt", "w");
	while(fscanf(in, "%s", s)!=EOF) {
		for(int i=0; i<55; ++i)
			for(int j=0; j<55; ++j)
				matrix[i][j]='0';
		fscanf(in, "%d %d", &h, &w);
		for(int i=(55-h)/2; i<(55-h)/2+h; ++i) {
			for(int j=(55-w)/2; j<(55-w)/2+w; ++j) {
				fscanf(in, " %c", &matrix[i][j]);
			}
		}

		for(int i=0; i<10; ++i) {
			if(s[i]=='_') break;
			fprintf(out, "%c", s[i]);
		}
		fprintf(out, "\n");
		for(int i=0; i<55; ++i) {
			for(int j=0; j<55; ++j)
				fprintf(out, "%c ", matrix[i][j]);
			fprintf(out, "\n");
		}
		fprintf(out, "\n");
	}
	return 0;
}