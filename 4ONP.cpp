#include<iostream>
#include<stack>
using namespace std;
int main(){
	int T;
	char inp[401];
	char oup[401];
	stack <char> Stack;
	cin>>T;
	int i,j;
	char ch;
	while(T>0){
		cin>>inp;
		i=0;
		j=0;
		while(inp[i]!='\0'){
			if(inp[i]=='('){
				Stack.push(inp[i]);
			}
			else if(inp[i]>=97 && inp[i]<=122){
				oup[j++]=inp[i];
			}
			else if(inp[i]==')'){
				while(1){
					ch=Stack.top();
					Stack.pop();
					if(ch!='('){
						oup[j++]=ch;
					}
					else{
						break;
					}
				}
			}
			else{
				Stack.push(inp[i]);
			}
			i++;
		}
		oup[j]='\0';
		cout<<oup<<endl;
		T--;
	}
	return 0;
} 
