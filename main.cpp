#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int st = 10;

void zmiana(double *t, char *cht, int x)
{
    for (int i=x; i<(st-1) ; i++ )
    {
        if (i<st-2) t[i+1]=t[i+2];
        cht[i]=cht[i+1];
    }
}

int main() {

	string wyr;
	cout << "Wpisz wyrazenie, ktora ma zostac obliczone: " << endl;
	cin  >> wyr;

    double tab[st]={};
    char chtab[st]={};
    int j = 0;
    string zm;
	for (int i=0; i<=wyr.length(); i++)
	{
	    //if (wyr[i]!='*' && wyr[i]!='/' && wyr[i]!='+' && wyr[i]!='-' && wyr[i]!=0)
	    if (wyr[i]>='0' && wyr[i]<='9' && wyr[i]!=0)
	    {
	        zm += wyr[i];
	    }
	    else if (wyr[i]=='*' || wyr[i]=='/' || wyr[i]=='+' || wyr[i]=='-' || wyr[i]==0)
        {
	        for (int k=0; k<zm.length();k++ )
	        {
	           double tmp = (zm[k]-'0')*(pow(10,zm.length()-k))/10;
	           tab[j] +=  tmp;
	        }

            chtab[j]=wyr[i];
            j++;

	        zm.clear();
	    }
	}

	for (int i=0; chtab[i]!=0; i++)
    {
        if (chtab[i]=='*')
            {
                tab[i]=tab[i]*tab[i+1];
                zmiana(tab, chtab, i);
                i--;
            }
        else if (chtab[i]=='/')
            {
                tab[i]=tab[i]/tab[i+1];
                zmiana(tab,chtab, i);
                i--;
            }
    }

    for (int i=0; chtab[i]!=0; i++)
    {
        if (chtab[i]=='+')
            {
                tab[i]=tab[i]+tab[i+1];
                zmiana(tab, chtab, i);
                i--;
            }
        else if (chtab[i]=='-')
            {
                tab[i]=tab[i]-tab[i+1];
                zmiana(tab, chtab, i);
                i--;
            }
    }

    cout << "Wynik wyr. " << wyr << " to: "<< tab[0] << endl;

	return 0;
}
