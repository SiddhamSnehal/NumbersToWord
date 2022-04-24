#include<iostream>
using namespace std;

string A[] = { "Zero","One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine"};
string B[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Forteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
string C[] = {" "," ","Twenty","Thirty","Forty","Fifty", "Sixty","Seventy","Eighty","Ninety" };
string D[] = {" ","Hundred", "Thousand","Million","Billion","Trillion","Quadrillion","Quintillion","Sextillion","Septillion","Octillion","Nonillion","Decillion","Undecillion","Duodecillion","Tredecillion","Quattuordecillion","Quindecillion","Sexdecillion","Septendecillion","Octodecillion","Novemdecillion" };

void no_to_words(int* triples)
{
	int i;
	if(triples[0]==0 && triples[1]==0 && triples[2]==0){}
	else if(triples[0]==0 && triples[1]==0 && triples[2]!=0)
	{
		cout<<A[triples[2]]<<" ";
	}
	else if(triples[0]==0 && triples[1]!=0 && triples[2]==0)
	{
		if(triples[1]==1)
		{
			cout<<B[triples[2]]<<" ";	
		}
		cout<<C[triples[1]]<<" ";
	}
	else if(triples[0]==0 && triples[1]!=0 && triples[2]!=0)
	{
		if(triples[1]==1)
		{
			cout<<B[triples[2]]<<" ";	
		}
		else
		{
			cout<<C[triples[1]]<<" ";
			cout<<A[triples[2]]<<" ";
		}
	}
	else if(triples[0]!=0 && triples[1]==0 && triples[2]==0)
	{
		cout<<A[triples[0]]<<" ";
		cout<<D[1]<<" ";
	}
	else if(triples[0]!=0 && triples[1]==0 && triples[2]!=0)
	{
		cout<<A[triples[0]]<<" ";
		cout<<D[1]<<" ";
		cout<<A[triples[2]]<<" ";
	}
	else if(triples[0]!=0 && triples[1]!=0 && triples[2]==0)
	{
		cout<<A[triples[0]]<<" ";
		cout<<D[1]<<" ";
		if(triples[1]==1)
		{
			cout<<B[triples[2]]<<" ";
		}
		cout<<C[triples[1]]<<" ";
	}
	else
	{
		cout<<A[triples[0]]<<" ";
		cout<<D[1]<<" ";
		if(triples[1]==1)
		{
			cout<<B[triples[1]]<<" ";
		}
		else
		{
			cout<<C[triples[1]]<<" ";
			cout<<A[triples[2]]<<" ";
		}
	}
}
void form_triplet(string str,int n)
{
    int i,j,m;
    int triples[3];
    if(n%3==1)
    {
    	int count=(n+2)/3;
    	triples[0]=0;
        triples[1]=0;
        triples[2]=str[0]-48;
        no_to_words(triples);
        if(count>=2)
        {
        	cout<<D[count]<<" ";
        	count--;
        }
        
        for(i=1;i<n;i=i+3)
        {
            int k=0;
            for(j=i;j<=i+2;j++)
            {
                triples[k]=str[j]-48;
                k++;
            }
        	no_to_words(triples);
        	if(count>=2)
        	{
        		cout<<D[count]<<" ";
        		count--;
        	}
        }
    }
    else if(n%3==2)
    {
    	int count=(n+1)/3;
    	triples[0]=0;
        triples[1]=str[0]-48;
        triples[2]=str[1]-48;
        no_to_words(triples);
        if(count>=2)
        {
        	cout<<D[count]<<" ";
        	count--;
        }
        for(i=2;i<n;i=i+3)
        {
            int k=0;
            for(j=i;j<=i+2;j++)
            {
                triples[k]=str[j]-48;
                k++; 
            }
        	no_to_words(triples);
        	if(count>=2)
        	{
        		cout<<D[count]<<" ";
        		count--;
        	}
        }
    }
    else
    {   
    	int count=n/3;
    	for(i=0;i<n;i=i+3)
    	{
        	int k=0;
        	for(j=i;j<=i+2;j++)
        	{
            	triples[k]=str[j]-48;
            	k++;
        	}
        	no_to_words(triples);
        	if(count>=2)
        	{
        		cout<<D[count]<<" ";
        		count--;
        	}
        }
    }
}
int main()
{
	string str;
	cout<<"Enter a number:"<<endl;
	getline(cin,str);
	int n=str.length();
	form_triplet(str,n);
	return 0;
}
