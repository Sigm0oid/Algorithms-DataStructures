#include "bits/stdc++.h"

int n;
int c[555];
int mm[555][111][111];

int calcul(int b1, int b2, int i){
	if (i>=n) return 0;
	if (mm[i][b1][b2]!=-1) return mm[i][b1][b2];
	if ((b1 == c[i])||(b2 == c[i])) {
		int xx = calcul(b1,b2,i+1);
		mm[i][b1][b2] = xx;
		mm[i][b2][b1] = xx;
		return xx;
	}
	int m1 = calcul(c[i],b2,i+1);
	int m2 = calcul(b1,c[i],i+1);
	int xx = ((m1<m2)?m1:m2)+1;
	mm[i][b1][b2] = xx;
	mm[i][b2][b1] = xx;
	return xx;
}

int main() {
	int T=0;
	scanf("%d",&T);
	for(int t=0;t<T;t++) {
		scanf("%d",&n);
		int i=0;
		int j=0;
		while(i<n){
			int x;
			scanf("%d",&x);
			if (c[j-1] != x){
				c[j]=x;
				j++;
			}
			i++;
		}
		n=j;
		memset(mm,-1,sizeof mm);
		printf("%d\n",calcul(0,0,0));
	}
	return 0;
}
