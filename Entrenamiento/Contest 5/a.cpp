// Uso de sets para todas las posibilidades a partir de un estado
# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
int saque(int puntos)
{
	puntos--;
	puntos /= 2;
	if(puntos % 2 == 0) return 1;
	return 2;
}
 
int main()
{
    //freopen("prueba.txt", "r", stdin);
	int n;
	cin>>n;
	
	char c;
	
	vector<pair<int, int> > puntos(n+1);
	puntos.push_back(make_pair(0,0));
	for(int i=1;i<n+1;i++)
	{
		cin>>puntos[i].first>>c>>puntos[i].second;
		//cout << puntos[i].first << " " << puntos[i].second << endl;
	}
	
	bool res = true;
	
	for(int i=0;i<n;i++)
	{
		set<pair<int, int> > s;
		int saque_actual=saque(puntos[i].first + puntos[i].second);
		
		if(puntos[i].first == 11 || puntos[i].second == 11)
		{
			s.insert(puntos[i]);
		}
		else
		{
			for(int a=puntos[i].first;a<=11;a++)
			{
				for(int b = puntos[i].second;b<=11;b++)
				{
					if(a==11 && b==11) continue;
					if(saque(a+b) == saque_actual) s.insert(make_pair(a,b));
					else s.insert(make_pair(b,a));
				}
			}
		}
		
		pair<int, int> next = puntos[i+1];
		if(s.find(next) == s.end())
		{
			cout << "error " << i+1 << endl;
			return 0;
		}
		
		//set<pair<int, int> > :: iterator it;
		//for(it = s.begin();it!=s.end();it++) cout << (*it).first << " " << (*it).second << endl;
	}
	
	cout << "ok" << endl;
	
    return 0;
}