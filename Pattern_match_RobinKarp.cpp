#include<iostream>
#include<math.h>
using namespace std;
class string_matching {
	public:
		int PreProcess(string P,int d,int q)
		{
		  int m=P.length();
		  int count=0;	
		  int p=0;
		  for(int i=0;i<m;i++)
		{
			count++;
			int asc=(int(P[i]))%d;
			p=((d*p)+ asc) % q;
		}
		cout<<"PreProcessing count="<<count<<endl;
		return p;
	}
	void RABIN_KARP_MATCHER(string T,string P,int d,int q,int &count)
	{
		int n,m,h,p,asc1,asc2,temp;
		int found=0;
		string s1;
		n=T.length();
		m=P.length();
		int t[n];
		 h=1;
		 //pow(d,m-1)=>not in integer range
		 //hence do power calculation by iteration(for loop)
		 //in the each iteration do mod operation
		 
		for(int i=0;i<m-1;i++)
		{
			h=(h*d)%q;
		}
	
		p=PreProcess( P, d,q);
		t[0]=0;
		for(int i=0;i<m;i++)
		{
			count++;
			asc1=(int(T[i]))%d;
		
			t[0] = ((d*t[0]) + asc1) % q;
		}
		for(int s=0;s<=(n-m);s++)
		{  
			count++;
			if(p==t[s])
			{  found=0;
				for(int j=0;j<m;j++)
				{
					count++;
					//s1=T.substr(s,m);
					if(T[s+j]!=P[j])
					{
						found=1;
						break;
					}
				}
				if(found==0)
				{
					cout<<"Pattern occurs with shift "<<s<<endl;
				}
			}
			if(s < n-m)
			{
				asc1=(int(T[s]))%d;
				asc2=(int(T[s+m]))%d;
				//cout<<asc1<<" "<<asc2<<" \n";
				temp=(d*(t[s]-(asc1*h)) + asc2);
				if(temp < 0)
				{
					temp=(-1)*temp;
					t[s+1]= temp % q;
					t[s+1]=q-t[s+1];
				}
				else
				{
					t[s+1]= temp % q;
				}
			}
		}
	}

};
int main() {
	string_matching obj;
	int count;
    int base=256;
    int q=4999;
cout<<"RABIN_KARP_MATCHER.........\n";
	string T1="ABABCABABACABABCCABABCABAB";
	string T2="ABABABCABABCABABCCABABABCABABABB";
	string T3="AABABCABCABABCABACABABCABABCABAC";
	string P1="ABABCABAB";
	count=0;

	
	obj.RABIN_KARP_MATCHER( T1, P1,base,q,count);
	cout<<"For T1 pattern P1 no.of comparison for RobinKarp : "<<count<<"\n\n";
	count=0;
	obj.RABIN_KARP_MATCHER( T2, P1,base,q,count);
	cout<<"For T2 pattern P1 no.of comparison for  RobinKarp  : "<<count<<"\n\n";
	count=0;
    obj.RABIN_KARP_MATCHER( T3, P1,base,q,count);
	cout<<"For T3 pattern P1 no.of comparison for  RobinKarp  : "<<count<<"\n\n";
	count=0;

	string T4="GTGTXCGGGTXCGTXCGGGTXCGTXCGTCG";
	string T5="GTXCGGGTXCGTXCGGGGTXCGGGTXCGTXC";
	string T6="GGGTXCGGGTXCGTXCGGGTXCGGTXCGGGTXCGTXC";
	string P2="GTXCGGGTXCGTXC";

	obj.RABIN_KARP_MATCHER( T4, P2,base,q,count);
	cout<<"For Text T4 pattern P2 no.of comparison for  RobinKarp   : "<<count<<"\n\n";
	count=0;
	obj.RABIN_KARP_MATCHER( T5, P2,base,q,count);
	cout<<"For Text T5 pattern P2 no.of comparison for  RobinKarp  : "<<count<<"\n\n";
	count=0;
	obj.RABIN_KARP_MATCHER( T6, P2,base,q,count);
	cout<<"For Text T6 Pattern p2 no.of comparison for  RobinKarp  : "<<count<<"\n\n";

	string T="ABAABAABAABAABAA";
	string P="AA";
	count=0;
	obj.RABIN_KARP_MATCHER( T, P,base,q,count);
	cout<<"For Text T Pattern p no.of comparison for  RobinKarp  : "<<count<<endl;

}
