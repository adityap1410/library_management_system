#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;



class student{
    public:
    struct student1{
        string name;
        string dept;
        int uid;

    };
    //int student[1000];
    vector<student1> students;
    void adduser(int uid, string n, string dep){
        student1 x;
        x.uid=uid;
        x.name=n;
        x.dept=dep;
        students.push_back(x);
    }
    void getUserDetails(int uid_fetched){
        for(auto student1: students){
            if(student1.uid==uid_fetched){
            cout<<"student name is"<<student1.name<<"\n";
            cout<<student1.dept<<" is his dept \n";}
        }

    }
};
    class book{
        public:
        struct book1{
            long long int isbn;
            string bookn;
            string booka;
        };
        vector<book1> books;
        void addbook(long long int isbn, string name, string auth){
            book1 x;
            x.isbn=isbn;
            x.bookn=name;
            x.booka=auth;
            books.push_back(x);
        }
        void getBookDetails(long long int isbn_to_be_fetched){
            for(auto book1: books){
                if(book1.isbn==isbn_to_be_fetched){
                    cout<<book1.bookn<<" is the name of book"<<"\n";
                    cout<<book1.booka<<" is the book author"<<"\n";

                }
        }
    }
};


class library{
    public:
    unordered_map<int, vector<long long int>> mp2;
   
    void assignBook(int uid, long long int isbn){
        //mp.insert({uid,isbn});
        mp2[uid].push_back(isbn);
    }
    void returnedBook(int uid, long long int isbn){
      // for(auto it: mp.find(uid)){
       auto i=mp2.find(uid);
           if(i!=mp2.end()){
               //vector<long> temp;
              auto temp=i->second;
               //long long int
               auto ans=find(temp.begin(),temp.end(), isbn);
               if(ans!=temp.end()){
                   temp.erase(ans);
                   cout<<"book returned";
               }
               else
               cout<<"book is not alloted to given user";
           }
           else{
               cout<<"user not found";
           }
           
       
   }
   
    
    void getmappingdetails(int uid){
        if(mp2.find(uid)!=mp2.end()){
        cout<<"Student with the following uid has been assigned \n";
        for(auto isbn: mp2[uid]){
            cout<<isbn<<"\n";
        }
    }
    else{
        cout<<"user currently has no books assigned \n";
    }
    }
};

int main(){
    
    
    student student1;
    book book1;
    library library1;

    student1.adduser(1, "Aditya", "ece");
    student1.adduser(2, "Adwait", "civil");

    book1.addbook(23457689043453, "cpp book", "cpp author");
    book1.addbook(1232456778565, "python book", "python author");
    book1.addbook(123456789, "java book", "java author");

    library1.assignBook(1, 23457689043453);
    library1.assignBook(2, 1232456778565);
    library1.assignBook(1, 123456789);
    library1.assignBook(1, 1232456778565);

   int x;
    cout<<"enter uid of user, who's details is to be fetched \n";
    cin>>x;
    

   
    student1.getUserDetails(x);

    long long int y;
    cout<<"enter isbn, who's book details is to be fetched \n";
   cin>>y;
    
    book1.getBookDetails(y);

   int z;
   cout<<"get isbn of book, the student with given uid has \n";
   cin>>z;
    
    library1.getmappingdetails(z);
    
    
    
    
    
    
     int a;
    long long int isbn_delete;
    
    cout << "Enter UID and ISBN of the book to be returned:\n";
    cin >> a >> isbn_delete;
   library1.returnedBook(a, isbn_delete);

    return 0;
}
