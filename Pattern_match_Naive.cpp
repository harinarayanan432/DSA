#include<iostream>
using namespace std;
class string_matching {
	public:
		void Naive_string_matching(string T,string P,int &count) {
			
			int n,m;
			string s1;
			n=T.length();
			m=P.length();
			int flag;
			for(int s=0; s<=(n-m) ; s++) {
				flag=0;
				for(int j=0; j<m; j++) {
					count++;

					if(P[j]!=T[s+j]) {
						flag=1;
						break;
					}
				}
				if(flag==0)
					cout<<"Pattern occurs with valid shift "<<s<<"\n";
			}
		}

};
int main() {
	string_matching obj;
	int count;

cout<<"Naive_string_matching.........\n";
	string T1="ABABCABABACABABCCABABCABAB";
	string T2="ABABABCABABCABABCCABABABCABABABB";
	string T3="AABABCABCABABCABACABABCABABCABAC";
	string P1="ABABCABAB";
	count=0;

	obj.Naive_string_matching(T1,P1,count);
	cout<<"For T1 pattern P1 no.of comparison for naive : "<<count<<"\n\n";
	count=0;
	obj.Naive_string_matching(T2,P1,count);
	cout<<"For T2 pattern P1 no.of comparison for naive : "<<count<<"\n\n";
	count=0;
	obj.Naive_string_matching(T3,P1,count);
	cout<<"For T3 pattern P1 no.of comparison for naive : "<<count<<"\n\n";
	count=0;

	string T4="GTGTXCGGGTXCGTXCGGGTXCGTXCGTCG";
	string T5="GTXCGGGTXCGTXCGGGGTXCGGGTXCGTXC";
	string T6="GGGTXCGGGTXCGTXCGGGTXCGGTXCGGGTXCGTXC";
	string P2="GTXCGGGTXCGTXC";

	obj.Naive_string_matching(T4,P2,count);
	cout<<"For Text T4 pattern P2 no.of comparison for naive  : "<<count<<"\n\n";
	count=0;
	obj.Naive_string_matching(T5,P2,count);
	cout<<"For Text T5 pattern P2 no.of comparison for naive : "<<count<<"\n\n";
	count=0;
	obj.Naive_string_matching(T6,P2,count);
	cout<<"For Text T6 Pattern p2 no.of comparison for naive : "<<count<<"\n\n";

	string T="ABAABAABAABAABAA";
	string P="AA";
	count=0;
	obj.Naive_string_matching(T,P,count);
	cout<<"For Text T Pattern p no.of comparison for naive : "<<count<<endl;

}
