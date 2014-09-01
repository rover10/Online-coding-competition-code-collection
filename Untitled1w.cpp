#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	
	stack<string> opStack;
	stack<string>operStack;
	string str;
	getline(cin,str);
	
	int i=0,j=0,k=0;
	int strlen;
	strlen=str.length();
	while(k<strlen){
		if(str[k]==' ' || str[k]=='(' ||str[k]==')'){
			string temp=str.substr(i,k);
			cout<<temp<<" "<<endl;
				if(temp.length()!=0){
					if(str[k]==')'){
						int val;
						string opd1,opd2,opt;
						
						if( !operStack.empty() && !opStack.empty()){
							opd2=str.substr(i,k-i);
							opd1=operStack.top();
							operStack.pop();
							opt=opStack.top();
							opStack.pop();
							if(opt.compare("OR")){
									if(opd2.compare("FALSE")==0 && opd1.compare("FALSE")==0 )
											opStack.push("FALSE");
										else
											opStack.push("TRUE");
							}else{
									if(opd2.compare("TRUE")==0 && opd1.compare("TRUE")==0 )
											opStack.push("TRUE");
										else
											opStack.push("FALSE");
								}
						}else{
							cout<<"Invalid Expression!"<<endl;
							//break;
							return 0;						
						}
						i=k;
					}
					else if( temp.compare("AND")==0 || temp.compare("OR")==0){
						if( (temp).compare("AND")==0 )
									opStack.push(("AND"));
							else if( (temp).compare("OR")==0 )
									opStack.push(("OR"));
							else{
									cout<<"Invalid Expression!"<<endl;
									//break;
									return 0;
								}
							i=k;						
						}
					else if((temp).compare("TRUE")==0 || (temp).compare("FALSE")==0){
						if((temp).compare("TRUE")==0)
								 operStack.push("TRUE");	
						else if ((temp).compare("FALSE")==0)
								 operStack.push("FALSE");
						else{
								cout<<"Invalid Expression!"<<endl;
								//break;
								return 0;
							}
					
					/////////
							int val;
						string opd1,opd2,opt;
						
						if( !operStack.empty() && !opStack.empty()){
							opd2=str.substr(i,k-i);
							opd1=operStack.top();
							operStack.pop();
							opt=opStack.top();
							opStack.pop();
							if(opt.compare("OR")){
									if(opd2.compare("FALSE")==0 && opd1.compare("FALSE")==0 )
											opStack.push("FALSE");
										else
											opStack.push("TRUE");
							}else{
									if(opd2.compare("TRUE")==0 && opd1.compare("TRUE")==0 )
											opStack.push("TRUE");
										else
											opStack.push("FALSE");
								}
						}else{
							cout<<"Invalid Expression!"<<endl;
							//break;
							return 0;						
						}
						i=k;
				
					
					////////////
					
					
					
							
					} 		
		
				}
			i=k+1;					
		}
			
			k++;
	}
	cout<<"Here";
	if(!opStack.empty())
		cout<<opStack.top();
}
