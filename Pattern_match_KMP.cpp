#include<iostream>
#include<math.h>
using namespace std;
class string_matching {
	public:
	int* compute_prefix_function(string P)
	{
		int m = P.length();
		int *pie=new int [m];
		pie[0] = 0;
		int k=0;
		int count=0;
		for(int q=0;q<m-1;q++)
		{
			count++;
			while(k>0 && P[k] != P[q+1] )
			{
				k=pie[k];
				count++;
			}
			if( P[k] == P[q+1] )
		 		k=k+1;
			
			pie[q+1]=k;
			
		}
		 
		for(int i=0;i<m;i++)
		cout<<pie[i]<<" ";
		cout<<endl;
		cout<<"Preprocessing:pie table creation:count="<<count<<endl; 

		return pie;
	}
	void KMP_MATCHER(string T,string P,int *pie,int &count)
	{
		int m,n;
		n=T.length();
		m=P.length();
		
		int q=0;
		for(int i=0; i<n; i++)
		{
			count++;
			while (q > 0 && P[q] != T[i] )
			{
			  q = pie[q-1];
			  
			   count++;
	     	}
			if(P[q] == T[i])
			{
			
				q = q+1;	
				if( q == m )
				{
				cout<<"Pattern occurs with shift "<< i - (m-1)<<endl;
				q= pie[q-1];
				
			    }
		    }
		}
	}
};
int main() {
	string_matching obj;
	int count;
   
cout<<"KMP.........\n";
	string T1="ABABCABABACABABCCABABCABAB";
	string T2="ABABABCABABCABABCCABABABCABABABB";
	string T3="AABABCABCABABCABACABABCABABCABAC";
	string P1="ABABCABAB";
	int* pie=obj.compute_prefix_function(P1);
	count=0;

	
	obj.KMP_MATCHER( T1, P1,pie,count);
	cout<<"For T1 pattern P1 no.of comparison for KMP : "<<count<<"\n\n";
	count=0;
	obj.KMP_MATCHER( T2, P1,pie,count);
	cout<<"For T2 pattern P1 no.of comparison for  KMP : "<<count<<"\n\n";
	count=0;
    obj.KMP_MATCHER( T3, P1,pie,count);
	cout<<"For T3 pattern P1 no.of comparison for  KMP : "<<count<<"\n\n";
	count=0;

	string T4="GTGTXCGGGTXCGTXCGGGTXCGTXCGTCG";
	string T5="GTXCGGGTXCGTXCGGGGTXCGGGTXCGTXC";
	string T6="GGGTXCGGGTXCGTXCGGGTXCGGTXCGGGTXCGTXC";
	string P2="GTXCGGGTXCGTXC";
     pie=obj.compute_prefix_function(P2);
	obj.KMP_MATCHER( T4, P2,pie,count);
	cout<<"For Text T4 pattern P2 no.of comparison for  KMP   : "<<count<<"\n\n";
	count=0;
	obj.KMP_MATCHER( T5, P2,pie,count);
	cout<<"For Text T5 pattern P2 no.of comparison for  KMP  : "<<count<<"\n\n";
	count=0;
	obj.KMP_MATCHER( T6, P2,pie,count);
	cout<<"For Text T6 Pattern p2 no.of comparison for  KMP  : "<<count<<"\n\n";

	

}

