#include <iostream>
#include <string>

using namespace std;

int decrypt(){
	int key;
	cout<<"Enter the key\n";
	scanf("%d",&key);
	if((key<0 || key%26==0)){
		cout<<"Wrong key value!\n";
		return 1;
	}

	string input;
	cout<<"Enter the cipher text\n";
	
	cin.ignore();
	getline(cin,input);
	//cout<<input<<endl;
	//int len=sizeof(input)/sizeof(char);
	int len=input.length();
	//int len=6;

	key=key%26;

	for(int i=0;i<len;i++){

		int temp=(int)input[i];
		if((temp>64 && temp<=90)  ){
			temp-=key;
			if(temp<65){
				temp=91-(65-temp);
			}
			
		}
		if((temp>96 && temp<=122)){
			temp-=key;
			if(temp<97){
				temp=123-(97-temp);
			}

		}
		input[i]=(char)temp;
	}
	cout<<input<<endl;
	//free (input);
	cout<<"voila\n";
	return 1;
}


int encrypt(){

	int key;
	cout<<"Enter the key\n";
	cin>>key;
	if((key<0 || key%26==0)){
		cout<<"Wrong key value!\n";
		return 1;
	}

	string input;
	cout<<"Enter the clear text\n";
	
	cin.ignore();
	getline(cin,input);
	//cout<<input<<endl;
	//int len=sizeof(input)/sizeof(char);
	int len=input.length();
	//int len=6;

	key=key%26;

	for(int i=0;i<len;i++){

		int temp=(int)input[i];
		
		if( (temp>96 && temp<=122)){
			
			temp+=key;
			if(temp>122){
				
				temp=96-(122-temp);
			}
		}

		if((temp>64 && temp<=90)){
			temp+=key;
			if(temp>90){
			temp=64-(90-temp);
			}
		}
		
		input[i]=(char)temp;
	}
	cout<<input<<endl;
	//free (input);
	cout<<"voila\n";
	return 0;

}


int main(){
	int flag=1;
	while(flag)
		{
			cout<<"Hello!\nThis is a simple ceser cipher encryptor/decryptor!\nPress 1 to encrypt\nPress 2 to decyypt\nPress 0 to exit\n";
			int choice;
			//cin>>choice;
			int val=1;
			//int key;
			cin>>choice;
			if(choice == 1)
				 val = encrypt();
			if(choice == 2){
				val = decrypt();
				val=0;
			}
			if(choice == 0)
				return 0;
			if(val==1)
				cout<<"Wrong input\nTry again\n";

		}
}