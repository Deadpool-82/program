#include<iostream>
#include<cstdlib>
using namespace std;

class node{
	public:
		string s;
		bool isEmpty;
		node(){
			s="";
			isEmpty=true;
		}
};
class hashtable{
	private:
		node *arr;
	public:
	hashtable(){
		arr=new node[52];	
	}
	int hashFn(string str){
		if(isupper(str[0]))
			return str[0]-'A';
		if(islower(str[0]))
			return str[0]-'a'+26;	
	}
	bool insert(string s){
		int index=hashFn(s);
		if(arr[index].isEmpty){
			arr[index].s=s;
			arr[index].isEmpty=false;
			cout<<"\n"<<s<<" inserted in pos"<<index<<endl;
			return true;
		}
		else{
			if(arr[index].s==s)
				return false;
			for(int i=(index+1);i!=index;i=(i+1)%52){
				if(arr[i].s==s)
					return false;
				if(arr[i].isEmpty){
					arr[i].s=s;
					arr[i].isEmpty=false;
					cout<<"\n"<<s<<" inserted in pos"<<i<<endl;
					return true;
				}	
			}	
		}
		return false;
	}
	bool find(string s){
		int index=hashFn(s);
		if(arr[index].s==s)
			return true;
		else{
			for(int i=index+1;i!=index&&!arr[i].isEmpty;i=(i+1)%52){
				if(arr[i].s==s)
					return true;
			}
		}
		return false;	
	}
};
int main(){
	hashtable h;
	string x;
	int n;
	//inserting strings in hash table
	cout<<"Enter the number of words to be inserted: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"\nEnter the word to insert: ";
		cin>>x;
		h.insert(x);
	}
	//searching strings in hash table
	cout<<"\nEnter the number of words to be searched: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"\nEnter the word to search: ";
		cin>>x;
		if(h.find(x))
			cout<<"Found";
		else
			cout<<"Unavailable";	
	}
}
