#include <bits/stdc++.h>
#define PI 3.14159265358979
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
double IP[10][4];
vector<pii> three, four, five, six, seven, eight;
int h, w;
char s[100];
char matrix[100][100];
FILE *in, *out;

double angle(vector<pii> v) {
	ll u=0, x=0, y=0, xy=0, xx=0, yy=0;
	for(int i=0; i<v.size(); ++i) {
		u++;
		x+=v[i].first;
		y+=v[i].second;
		xy+=v[i].first*v[i].second;
		xx+=v[i].first*v[i].first;
		yy+=v[i].second*v[i].second;
	}
	double t, twotheta, S1, S2, C1, C2;
	if(yy*u+x*x==y*y+xx*u) twotheta=PI/2;
	else {
		t=(double)2*(x*y-xy*u)/(yy*u-xx*u-y*y+x*x);
		twotheta = atan(t);
		if(twotheta<0) twotheta+=PI;
	}
	double t1=twotheta/2;
	double t2=t1+PI/2;
	double s1=sin(t1), s2=sin(t2), c1=cos(t1), c2=cos(t2);
	C1=(double)(-s1*x+c1*y)/u;
	C2=(double)(-s2*x+c2*y)/u;
	S1=(double)xx*s1*s1-2*xy*s1*c1+yy*c1*c1+2*C1*x*s1-2*C1*y*c1+C1*C1*u;
	S2=(double)xx*s2*s2-2*xy*s2*c2+yy*c2*c2+2*C2*x*s2-2*C2*y*c2+C2*C2*u;
	if(S1>S2) return t2;
	else return t1;
}

void process() {
	for(int i=0; i<3; ++i) {
		if(s[i]=='_') break;
		fprintf(out, "%c", s[i]);
	}
	fprintf(out, "\n");
	for(int i=0; i<h; ++i) {
		for(int j=0; j<w; ++j) {
			switch(matrix[i][j]) {
				case '3':
					three.emplace_back(i, j);
					break;
				case '4':
					four.emplace_back(i, j);
					break;
				case '5':
					five.emplace_back(i, j);
					break;
				case '6':
					six.emplace_back(i, j);
					break;
				case '7':
					seven.emplace_back(i, j);
					break;
				case '8':
					eight.emplace_back(i, j);
					break;
			}
		}
	}
	cout<<angle(three)<<' '<<angle(four)<<' '<<angle(five)<<' '<<angle(six)<<' '<<angle(seven)<<' '<<angle(eight)<<'\n';
	fprintf(out, "%.10f %.10f %.10f\n", cos(angle(three)-angle(four)), cos(angle(five)-angle(six)), cos(angle(seven)-angle(eight)));
}

int main() {
	in = fopen("han_rep.txt", "r");
	out = fopen("han_cos.txt", "w");
	for(int i=0; i<9; ++i) {
		fscanf(in, "%s", s);
		fscanf(in, "%d %d", &h, &w);
		for(int i=0; i<h; ++i) {
			fscanf(in, "%s", matrix[i]);
		}
		process();
		three.clear();
		four.clear();
		five.clear();
		six.clear();
		seven.clear();
		eight.clear();
	}
}