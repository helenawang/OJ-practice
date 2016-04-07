#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

map<string, string> names;

int n, m;
string lines[105];

int main()
{
	freopen("201509-3.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	getline(cin, lines[0]);
	for(int i=0; i<n; i++){
		getline(cin, lines[i]);
		//cout<<lines[i]<<endl;
	}
	for(int i=0; i<m; i++){
		string name, value;
		cin>>name;
		getchar();
		getline(cin, value);
		int pos = value.find('\"',0);
		value = value.erase(pos, 1);
		
		pos = value.find('\"',0);
		value = value.erase(pos, 1);
		
		names.insert(pair<string, string>(name, value));
		//cout<<name<<value<<endl;
	}
	for(int i=0; i<n; i++){
		int s, e;
		int cur = 0;
		s = lines[i].find("{{ ", cur);
		e = lines[i].find(" }}", cur);
		while(s!=-1 && e!=-1){
			string name;
			name = lines[i].substr(s+3, e-s-3);
			//cout<<name<<endl;
			map<string, string>::iterator iter;
			iter = names.find(name);
			if(iter == names.end()){
				lines[i].replace(s, e-s+3, " ");
				cur = s+1;
			}
			else{
				lines[i].replace(s, e-s+3, iter->second);
					
				cur = s+(iter->second).length();
			}
			s = lines[i].find("{{ ", cur);
			e = lines[i].find(" }}", cur);	
		}
		cout<<lines[i]<<endl;
	}
	return 0;
}
